[BITS 32]

section .text
global _doomstart

extern doom_main

_doomstart:
    mov eax, 0
    call doom_main

loop:
    jmp loop
