#include <stdio.h>
#include "mem.h"
typedef struct {
    word mask;
    word opcode;
    char * name;
    void (*do_command)(void);
} Command;
void do_halt();
void do_move();
void do_nothing();
void do_sob();
void do_add();
void do_inc();
Command cmd[] = {
    {0170000, 0060000, "add", do_add},
    {0170000, 0010000, "mov", do_move},
    {0170000, 0000000, "halt", do_halt},
    {0170000, 0005200, "inc", do_inc},
    {0170000, 0077000, "sob", do_sob},
    {0000000, 000000, "unknown", do_nothing},

};
void do_halt(){
    trace("THE END");
    exit(0);
}
void do_move(){

}
void do_nothing(){

}
