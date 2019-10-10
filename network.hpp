#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <iostream>
#include <vector>

#include "mooremachine.hpp"
#include "xor.hpp"
#include "memory.hpp"
#include "couple.hpp"

using namespace std;

class Network : public MooreMachine {
	private:
		vector<MooreMachine *> machines;
		vector<vector<bool>> pipes;
		vector<Couple *> couples;
		XOR xor1;
		XOR xor2;
		Memory m;

	public:
		Network();
		~Network();
		
		bool lambda();
		void delta(int, ...);

		int addMM(MooreMachine *);
		void addCouple(int, int);
};

#endif
