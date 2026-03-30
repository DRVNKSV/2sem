#include <stdio.h>
#include "mem.c"
void test_mem()
{
    address a;
    byte b0, b1, bres;
    word w, wres;
    fprintf(stderr, "Пишем и читаем байт по четному адресу\n");
    a = 0;
    b0 = 0x12;
    b_write(a, b0);
    bres = b_read(a);
    fprintf(stderr, "a=%06o b0=%hhx bres=%hhx\n", a, b0, bres);
    assert(b0 == bres);
    a = 3;
    b0 = 0x21;
    bres = b_read(a);
    fprintf(stderr, "a=%06o b0=%hhx bres=%hhx\n", a, b0, bres);
    

    fprintf(stderr, "Пишем и читаем слово\n");
    a = 2;
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


    fprintf(stderr, "Пишем 2 байта, читаем слово\n");
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

}
