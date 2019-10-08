#ifndef MOOREMACHINE_HPP
#define MOOREMACHINE_HPP

#include<cstdarg>
class MooreMachine{
	public:
		virtual bool lambda() = 0;
		virtual void delta(int, ...) = 0;
};

#endif
