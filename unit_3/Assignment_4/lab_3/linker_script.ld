/*linker_script.ld
lab2
made by mark
*/
MEMORY
{
	flash(RX) : ORIGIN = 0x08000000, LENGTH = 512M
	sram(RWX) : ORIGIN = 0x20000000, LENGTH = 512M
}

SECTIONS
{
	.text : {
             *(.vectors*)
             *(.text*) 
             *(.rodata*)
	     _E_text = . ;
                } > flash


	.data : {
             _S_Data = . ;
             *(.data*) 
             . = ALIGN(4) ;
             _E_Data = . ;
                }>sram AT> flash


	.bss : {
             _S_bss = . ;
             *(.bss*) 
             _E_bss = . ;
           /*specified stack in the startup*/   
                } > sram
}