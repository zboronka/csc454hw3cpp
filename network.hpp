#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <iostream>

#include "mooremachine.hpp"
#include "xor.hpp"
#include "memory.hpp"

using namespace std;

class Network : public MooreMachine {
	private:
		XOR xor1;
		XOR xor2;
		Memory m;
		int tick;

	public:
		Network();
		
		bool lambda();
		void delta(int, ...);
};

#endif
