#include <stdio.h>
#include <assert.h>
typedef unsigned char byte;  
typedef unsigned short word;
typedef word address;
#define MEMSIZE 64*1024
static byte mem[MEMSIZE];
word reg[8];

void b_write(address adr, byte val) {
    assert(adr < MEMSIZE);
    
    mem[adr] = val;
    
}

word b_read (address adr)
{
    word w;
    byte bres;
    return mem[adr];
    /*
    
    if (adr % 2 == 0) {
        w = mem[adr];
        bres = (byte)w;
    }
    else {
        w = mem[adr - 1];
        bres = (byte)(w >> 8);
    }
    return bres;
    */
}

void w_write(address adr, word val) {
    assert(adr < MEMSIZE - 1);
    mem[adr] = val & 0xFF; 
    mem[adr + 1] = (val >> 8) & 0xFF; 
}

word w_read(address adr) {
    assert(adr < MEMSIZE - 1);
    word result = mem[adr]; 
    result |= (mem[adr + 1] << 8);
    return result;
}
void load_data() {
    address start_addr;
    int count;
    while (scanf("%hx %x", &start_addr, &count) == 2) {
        for (int i = 0; i < count; i++) {
            int byte_val;
            scanf("%x", &byte_val);
            b_write(start_addr + i, (byte)byte_val);
        }
    }
}

void mem_dump(address adr, int size) {
    for (int i = 0; i < size; i += 2) {
        word value = w_read(adr + i);
        printf("%06o: %06o %04x\n", adr + i, value, value);
    }
}

