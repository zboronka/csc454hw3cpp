#ifndef COUPLE_HPP
#define COUPLE_HPP

#include <vector>

#include "mooremachine.hpp"

using namespace std;

class Couple {
	private:
		vector<MooreMachine*> inputs;
		vector<bool>* output;

	public:
		Couple(MooreMachine*, vector<bool>*);
		void pipe();
};

#endif
