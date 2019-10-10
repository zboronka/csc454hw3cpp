#include <iostream>
#include <vector>

#include "xor.hpp"
#include "memory.hpp"
#include "network.hpp"
#include "couple.hpp"

using namespace std;

int main() {
	vector<bool>* b = new vector<bool>();
	Couple c = Couple(new XOR(), b);
	c.pipe();
	Network * n = new Network();
	bool show = false;
	int x = n->addMM(new XOR());
	int y = n->addMM(new XOR());

	string command;
	for(cin >> command; command != "exit"; cin >> command) {
		if(command.compare("verbose") == 0) {
			show = true;
		}
		else if(command.compare("normal") == 0) {
			show = false;
		}
		else {
			cout << n->lambda() << endl;
			if(show) {
				n->delta(3, command[0] == '1', command[1] == '1');
			}
			else {
				n->delta(0, command[0] == '1', command[1] == '1');
			}
		}
	}

	delete(n);
}
