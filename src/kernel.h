#ifndef KERNEL_H
#define KERNEL_H

#define VGA_WIDTH 80
#define VGA_HEIGHT 20

void kernel_main();
void panic(const char *msg);
void print(const char *str);
void terminal_writechar(char c, char color);
void kernel_page();
void kernel_registers();

#define ERROR(value) (void *)(value)
#define ERROR_I(value) (int)(value)
#define ISERR(value) ((int)value < 0)

#endif
