#ifndef XOR_HPP
#define XOR_HPP

#include "mooremachine.hpp"

class XOR : public MooreMachine {
	private:
		bool state = false;

	public:
		bool lambda() { return state; }
		void delta(vector<bool>* in) { state = (*in)[0] ^ (*in)[1]; }
};

#endif
