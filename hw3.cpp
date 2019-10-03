#include<iostream>

#include "xor.hpp"
#include "memory.hpp"

using namespace std;

int main() {
	XOR * x1 = new XOR();
	Memory * m = new Memory();

	cout << "First x1=" << x1->lambda() << endl;
	cout << "First m=" << m->lambda() << endl;

	string command;
	for(cin >> command; command != "exit"; cin >> command) {
		x1->delta(0, command[0] == '1', command[1] == '1');
		m->delta(0, command[2] == '1');
		cout << "X1=" << x1->lambda() << endl << "M=" << m->lambda() << endl;
	}

	delete(x1);
	delete(m);
}
