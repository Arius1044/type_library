#ifndef QUEUE_H
#define QUEUE_H

#include "Doubly_List.h"
template<typename Type>
class Queue
{
private:
	D_List<Type> queue;
public:
	Queue();               
	~Queue();             

	void pushBack(Type elem);    
	Type pop();                  
	void print();
	int size() const;
};

#endif 