#include "xor.hpp"

void XOR::delta(int start, ...) {
	va_list x;
	va_start(x, start);

	state = va_arg(x, int) ^ va_arg(x, int);

	va_end(x);
}
