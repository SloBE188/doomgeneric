[BITS 32]

section .text
global _userstart

extern doom_main

_userstart:
    mov eax, 0
    call doom_main

loop:
    jmp loop


