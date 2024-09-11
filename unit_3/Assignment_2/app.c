#include "uart.h"
const int x=100;
unsigned char string_buffer[100]="learn in depth 2024 : mark";
int main(){
uart_send_string(string_buffer);
    return 0;
}