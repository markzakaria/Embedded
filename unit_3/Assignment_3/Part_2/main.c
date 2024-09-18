/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mark Zakaria
 * @brief          : Main program body
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 ******************************************************************************
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <Platform_Types.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

typedef volatile unsigned int vuint32_t;
//register addresses
#define Rcc_base   0x40021000
#define GPIO_base  0x40010800  //port A
#define Rcc_APB2ENR   *(volatile uint32_t *)(Rcc_base + 0x18)
#define GPIO_CRH   *(volatile uint32_t *)(GPIO_base + 0x04)
#define GPIO_ODR   *(volatile uint32_t *)(GPIO_base + 0x0C)

//Bit field
#define Rcc_IOPAEN (1<<2)
#define GPIOA13 (1UL<<13)

typedef union {
	vuint32_t   all_fields;
	struct {
		vuint32_t  reserved : 13;
		vuint32_t  pin_13   : 1;
	       }pin;
              }R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIO_base + 0x0C);

unsigned char g_var[3]={1,2,3};
unsigned char const const_var[3]={5,6,7};

int main(void)
{
    Rcc_APB2ENR |= Rcc_IOPAEN;
    GPIO_CRH &= 0xFF0FFFFF;
    GPIO_CRH |= 0x00200000;
    while(1){
    	R_ODR->pin.pin_13 =1;   //set bit 13
    	for (int var = 0; var < 10000; ++var);
		R_ODR->pin.pin_13 =0;   //reset bit 13
		for (int v = 0; v < 10000; ++v);
            }

}
