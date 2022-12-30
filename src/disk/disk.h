#ifndef DISK_H
#define DISK_H

typedef unsigned int OCTOS_DISK_TYPE;

//Represent a read physical hard disk
#define OCTOS_DISK_TYPE_REAL 0

struct disk {
	OCTOS_DISK_TYPE type;
	int sector_size;
	int id;
	struct filesystem *filesystem;

	//Private data of out filesystem
	void *fs_private;
};

void disk_search_and_init();
struct disk *disk_get(int index);
int disk_read_block(struct disk *idisk, unsigned int lba, int total, void *buf);
#endif