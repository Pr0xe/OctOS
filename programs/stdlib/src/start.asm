[BITS 32]

global _start
extern c_start
extern octos_exit

section .asm

_start:
        call c_start
        call octos_exit
        ret