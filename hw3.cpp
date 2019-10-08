#include<iostream>

#include "xor.hpp"
#include "memory.hpp"
#include "network.hpp"

using namespace std;

int main() {
	Network * n = new Network();
	bool show = false;
	bool step = false;

	string command;
	for(cin >> command; command != "exit"; cin >> command) {
		if(command.compare("verbose") == 0) {
			show = true;
		}
		else if(command.compare("normal") == 0) {
			show = false;
		}
		else if(command.compare("step") == 0) {
			step = true;
		}
		else if(command.compare("nostep") == 0) {
			step = false;
		}
		else {
			cout << "Network output= " << n->lambda() << endl;
			if(show && step) {
				n->delta(4, command[0] == '1', command[1] == '1', show, step);
			}
			else if(show) {
				n->delta(3, command[0] == '1', command[1] == '1', show);
			}
			else {
				n->delta(0, command[0] == '1', command[1] == '1');
			}
		}

		cout << endl;
	}

	delete(n);
}
