/*
author: mark
date: 2025-02-08
description: main
*/
#include "lifo.h"
#include <stdio.h>  
#include <stdlib.h>

unsigned int buffer1[5];

void main() {
    int i, temp=0;
    LIFO_Buf_t uart_lifo, I2C_lifo;
    //static allocation
    LIFO_Init(&uart_lifo, buffer1, 5);

    //dynamic allocation
    unsigned int *buffer2 = (unsigned int *)malloc(5 * sizeof(unsigned int));
    LIFO_Init(&I2C_lifo, buffer2, 5);

    //push item to the lifo
    for (i = 0; i < 5; i++) {
       if( LIFO_Push_item(&uart_lifo, i)==LIFO_NO_ERROR)
        printf("uart_lifo_add: %d\n", i);
    }
    //pop item from the lifo
    for (i = 0; i < 5; i++) {
       if( LIFO_Pop_item(&uart_lifo, &temp)== LIFO_NO_ERROR)
        printf("uart_lifo: %d\n", temp);
    }
    
    
}
