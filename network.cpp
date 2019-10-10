#include "network.hpp"

Network::Network() {
	xor1 = XOR();
	xor2 = XOR();
	m = Memory();
}

Network::~Network() {
	for(auto m = machines.begin(); m != machines.end(); m++) {
		delete(*m);
	}
}

bool Network::lambda() {
	return(xor2.lambda());
}

void Network::delta(int start,...) {
	va_list x;
	va_start(x, start);

	bool x1 = va_arg(x, int);
	bool x2 = va_arg(x, int);

	for(int i = 0; i < 3; i++) {
		if(start > 2) {
			cout << "=============TICK " << i << "=============" << endl;
		}
		bool l_xor1 = xor1.lambda();
		if(start > 2) {
			cout << "XOR1 lambda=        {" << l_xor1 << "}" << endl;
		}

		bool l_xor2 = xor2.lambda();
		if(start > 2) {
			cout << "XOR2 lambda=        {" << l_xor2 << "}" << endl;
		}

		bool l_m = m.lambda();
		if(start > 2) {
			cout << "M lambda=           {" << l_m << "}" << endl;
		}

		xor1.delta(0, x1, x2);
		if(start > 2) {
			cout << "XOR1 delta, state=  {" << (x1 ^ x2) << "}" << endl;
		}

		xor2.delta(0, l_xor1, l_m);
		if(start > 2) {
			cout << "XOR2 delta, state=  {" << (l_xor1 ^ l_m) << "}" << endl;
		}

		m.delta(0, l_xor2);
		if(start > 2) {
			cout << "M delta, state=     {q1=" << l_m << ", q2=" << l_xor2 << "}" << endl;
		}
	}
	
	va_end(x);
}

int Network::addMM(MooreMachine * machine) {
	machines.push_back(machine);
	return(machines.size()-1);
}
