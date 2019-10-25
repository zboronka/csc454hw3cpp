#ifndef NETWORK_HPP
#define NETWORK_HPP

#define LINEWIDTH 30
#define BOXC "\u001b[31m"
#define TICKC "\u001b[33m"
#define RESETC "\u001b[39;49m"

#include <iostream>
#include <vector>

#include "mooremachine.hpp"
#include "xor.hpp"
#include "memory.hpp"
#include "couple.hpp"

using namespace std;

class Network : public MooreMachine {
	private:
		vector<Couple*>* couples = new vector<Couple*>();

		MooreMachine* input;
		MooreMachine* output;

		int currentTick = 0;
		int ticks;

		vector<string>* coupleOutput = new vector<string>();

		bool verb = false;

	public:
		Network(MooreMachine* in, MooreMachine* out, int t) { input = in; output = out, ticks = t; }

		bool lambda() { return output->lambda(); }
		void delta(vector<bool>* in);

		void addCouple(Couple* couple) { couples->push_back(couple); }
		void verbose();

		void step(int t) { ticks = t; }
		string line(string, int);
};

#endif
