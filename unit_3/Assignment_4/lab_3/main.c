/*lab_3_unit_3
made by mark 2024*/
#include <Platform_Types.h>
#define SYSCTRL_RCGC2_R         (*((vuint32_t*)0x400FE108))
#define GPIO_PORTF_DATA_R       (*((vuint32_t*)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((vuint32_t*)0x40025400))
#define GPIO_PORTF_DEN_R        (*((vuint32_t*)0x4002551C))

int main (void){
    vuint32_t delay_counter;
    SYSCTRL_RCGC2_R = 0x00000020;
    //delay to make sure that GPIO is up and the clock is ready
    for (delay_counter= 0; delay_counter < 200000; delay_counter++);
    GPIO_PORTF_DIR_R |= 1<<3 ;    //dir -> output or input and for our pin3 port F we set it output
    GPIO_PORTF_DEN_R |= 1<<3 ;
    while(1){
        GPIO_PORTF_DATA_R |= 1<<3;
        for (delay_counter= 0; delay_counter < 200000; delay_counter++);
        GPIO_PORTF_DATA_R &= ~(1<<3);
        for (delay_counter= 0; delay_counter < 200000; delay_counter++);

    }
    return 0;
}
