#ifndef MOOREMACHINE_HPP
#define MOOREMACHINE_HPP

#include <vector>

using namespace std;

class MooreMachine {
	public:
		virtual bool lambda() = 0;
		virtual void delta(vector<bool>*) = 0;
};

#endif
