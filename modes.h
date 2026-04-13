#ifndef MODES_H
#define MODES_H

#include <stdio.h>
#include "mem.h"

#define HAS_SS (1<<0) // 1
#define HAS_DD (1<<1)  // 2
#define HAS_XX (1<<2)   // 4
#define HAS_NN (1<<3)   // 8
#define HAS_R (1<<4)    // 16

typedef struct {
    word val;  
    address adr;
} Arg;

Arg get_mr(word w);

#endif