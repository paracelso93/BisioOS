#ifndef _IDT_H
#define _IDT_H

#include <stddef.h>
#include <stdint.h>

struct IDT_entry {
	uint16_t low_bits;
	uint16_t selector;
	uint8_t zero;
	uint8_t type;
	uint16_t high_bits;
}

struct IDT_entry IDT[256];

void idt_initialize_entry(IDT_entry* entry, uint16_t bits_low, uint16_t selector, uint8_t zero, uint8_t type, uint16_t high_bits);
void idt_initialize(void);

#endif