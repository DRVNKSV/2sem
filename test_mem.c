#include <stdio.h>
#include "mem.h"
void test_mem1(address a, word wexp, byte b1exp, byte b0exp)
{
    assert((a & 1) == 0);

    byte b0res, b1res;
    word wres;
    //fprintf(stderr, "write and read a byte on even-numbered address\n");

    b_write(a, b0exp);
    b0res = b_read(a);
    //fprintf(stderr, "a=%06o b0=%hhx bres=%hhx\n", a, b0exp, b0res);
    assert(b0exp == b0res);
 
    a++ ;
 
    b_write(a, b1exp);
    b1res = b_read(a);
    //fprintf(stderr, "a=%06o b1=%hhx bres=%hhx\n", a, b1exp, b1res);
    assert(b1exp == b1res);
 
    a++;

    //fprintf(stderr, "write and read word\n");
    w_write(a, wexp);
    wres = w_read(a);
    //fprintf(stderr, "a=%06o w=%04x wres=%04x\n", a, wexp, wres);
    assert(wexp == wres);
    
    a += 2;

    //fprintf(stderr, "write 2 byte, read word\n");
    b_write(a, b0exp);
    b_write(a+1, b1exp);
    wres = w_read(a);
    //fprintf(stderr, "a=%06o b1=%02hhx b0=%02hhx wres=%04x\n", a, b1exp, b0exp, wres);
    assert(wexp == wres);

    a += 2;

    //fprintf(stderr, "write word, read 2 byte\n");
    // little-endian, младшие разряды по меньшему адресу
    w_write(a, wexp);
    byte bres0 = b_read(a);
    byte bres1 = b_read(a+1);
    // тут полезно написать отладочную печать a, w, wres
    //fprintf(stderr, "a=%06o W=%02hhx bres1=%02hhx bres2=%04x\n", a, wexp, bres1, bres0);
    assert(b0exp == bres0);
    assert(b1exp == bres1);

}
void test_mem()
{
    test_mem1(0, 0x2134, 0x21, 0x34);
    test_mem1(10, 0x0a0b, 0x0a, 0x0b);
    test_mem1(20, 0xcadb, 0xca, 0xdb);
}