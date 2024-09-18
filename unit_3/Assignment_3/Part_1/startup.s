/*startup lab 2
made by Mark
*/

//gathering all inerrupts
.section .vectors
//SRAM
.word 0x20001000
//vectors after SRAM by 4 bytes
.word _reset
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler
.word vector_handler

.section .text
_reset:
	bl main
	b .

.thumb_func

vector_handler:
	b _reset