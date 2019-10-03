#include "memory.hpp"

void Memory::delta(void * start, ...) {
	va_list x;
	va_start(x, start);

	q1 = q2;
	q2 = va_arg(x, int);

	va_end(x);
}
