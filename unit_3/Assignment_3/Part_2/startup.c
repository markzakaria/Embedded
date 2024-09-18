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
void MM_Fault_Handler (void) __attribute__((weak, alias ("Default_Handler")));
void Bus_Handler (void) __attribute__((weak, alias ("Default_Handler")));
void Usage_Fault_Handler (void) __attribute__((weak, alias ("Default_Handler")));

extern unsigned int _stack_top ;

//option for the toolchain compiler to specify the desired section
uint32_t vectors[] __attribute__((section(".vectors")))=
{
(uint32_t) &_stack_top,
(uint32_t) &Reset_Handler ,
(uint32_t) &NMI_Handler ,
(uint32_t) &H_Fault_Handler ,
(uint32_t) &MM_Fault_Handler ,
(uint32_t) &Bus_Handler ,
(uint32_t) &Usage_Fault_Handler
};
//defining symbols
extern unsigned int _S_text ;
extern unsigned int _E_text ;
extern unsigned int _S_Data ;
extern unsigned int _E_Data ;
extern unsigned int _S_bss ;
extern unsigned int _E_bss ;

void Reset_Handler (void){
//coping symbols variables from flash to
//casting to char to move data byte by byte due to allignment
unsigned int DATA_Size = (unsigned char*)&_E_Data - (unsigned char*)&_S_Data ;
unsigned char* P_source = (unsigned char*)&_E_text;
unsigned char* P_destination = (unsigned char*)&_S_Data;

for(int i = 0; i<DATA_Size; i++){
    *((unsigned char*) P_destination++) = *((unsigned char*) P_source++) ;
}
//in case of existence of uninitialized data
unsigned int BSS_Size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss ;

for(int i = 0; i<BSS_Size; i++){
    *((unsigned char*) P_destination++) = 0 ;
}

    main();
}

