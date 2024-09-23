//startup.c
//made by mark 2024

#include <stdint.h>

void Reset_Handler ();
extern int main(void);
void Default_Handler (){
    Reset_Handler ();
}
//weak -> specifies a fun() can be overwritten by another file
//alias -> to specify that the current symbol point to one handler containing all the addresses
void NMI_Handler (void) __attribute__((weak, alias ("Default_Handler")));
void H_Fault_Handler (void) __attribute__((weak, alias ("Default_Handler")));

static unsigned long Stack_Top[256];

//option for the toolchain compiler to specify the desired section
void ( * const g_P_F_Vectors[])() __attribute__((section(".vectors")))=
{
    (void(*)()) ((unsigned long)Stack_Top + sizeof(Stack_Top)),
    &Reset_Handler ,
    &NMI_Handler ,
    &H_Fault_Handler
};

//defining symbols
extern unsigned int _E_text ;
extern unsigned int _S_Data ;
extern unsigned int _E_Data ;
extern unsigned int _S_bss ;
extern unsigned int _E_bss ;

void Reset_Handler (void){
//coping symbols variables from flash to RAM
//casting to char to move data byte by byte due to alignment
unsigned int DATA_Size = (unsigned char*)&_E_Data - (unsigned char*)&_S_Data ;
unsigned char* P_source = (unsigned char*)&_E_text;
unsigned char* P_destination = (unsigned char*)&_S_Data;

for(int i = 0; i<DATA_Size; i++){
    *((unsigned char*) P_destination++) = *((unsigned char*) P_source++) ;
}
//in case of existence of uninitialized data
unsigned int BSS_Size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss ;

for(int i = 0; i<BSS_Size; i++){
    *((unsigned char*) P_destination++) = (unsigned char)0 ;
}

    main();
}

