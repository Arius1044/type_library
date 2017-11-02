#ifndef STACK_H
#define STACK_H

#include "Doubly_List.h"
template<typename Type>
class Stack
{
private:
	D_List<Type> stack;
public:
	Stack();
	~Stack();

	void pushBack(Type elem);
	Type pop();
	void print();
	int size() const;
};

#endif 