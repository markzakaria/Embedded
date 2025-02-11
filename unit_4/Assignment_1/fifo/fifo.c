/*
author: mark
date: 8/2/2025
fifo lab
*/
#include "fifo.h"

//APIs
FIFO_Buf_Status FIFO_Init(FIFO_Buf_t *fifo_buf, element_type *buf, uint32_t length){
    if(buf==NULL)
        return FIFO_NULL;

    fifo_buf->base =buf;
    fifo_buf->head =buf;
    fifo_buf->tail =buf;
    fifo_buf->length =length;
    fifo_buf->count =0;

    return FIFO_NO_ERROR;
}
FIFO_Buf_Status FIFO_Enq_item(FIFO_Buf_t *fifo_buf, element_type item){
    if(!fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
        return FIFO_NULL;
    if(FIFO_IS_FULL(fifo_buf) == FIFO_FULL)
        return FIFO_FULL;

    *(fifo_buf->head)=item;
    fifo_buf->count++;
    //apply circular approach
    if(fifo_buf->head == (fifo_buf->base +(fifo_buf->length*sizeof(element_type))))
        fifo_buf->head = fifo_buf->base;
    else
        fifo_buf->head++; 

    return FIFO_NO_ERROR;
    }


FIFO_Buf_Status FIFO_Deq_item(FIFO_Buf_t *fifo_buf, element_type *item){
    if(!fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
        return FIFO_NULL;
    if(fifo_buf->count == 0)
        return FIFO_EMPTY;

    *item = *(fifo_buf->tail);
    fifo_buf->count--;

    //apply circular approach
    if(fifo_buf->tail == (fifo_buf->base +(fifo_buf->length*sizeof(element_type))))
        fifo_buf->tail = fifo_buf->base;
    else
        fifo_buf->tail++; 

    return FIFO_NO_ERROR;
    }

FIFO_Buf_Status FIFO_IS_FULL(FIFO_Buf_t *fifo_buf){
    if(!fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
        return FIFO_NULL;
    if(fifo_buf->count == fifo_buf->length)
        return FIFO_FULL;
}
//print fifo elements
void FIFO_print(FIFO_Buf_t *fifo_buf){ 
    element_type* temp;
    int i=0;

    if(fifo_buf->count == 0)
        printf("fifo is empty\n");
    else{
        temp = fifo_buf->tail;
        printf("fifo is printing\n");
        for(i=0;i<fifo_buf->count;i++){
            printf("\t %x \n",*temp);
            temp++;
        }
        printf("/////////////////////");
    }
}