[BITS 32]

section .asm

global print:function
global octos_getkey:function
global octos_putchar:function
global octos_malloc:function
global octos_free:function

;void print(const char *filename)
print:
        push ebp
        mov ebp, esp
        push dword[ebp+8]
        mov eax ,1 ;Command print
        int 0x80
        add esp, 4

        pop ebp
        ret

;int octos_getkey()
octos_getkey:
        push ebp
        mov ebp, esp
        mov eax, 2; command getkey
        int 0x80
        pop ebp
        ret

;void octos_putchar(char c)
octos_putchar:
        push ebp
        mov ebp, esp
        mov eax, 3;putchar command
        push dword [ebp+8] ; variable "c"
        int 0x80
        add esp, 4
        pop ebp
        ret

;void* octos_malloc(size_t size)
octos_malloc:
        push ebp
        mov ebp, esp
        mov eax, 4; command malloc
        push dword[ebp+8]; Variable "size"
        int 0x80
        add esp, 4
        pop ebp
        ret

;void octos_free(void* ptr)
octos_free:
        push ebp
        mov ebp, esp
        mov eax, 5 ; free command
        push dword[ebp+8] ; variable ptr
        int 0x80
        add esp, 4
        pop ebp
        ret