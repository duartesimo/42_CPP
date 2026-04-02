#ifndef BASE_HPP
#define BASE_HPP

class Base
{
	//virtual destructor ensure proper cleanup of derived objects when deleted through a Base* pointer
	public:
		virtual ~Base();
};

#endif
