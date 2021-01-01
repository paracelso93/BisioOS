#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/gdt.h>
#include <kernel/idt.h>

void kernel_main(void) {
    terminal_initialize();
    struct GlobalDescriptorTable gdt;
    initialize_gdt(&gdt);
    initialize_idt();
    printf("Hello, kernel World!\n");
}
