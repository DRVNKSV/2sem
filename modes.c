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
    int is_byte;
} Arg;

Arg get_mr(word w, int is_byte)
{
    Arg res;
    int r = w & 7;
    int m = (w >> 3) & 7;
    res.is_byte = is_byte;
    switch (m) {
    // мода 0, R1
    case 0:
        res.adr = r; 
        if (is_byte != 0){
            res.val = reg[r] & 0xFF;
            printf("R%d ", r);
        }
        else{       // адрес - номер регистра
        res.val = reg[r];   // значение - число в регистре
        printf("R%d ", r);
        }
        break;


    // мода 1, (R1)
    case 1:
        res.adr = reg[r];
        if (is_byte != 0){
            res.val = b_read(res.adr);
            printf("(R%d) ", r);
        }         // в регистре адрес
        
        else{
            res.val = w_read(res.adr); // по адресу - значение
        printf("(R%d) ", r);
        }
        break;


    // мода 2, (R1)+ или #3
    case 2:
        res.adr = reg[r];
        if (is_byte != 0){
            res.val = b_read(res.adr);  // по адресу - значение  
        } 
        else{          // в регистре адрес
        res.val = w_read(res.adr);
        }  // по адресу - значение
        reg[r] += (is_byte ? 1 : 2);                // TODO: +1
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

Arg get_r(word w){
    Arg res;
    int r = w & 7;
    res.adr = r;
    res.val = reg[r];
    return res;
}

Arg get_nn(word w){
    Arg res;
    int n = w & 077;
    res.val = n;
    //printf("w=%o n=%o ", w, n);
    res.val = n;
    res.adr = n;
    return res;
}
