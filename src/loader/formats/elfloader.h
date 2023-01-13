#ifndef ELFLOADER_H
#define ELFLOADER_H

#include <stdint.h>
#include <stddef.h>

#include "elf.h"
#include "config.h"

struct elf_file {
	char filename[OCTOS_MAX_PATH];

	int in_memory_size;

	//The physical memory address that elf file is loaded
	void *elf_memory;
	//The virtual base address of this binary
	void *virtual_base_address;
	//ending virtual address
	void *virtual_end_address;
	//the physical base address
	void *physical_base_address;
	//the pysical end address
	void *physical_end_address;
};

#endif