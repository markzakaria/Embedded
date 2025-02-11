/*
author: mark
date: 8/2/2025
fifo lab
*/

#include "fifo.h"
void main(){
    FIFO_Buf_t FIFO_UART;
    if(FIFO_Init(&FIFO_UART,uart_buf,5)==FIFO_NO_ERROR)
        printf("fifo init done\n");

    element_type i, temp;
    for(i=0;i<7;i++)
    {
        printf("FIFO enqueue (%x)\n",i);
        if(FIFO_Enq_item(&FIFO_UART,i)== FIFO_NO_ERROR)
            printf("FIFO enqueue done\n");
        else
            printf("FIFO enqueue failed\n");
    }

    FIFO_print(&FIFO_UART);

    if(FIFO_Deq_item(&FIFO_UART,&temp)== FIFO_NO_ERROR)
            printf("FIFO dequeue %x done\n",temp);
    if(FIFO_Deq_item(&FIFO_UART,&temp)== FIFO_NO_ERROR)
            printf("FIFO dequeue %x done\n",temp);

    FIFO_print(&FIFO_UART);
}