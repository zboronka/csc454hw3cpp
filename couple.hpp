#ifndef COUPLE_HPP
#define COUPLE_HPP

#include <string>

#include "mooremachine.hpp"

using namespace std;

class Couple {
	private:
		vector<MooreMachine*>* inputs = new vector<MooreMachine*>;
		vector<MooreMachine*>* outputs = new vector<MooreMachine*>;

		vector<bool>* output = new vector<bool>();
		vector<string>* output_string = new vector<string>();

		bool verb = false;

	public:
		~Couple() { delete inputs; delete outputs; delete output; delete output_string; }
		void pipe();
		void deltas();

		void addInput(MooreMachine* in) { inputs->push_back(in); }
		void addOutput(MooreMachine* out) { outputs->push_back(out); }

		vector<string>* getOutput() { return output_string; }
		vector<bool>* get() { return output; }

		void verbose() { verb = !verb; }
};

#endif
