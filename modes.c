#include <stdio.h>
#include <stdlib.h>
#include "mem.h"

#define HAS_SS (1<<0) // 1
#define HAS_DD (1<<1)  // 2
#define HAS_XX (1<<2)   // 4
#define HAS_NN (1<<3)   // 8
#define HAS_R (1<<4)    // 16


typedef struct {
    word val;  
    address adr;
} Arg;

Arg get_mr(word w)
{
    Arg res;
    int r = w & 7;
    int m = (w >> 3) & 7;
    switch (m) {
    // мода 0, R1
    case 0:
        res.adr = r;        // адрес - номер регистра
        res.val = reg[r];   // значение - число в регистре
        printf("R%d ", r);
        break;


    // мода 1, (R1)
    case 1:
        res.adr = reg[r];           // в регистре адрес
        res.val = w_read(res.adr);  // по адресу - значение
        printf("(R%d) ", r);
        break;


    // мода 2, (R1)+ или #3
    case 2:
        res.adr = reg[r];           // в регистре адрес
        res.val = w_read(res.adr);  // по адресу - значение
        reg[r] += 2;                // TODO: +1
        // печать разной мнемоники для PC и других регистров
        if (r == 7)
            printf("#%o ", res.val);
        else
            printf("(R%d)+ ", r);
        break;


    // мы еще не дописали другие моды
    default:
        printf("Mode %d not implemented yet!\n", m);
        exit(1);
    }

    return res;
}
