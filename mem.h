#ifndef MEM_H
#define MEM_H

#include <stdio.h>
#include <assert.h>

typedef unsigned char byte;
typedef unsigned short word;
typedef word address;

#define MEMSIZE (64 * 1024)
extern word reg[8];
#define pc reg[7]

void b_write(address adr, byte val);
byte b_read(address adr);
void w_write(address adr, word val);
word w_read(address adr);
void load_data(void);
void mem_dump(address adr, int size);

#endif 