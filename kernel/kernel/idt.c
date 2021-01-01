#include <kernel/idt.h>

void idt_initialize_entry(IDT_entry* entry, uint16_t bits_low, uint16_t selector, uint8_t zero, uint8_t type, uint16_t high_bits) {
	entry->low_bits = bits_low;
	entry->selector = selector;
	entry->zero = zero;
	entry->type = type;
	entry->high_bits = high_bits;
}

void idt_initialize(void) {
	extern int load_idt();
	extern int irq0();
	extern int irq1();
	extern int irq2();
	extern int irq3();
	extern int irq4();
	extern int irq5();
	extern int irq6();
	extern int irq7();
	extern int irq8();
	extern int irq9();
	extern int irq10();
	extern int irq11();
	extern int irq12();
	extern int irq13();
	extern int irq14();
	extern int irq15();

	uint32_t irq0_address;
	uint32_t irq1_address;
	uint32_t irq2_address;
	uint32_t irq3_address;
	uint32_t irq4_address;
	uint32_t irq5_address;
	uint32_t irq6_address;
	uint32_t irq7_address;
	uint32_t irq8_address;
	uint32_t irq9_address;
	uint32_t irq10_address;
	uint32_t irq11_address;
	uint32_t irq12_address;
	uint32_t irq13_address;
	uint32_t irq14_address;
	uint32_t irq15_address;
	uint32_t idt_address;
	uint32_t idt_ptr[2];

	outb(0x20, 0x11);
	outb(0xA0, 0x11);
	outb(0x21, 0x20);
	outb(0xA1, 40);
	outb(0x21, 0x04);
	outb(0xA1, 0x02);
	outb(0x21, 0x01);
	outb(0xA1, 0x01);
	outb(0x21, 0x0);
	outb(0xA1, 0x0);

	irq0_address = (uint32_t)irq0;
	idt_initialize_entry(&(IDT[32]), irq0_address & 0xFFFF, 0x08, 0, 0x8E, (irq0_address & 0xFFFF0000) >> 16);

	irq1_address = (uint32_t)irq0;
	idt_initialize_entry(&(IDT[33]), irq1_address & 0xFFFF, 0x08, 0, 0x8E, (irq1_address & 0xFFFF0000) >> 16);

	irq2_address = (uint32_t)irq0;
	idt_initialize_entry(&(IDT[34]), irq2_address & 0xFFFF, 0x08, 0, 0x8E, (irq2_address & 0xFFFF0000) >> 16);

	irq3_address = (uint32_t)irq0;
	idt_initialize_entry(&(IDT[35]), irq3_address & 0xFFFF, 0x08, 0, 0x8E, (irq3_address & 0xFFFF0000) >> 16);

	irq4_address = (uint32_t)irq0;
	idt_initialize_entry(&(IDT[36]), irq4_address & 0xFFFF, 0x08, 0, 0x8E, (irq4_address & 0xFFFF0000) >> 16);

	irq5_address = (uint32_t)irq0;
	idt_initialize_entry(&(IDT[37]), irq5_address & 0xFFFF, 0x08, 0, 0x8E, (irq5_address & 0xFFFF0000) >> 16);

	irq6_address = (uint32_t)irq0;
	idt_initialize_entry(&(IDT[38]), irq6_address & 0xFFFF, 0x08, 0, 0x8E, (irq6_address & 0xFFFF0000) >> 16);

	irq7_address = (uint32_t)irq0;
	idt_initialize_entry(&(IDT[39]), irq7_address & 0xFFFF, 0x08, 0, 0x8E, (irq7_address & 0xFFFF0000) >> 16);

	irq8_address = (uint32_t)irq0;
	idt_initialize_entry(&(IDT[40]), irq8_address & 0xFFFF, 0x08, 0, 0x8E, (irq8_address & 0xFFFF0000) >> 16);

	irq9_address = (uint32_t)irq0;
	idt_initialize_entry(&(IDT[41]), irq9_address & 0xFFFF, 0x08, 0, 0x8E, (irq9_address & 0xFFFF0000) >> 16);

	irq10_address = (uint32_t)irq0;
	idt_initialize_entry(&(IDT[42]), irq10_address & 0xFFFF, 0x08, 0, 0x8E, (irq10_address & 0xFFFF0000) >> 16);

	irq11_address = (uint32_t)irq0;
	idt_initialize_entry(&(IDT[43]), irq11_address & 0xFFFF, 0x08, 0, 0x8E, (irq11_address & 0xFFFF0000) >> 16);

	irq12_address = (uint32_t)irq0;
	idt_initialize_entry(&(IDT[44]), irq12_address & 0xFFFF, 0x08, 0, 0x8E, (irq12_address & 0xFFFF0000) >> 16);

	irq13_address = (uint32_t)irq0;
	idt_initialize_entry(&(IDT[45]), irq13_address & 0xFFFF, 0x08, 0, 0x8E, (irq13_address & 0xFFFF0000) >> 16);

	irq14_address = (uint32_t)irq0;
	idt_initialize_entry(&(IDT[46]), irq14_address & 0xFFFF, 0x08, 0, 0x8E, (irq14_address & 0xFFFF0000) >> 16);

	irq15_address = (uint32_t)irq0;
	idt_initialize_entry(&(IDT[47]), irq15_address & 0xFFFF, 0x08, 0, 0x8E, (irq15_address & 0xFFFF0000) >> 16);

	idt_address = (uint32_t) IDT;
	idt_ptr[0] = (sizeof(struct IDT_entry) * 256) + ((idt_address & 0xFFFF) << 16);
	idt_ptr[1] = idt_address >> 16;

	load_idt(idt_ptr);
}