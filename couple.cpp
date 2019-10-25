#include <iostream>
#include "couple.hpp"

void Couple::pipe() {
	output->clear();
	output_string->clear();
	for(auto i = inputs->begin(); i != inputs->end(); i++) {
		output->push_back((*i)->lambda());
		if(verb) {
			char buffer [50];
			sprintf(buffer, "%p lambda = %s", *i, output->back() ? "true" : "false");
			output_string->push_back(string(buffer));
		}
	}
}

void Couple::deltas() {
	output_string->clear();
	for(auto o = outputs->begin(); o != outputs->end(); o++) {
		(*o)->delta(output);
		if(verb) {
			char buffer [50];
			sprintf(buffer, "%p ran delta", *o);
			output_string->push_back(string(buffer));
		}
	}
}
