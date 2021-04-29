.section .gdt
# Setup that GDT
gdt:
 
gdt_null:
    .word 0
    .word 0
    .word 0
    .word 0
 
gdt_code:
    .word 65535
    .word 0
 
    .byte 0
    .byte 154
    .byte 207
    .byte 0
 
gdt_data:
    .word 65535
    .word 0
 
    .byte 0
    .byte 154
    .byte 207
    .byte 0
 
gdt_end:
 
gdt_desc:
    .word gdt_end - gdt - 1
    .word gdt