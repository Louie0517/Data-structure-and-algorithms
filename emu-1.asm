 section .data
    msg db "Insert character: ", 0
    msglen equ $-msg
    
    msg2 db "Insert character: ", 0
    msg2len equ $-msg2
    
    newline db 10, 0
    
 section .bss
    char resb 1 
    num resb 4
    
 sectio .text
    global _start
    
 _start:
    
    MOV EAX, 4      
    MOV EBX, 1      
    MOV ECX, msg    
    MOV EDX, msglen     
    INT 0x80        
    
    MOV EAX, 3     
    MOV EBX, 10
    MOV ECX, CHAR
    MOV EDX, 1
    INT 0x80
    
    MOV EAX, 4
    MOV EBX, 1
    MOV ECX, msg2
    MOV EDX, msg2len
    INT 0x80 
    
    
    MOV EAX, 3
    MOV EBX, 0
    MOV ECX, num
    MOV EDX, 4
    INT 0x80
    
    MOV ESI, num
    MOV EXC, ECX
    
 convert_loop:
     
    MOV AL, [ESI]
    CMP AL, 10
    JE convert_done
    SUB AL, '0'
    IMUL ECX, ECX, 10
    ADD EXC, EAX
    INC ESI
    JMP convert_loop
    
 convert_done:
 
 print_loop:
    CMP ECX, 0
    JE done_print
    MOV EAX, 4
    MOV EBX, 1
    MOV EBX, 1
    MOV ESI, CHAR
    MOV ECX, ESI
    INT 0x80
    DEC ECX, 1
    JMP print_loop
    
 done_print:
    MOV EAX, 4
    MOV EBX, 1
    MOV ECX, newline
    MOV EDX, 1
    INT 0x80
    
    MOV EAX, 1
    XOR EBX, EBX
    INT 0x80 
    
    
    
    