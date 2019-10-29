#include <iostream>
#include <vector>

#include "xor.hpp"
#include "memory.hpp"
#include "network.hpp"
#include "couple.hpp"

#define PROMPT "\u001b[32mnet_in# \u001b[39;49m"

using namespace std;

int main() {
	string command = "";
	bool step = false;
	vector<bool>* input = new vector<bool>();
	
	XOR* xor1 = new XOR();
	XOR* xor2 = new XOR();
	Memory* m = new Memory();

	Couple* one = new Couple();
	one->addInput(xor1);
	one->addInput(m);
	one->addOutput(xor2);

	Couple* two = new Couple();
	two->addInput(xor2);
	two->addOutput(m);

	Network* net = new Network(xor1, xor2, 3);
	net->addCouple(one);
	net->addCouple(two);

	cout << PROMPT;
	for(cin >> command; command != "exit"; cin >> command) {
		input->clear();
		if(command == "verbose") {
			net->verbose();
		}
		else if(command == "step") {
			int t = step ? 3 : 1;
			net->step(t);
			step != step;
		}
		else {
			input->push_back(command[0] == '1');
			input->push_back(command[1] == '1');

			printf("Network lambda %s\n", net->lambda() ? "true" : "false");
			net->delta(input);
		}

		cout << PROMPT;
	}

	delete input;
	delete xor1;
	delete xor2;
	delete m;
	delete one;
	delete two;
	delete net;
}
