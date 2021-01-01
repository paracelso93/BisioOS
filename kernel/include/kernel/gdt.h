#ifndef _GDT_H
#define _GDT_H

#include <stddef.h>
#include <stdint.h>

struct Descriptor {
	uint16_t limit_low;
	uint16_t base_low;
	uint8_t base_high;
	uint8_t type;
	uint8_t limit_high_flags;
	uint8_t base_vhigh;
} __attribute__((packed));

uint8_t* initialize_descriptor(struct Descriptor* descriptor, uint32_t base, uint32_t limit, uint8_t type);

struct GlobalDescriptorTable {
	struct Descriptor selectors[4];
} __attribute__((packed));

void initialize_gdt(struct GlobalDescriptorTable* table);

#endif
