#include <stdio.h>
#include "mem.h"
void test_mem(address a, word wexp, byte b1exp, byte b0exp)
{
    address a;
    byte b0, b1, bres;
    word w, wres;
    fprintf(stderr, "write and read a byte on even-numbered address\n");
    a = 0;
    b0 = 0x12;
    b_write(a, b0);
    bres = b_read(a);
    fprintf(stderr, "a=%06o b0=%hhx bres=%hhx\n", a, b0, bres);
    assert(b0 == bres);
    a = 3;
    b0 = 0x34;
    b_write(a, b0);
    bres = b_read(a);
    fprintf(stderr, "a=%06o b0=%hhx bres=%hhx\n", a, b0, bres);
    a = 4;
    b0 = 0x21;
    b_write(a, b0);
    bres = b_read(a);
    fprintf(stderr, "a=%06o b0=%hhx bres=%hhx\n", a, b0, bres);

    fprintf(stderr, "write and read word\n");
    a = 4;
    w = 0x3456;
    w_write(a, w);
    wres = w_read(a);
    fprintf(stderr, "a=%06o w=%04x wres=%04x\n", a, w, wres);
    assert(w == wres);
    a = 6;
    w = 0x3768;
    w_write(a, w);
    wres = w_read(a);
    fprintf(stderr, "a=%06o w=%04x wres=%04x\n", a, w, wres);
    assert(w == wres);
    a = 7;
    w = 0x3768;
    w_write(a, w);
    wres = w_read(a);
    fprintf(stderr, "a=%06o w=%04x wres=%04x\n", a, w, wres);
    assert(w == wres);


    fprintf(stderr, "write 2 byte, read word\n");
    a = 4;
    w = 0xa1b2;
    b0 = 0xb2;
    b1 = 0xa1;
    b_write(a, b0);
    b_write(a+1, b1);
    wres = w_read(a);
    fprintf(stderr, "a=%06o b1=%02hhx b0=%02hhx wres=%04x\n", a, b1, b0, wres);
    assert(w == wres);
    a = 8;
    w = 0xf852;
    b0 = 0x52;
    b1 = 0xf8;
    b_write(a, b0);
    b_write(a+1, b1);
    wres = w_read(a);
    fprintf(stderr, "a=%06o b1=%02hhx b0=%02hhx wres=%04x\n", a, b1, b0, wres);
    assert(w == wres);

     fprintf(stderr, "write word, read 2 byte\n");
    a = 4;        // другой адрес
    w = 0xa1b2;
    // little-endian, младшие разряды по меньшему адресу
    w_write(a, w);
    byte bres1 = b_read(a);
    byte bres2 = b_read(a+1);
    // тут полезно написать отладочную печать a, w, wres
    fprintf(stderr, "a=%06o W=%02hhx bres1=%02hhx bres2=%04x\n", a, w, bres1, bres2);
  

}