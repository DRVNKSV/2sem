#ifndef COMMAND_H
#define COMMAND_H

#include "mem.h" 
#include "modes.h"
typedef struct {
    word mask;         
    word opcode;        
    char *name;       
    void (*do_command)(void); 
} Command;

void do_halt(void);
void do_move(void);
void do_add(void);
void do_inc(void);
void do_sob(void);
void do_nothing(void);


extern Command cmd[];
extern Arg ss;
extern Arg dd;
#endif