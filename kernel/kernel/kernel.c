#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/gdt.h>

void kernel_main(void) {
    terminal_initialize();
    struct GlobalDescriptorTable gdt;
    initialize_gdt(&gdt);
    printf("Hello, kernel World!\n");
}
