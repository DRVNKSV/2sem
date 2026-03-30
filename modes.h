#ifndef MODES_H
#define MODES_H

#include <stdio.h>
#include "mem.h"

typedef struct {
    word val;  
    address adr;
} Arg;

Arg get_mr(word w);

#endif