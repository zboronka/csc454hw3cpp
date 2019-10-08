#include "network.hpp"

Network::Network() {
	xor1 = XOR();
	xor2 = XOR();
	m = Memory();
}

bool Network::lambda() {
	return(xor2.lambda());
}

void Network::delta(int start,...) {
	va_list x;
	va_start(x, start);

	bool x1 = va_arg(x, int);
	bool x2 = va_arg(x, int);
	bool verbose = start > 2;
	int step = start > 3 ? 1 : 3;

	for(int i = 0; i < step; i++) {
		if(verbose) {
			cout << "=============TICK " << tick << "=============" << endl;
		}

		bool l_xor1 = xor1.lambda();
		if(verbose) {
			cout << "XOR1 lambda=        {" << l_xor1 << "}" << endl;
		}

		bool l_xor2 = xor2.lambda();
		if(verbose) {
			cout << "XOR2 lambda=        {" << l_xor2 << "}" << endl;
		}

		bool l_m = m.lambda();
		if(verbose) {
			cout << "M lambda=           {" << l_m << "}" << endl;
		}

		xor1.delta(0, x1, x2);
		if(verbose) {
			cout << "XOR1 delta, state=  {" << (x1 ^ x2) << "}" << endl;
		}

		xor2.delta(0, l_xor1, l_m);
		if(verbose) {
			cout << "XOR2 delta, state=  {" << (l_xor1 ^ l_m) << "}" << endl;
		}

		m.delta(0, l_xor2);
		if(verbose) {
			cout << "M delta, state=     {q1=" << l_m << ", q2=" << l_xor2 << "}" << endl;
		}
		
		tick = (tick + 1) % 3;
	}
	
	va_end(x);
}
