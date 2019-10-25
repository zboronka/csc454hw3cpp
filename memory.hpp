#ifndef MEMORY_HPP
#define MEMORY_HPP

#include "mooremachine.hpp"

class Memory : public MooreMachine {
	private:
		bool q1 = false;
		bool q2 = false;

	public:
		bool lambda() { return q1; }
		void delta(vector<bool>* in) { q1 = q2; q2 = (*in)[0]; }
};

#endif
