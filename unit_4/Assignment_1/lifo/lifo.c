/*
author: mark
date: 2025-02-08
description: lifo stack
*/
#include "lifo.h"
//APIs
LIFO_Status LIFO_Init(LIFO_Buf_t *lifo_buf, unsigned int *buf, unsigned int length) {
    if (buf == NULL) {
        return LIFO_NULL;
    }
    lifo_buf->base = buf;
    lifo_buf->head = buf;
    lifo_buf->length = length;
    lifo_buf->count = 0;
    return LIFO_NO_ERROR;
}

LIFO_Status LIFO_Push_item (LIFO_Buf_t* lifo_buf, unsigned int item)
{
    //check for valid lifo
    if(!lifo_buf->base || !lifo_buf->head)
        return LIFO_NULL;

    //check whether lifo is full
    if (lifo_buf->count == lifo_buf->length)
        return LIFO_FULL;

    //add value
    *(lifo_buf->head) = item;
    lifo_buf->head++;
    lifo_buf->count++;

    return LIFO_NO_ERROR;
}

LIFO_Status LIFO_Pop_item (LIFO_Buf_t* lifo_buf, unsigned int* item)
{
    //check for valid lifo
    if(!lifo_buf->base || !lifo_buf->head)
        return LIFO_NULL;

    //check whether lifo is full
    if (lifo_buf->count == 0)
        return LIFO_EMPTY;

    //get value
    lifo_buf->head--;
    *item =*(lifo_buf->head);
    lifo_buf->count--;

    return LIFO_NO_ERROR;
}
