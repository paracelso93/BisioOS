#include <kernel/gdt.h>

uint8_t* initialize_descriptor(struct Descriptor* descriptor, uint32_t base, uint32_t limit, uint8_t type) {
	if ((limit > 65536) && (limit & 0xFFF) != 0xFFF) {
		// TODO: panic
	} 
	if (limit > 65536) {
		limit = limit >> 12;
		descriptor->limit_high_flags = 0xC0;
	} else {
		descriptor->limit_high_flags = 0x40;
	}

	descriptor->limit_low = limit & 0xFFFF;
	descriptor->limit_high_flags |= (limit >> 16) & 0xF;

	descriptor->base_low = base & 0xFFFF;
	descriptor->base_high = (base >> 16) & 0xFF;
	descriptor->base_vhigh = (base >> 24) & 0xFF;

	descriptor->type = type; 
	return (uint8_t*) descriptor;
}

void initialize_gdt(struct GlobalDescriptorTable* table) {
	uint32_t gdt[2];
	intialize_descriptor(&table->selectors[0], 0, 0, 0);
	intialize_descriptor(&table->selectors[1], 0, 0, 0);
	intialize_descriptor(&table->selectors[2], 0, 64 * 1024 * 1024, 0x9A);
	intialize_descriptor(&table->selectors[3], 0, 64 * 1024 * 1024, 0x92);
	gdt[0] = (uint32_t) table;
	gdt[1] = sizeof(GlobalDescriptorTable) << 16;
	asm volatile (
		"lgdt (%0)": :"p" (((uint8_t*) gdt) + 2)
	);
}