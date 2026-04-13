#include <stdio.h>
#include <stdlib.h>

#include "mem.h"
#include "modes.h"

typedef struct {
    word mask;
    word opcode;
    char * name;
    void (*do_command)(void);
    word need_args;
} Command;

Arg ss;
Arg dd;

void do_halt();
void do_move();
void do_add();
void do_nothing();
void do_sob();
void do_inc();

void do_halt(){
    printf("\nTHE END\n");
    printf("r0: %o, r1: %o, r2: %o, r3: %o,r4: %o, r5: %o, r6: %o, r7: %o", reg[0], reg[1], reg[2], reg[3], reg[4], reg[5], reg[6], reg[7]);
    exit(0);
}
void do_move(){
    w_write(dd.adr, ss.val);
    printf("%o - dd adr, %o - ss val", dd.adr, ss.val);
}
void do_add(){
    w_write(dd.adr, ss.val + dd.val);
}
void do_nothing(){}
void do_sob(){}
void do_inc(){}

Command cmd[] = {
    {0170000, 0060000, "add", do_add, HAS_SS + HAS_DD},
    {0170000, 0010000, "mov", do_move, HAS_SS + HAS_DD},
    {0177777, 0000000, "halt", do_halt, 0},
    {0177700, 0005200, "inc", do_inc, HAS_DD},
    {0177000, 0077000, "sob", do_sob, HAS_R + HAS_DD},
    {0000000, 0000000, "unknown", do_nothing, 0},
};

