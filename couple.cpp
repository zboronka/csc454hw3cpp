#include "couple.hpp"

Couple::Couple(MooreMachine* input, vector<bool>* o) {
	inputs.push_back(input);
	output = o;
}

void Couple::pipe() {
	for(auto m = inputs.begin(); m != inputs.end(); m++) {
		output->push_back((*m)->lambda());
	}
}
