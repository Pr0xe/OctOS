#ifndef PROCESS_H
#define PROCESS_H

#include <stdint.h>
#include "config.h"
#include "task/task.h"
#include "config.h"

struct process {
	//process ID
	uint16_t id;

	char filename[OCTOS_MAX_PATH];

	//The main process task
	struct task *task;
	//The memory allocations of the process
	void *allocations[OCTOS_MAX_PROGRAM_ALLOCATIONS];

	//The physical pointer to the process memory
	void *ptr;
	//The prysical pointer to the stack memory
	void *stack;
	//the size of the data pointed to by "ptr"
	uint32_t size;
	struct keyboard_buffer {
		char buffer[OCTOS_KEYBOARD_BUFFER_SIZE];
		int tail;
		int head;
	} keyboard;
};
int process_load(const char *filename, struct process **process);
int process_load_for_slot(const char *filename, struct process **process,
			  int process_slot);
struct process *process_current();
struct process *process_get(int process_id);
#endif