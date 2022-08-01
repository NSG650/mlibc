#pragma once

#include <stdint.h>
#include <mlibc/tcb.hpp>

namespace mlibc {

inline Tcb *get_current_tcb() {
	// On AArch64, TPIDR_EL0 points to 0x10 bytes before the first TLS block.
	uintptr_t ptr;
	asm ("mrs %0, tpidr_el0" : "=r"(ptr));
	return reinterpret_cast<Tcb *>(ptr + 0x10 - sizeof(Tcb));
}

} // namespace mlibc
