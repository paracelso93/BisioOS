#include <debug.h>

__attribute__((noreturn))
void __stack_chk_fail(void) {
#if __STDC_HOSTED__
	abort();
#elif __is_bisios_kernel
	panic("Stack smashing detected");
#endif
}