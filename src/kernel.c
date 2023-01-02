#include "kernel.h"
#include <stdint.h>
#include <stddef.h>
#include "idt/idt.h"
#include "io/io.h"
#include "memory/heap/kheap.h"
#include "memory/paging/paging.h"
#include "disk/disk.h"
#include "fs/pparser.h"
#include "string/string.h"
#include "disk/streamer.h"
#include "fs/file.h"
#include "gdt/gdt.h"
#include "config.h"
#include "memory/memory.h"
#include "task/tss.h"

uint16_t *video_mem = 0;
uint16_t terminal_row = 0;
uint16_t terminal_col = 0;

uint16_t terminal_make_char(char c, char color)
{
	return (color << 8) | c;
}

void terminal_putchar(int x, int y, char c, char color)
{
	video_mem[(y * VGA_WIDTH) + x] = terminal_make_char(c, color);
}
void terminal_writechar(char c, char color)
{
	if (c == '\n') {
		terminal_row += 1;
		terminal_col = 0;
		return;
	}
	terminal_putchar(terminal_col, terminal_row, c, color);
	terminal_col += 1;
	if (terminal_col >= VGA_WIDTH) {
		terminal_col = 0;
		terminal_row += 1;
	}
}

void terminal_init()
{
	video_mem = (uint16_t *)(0xB8000);
	for (int y = 0; y < VGA_HEIGHT; y++) {
		for (int x = 0; x < VGA_WIDTH; x++) {
			terminal_putchar(x, y, ' ', 0);
		}
	}
}

void print(const char *str)
{
	size_t len = strlen(str);
	for (int i = 0; i < len; i++) {
		terminal_writechar(str[i], 15);
	}
}

static struct paging_4gb_chunk *kernel_chunk = 0;

void panic(const char *msg)
{
	print(msg);
	while (1) {
	}
}
struct tss tss;
struct gdt gdt_real[OCTOS_TOTAL_GDT_SEGMENTS];
struct gdt_structured gdt_structured[OCTOS_TOTAL_GDT_SEGMENTS] = {
	{ .base = 0x00, .limit = 0x00, .type = 0x00 }, //NULL SEGMENT
	{ .base = 0x00, .limit = 0xffffffff, .type = 0x9A }, //KERNEL CodeSeg
	{ .base = 0x00, .limit = 0xffffffff, .type = 0x92 }, //KERNEL DataSeg
	{ .base = 0x00, .limit = 0xffffffff, .type = 0xF8 }, //User CodeSeg
	{ .base = 0x00, .limit = 0xffffffff, .type = 0xF2 }, // User Dataseg
	{ .base = (uint32_t)&tss, .limit = sizeof(tss), .type = 0xE9 } //TSS seg
};

void kernel_main()
{
	terminal_init();
	print("Hello People\nand computers");

	memset(gdt_real, 0x00, sizeof(gdt_real));
	gdt_structured_to_gdt(gdt_real, gdt_structured,
			      OCTOS_TOTAL_GDT_SEGMENTS);
	//Load GDT
	gdt_load(gdt_real, sizeof(gdt_real));

	//Initialize the heap
	kheap_init();

	//Init filesystems
	fs_init();

	//Search and initialize disks
	disk_search_and_init();

	//Initialize interrupt descriptor table
	idt_init();

	//Setup the TSS
	memset(&tss, 0x00, sizeof(tss));
	tss.esp = 0x600000;
	tss.ss0 = KERNEL_DATA_SELECTOR;

	//load the TSS
	tss_load(0x28);

	//Setup paging
	kernel_chunk = paging_new_4gb(PAGING_IS_WRITABLE | PAGING_IS_PRESENT |
				      PAGING_ACCESS_FROM_ALL);

	//Switch to kernel paging chunk
	paging_switch(paging_4gb_chunk_get_directory(kernel_chunk));

	//Enable Paging
	enable_paging();

	//Enable interrupts
	enable_interrupts();

	int fd = fopen("0:/test.txt", "r");
	if (fd) {
		struct file_stat s;
		fstat(fd, &s);
		fclose(fd);

		print("\nTesting\n");
	}

	while (1) {
	}
}