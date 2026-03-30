#include <stdio.h>
#include <stdarg.h>
#include "mem.h"
#include "command.h"

void run()
{
    pc = 01000;
    word w;
    while(1) {
        w = w_read(pc);
        printf("%06o %06o: ", pc, w);
        pc += 2;
        for (int i = 0; ; i++){
            if ((w & cmd[i].mask) == cmd[i].opcode){
                printf("%s ", cmd[i].name);
                //cmd[i].do_command();
                break;
            }
        }
    }
}