/*
author: mark
date: 2025-02-08
description: lifo stack
*/

#ifndef LIFO_H
#define LIFO_H

typedef struct {
    unsigned int length;
    unsigned int count;
    unsigned int *base;
    unsigned int *head;
} LIFO_Buf_t;

typedef enum {
    LIFO_NO_ERROR,
    LIFO_FULL,
    LIFO_NOT_FULL,
    LIFO_EMPTY,
    LIFO_NULL
} LIFO_Status;

//APIs
LIFO_Status LIFO_Init(LIFO_Buf_t *lifo_buf, unsigned int *buf, unsigned int length); //initialize the lifo
LIFO_Status LIFO_Push_item(LIFO_Buf_t *lifo_buf, unsigned int item); //push item to the lifo
LIFO_Status LIFO_Pop_item(LIFO_Buf_t *lifo_buf, unsigned int *item); //pop item from the lifo

#endif