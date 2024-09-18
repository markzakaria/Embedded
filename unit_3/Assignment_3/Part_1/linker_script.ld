/*linker_script.ld
lab2
made by mark
*/
MEMORY
{
	flash(RX) : ORIGIN = 0x08000000, LENGTH = 128K
	sram(RWX) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
	.text : {
             *(.vectors*)
             *(.text*) 
             *(.rodata*)
                } > flash

	.bss : {
             *(.bss*) 
                } > sram

	.data : {
             *(.data*) 
                } >flash
}