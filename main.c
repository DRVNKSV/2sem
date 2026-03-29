#include <stdio.h>
#include <assert.h>
#include "mem.h"
#include "command.h"
#include "run.h"
#include "test_mem.h"
int main(int argc, char *argv)
{
    load_data();
    mem_dump(0x40, 20);
    printf("\n");
    mem_dump(0x200, 0x26);
    return 0;
}
