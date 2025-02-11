/*
author: mark
date: 8/2/2025
fifo lab
*/
#ifndef FIFO_H_
#define FIFO_H_

#include <stdio.h>
#include <stdint.h>

#define element_type uint8_t 
#define width 5
element_type uart_buf[width];

typedef struct
{
    unsigned int length;
    unsigned int count;
    element_type* base;
    element_type* head;
    element_type* tail;
}FIFO_Buf_t;

typedef enum {
    FIFO_NO_ERROR,
    FIFO_FULL,
    FIFO_EMPTY,
    FIFO_NULL
}FIFO_Buf_Status;

//APIs
FIFO_Buf_Status FIFO_Init(FIFO_Buf_t *fifo_buf, element_type *buf, uint32_t length); //initialize the fifo
FIFO_Buf_Status FIFO_Enq_item(FIFO_Buf_t *fifo_buf, element_type item); //add item to the fifo
FIFO_Buf_Status FIFO_Deq_item(FIFO_Buf_t *fifo_buf, element_type *item); //get item from the fifo
FIFO_Buf_Status FIFO_IS_FULL(FIFO_Buf_t *fifo_buf);
//print fifo elements
void FIFO_print(FIFO_Buf_t *fifo_buf);
#endif /* FIFO_H_ */


