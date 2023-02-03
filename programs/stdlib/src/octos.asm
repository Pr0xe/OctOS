[BITS 32]

section .asm

global print:function
global octos_getkey:function
global octos_putchar:function
global octos_malloc:function
global octos_free:function
global octos_process_load_start:function
global octos_process_get_arguments:function
global octos_system:function
global octos_exit:function

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

;void octos_process_load_start(const char* filename)
octos_process_load_start:
        push ebp
        mov ebp, esp
        mov eax, 6 ;command 6 process load start
        push dword[ebp+8] ; variable filename
        int 0x80
        add esp, 4
        pop ebp
        ret

;int octos_system(struct command_argument* arguments)
octos_system:
        push ebp
        mov ebp, esp
        mov eax, 7 ;Command 7 process_system
        push dword[ebp+8]
        int 0x80
        add esp, 4
        pop ebp
        ret

;void octos_process_get_arguments(struct process_arguments* arguments)
octos_process_get_arguments:
        push ebp
        mov ebp, esp
        mov eax, 8 ; Command 8 get the process argument
        push dword[ebp+8] ; variable argument
        int 0x80
        add esp, 4
        pop ebp
        ret

;void octos_exit()
octos_exit:
        push ebp
        mov ebp, esp
        mov eax, 9 ; Command 9 process exit
        int 0x80
        pop ebp
        ret