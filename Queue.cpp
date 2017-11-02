#include "Queue.h"

using namespace std;

template<typename Type>
Queue<Type>::Queue()
{

}

template<typename Type>
Queue<Type>::~Queue()
{
}

template<typename Type>
void Queue<Type>::pushBack(Type elem)
{
	queue.pushBack(elem);
}

template<typename Type>
Type Queue<Type>::pop()
{
	Type temp = queue[0];
	queue.leftpop();
	return temp;
}

template<typename Type>
void Queue<Type>::print()
{
	int size = queue.size();
	for (int i = 0; i < size; i++)
	{
		if (i != size - 1)
			cout << queue[-i - 1] << " ";
		else cout << queue[0];
	}
}

template<typename Type>
int Queue<Type>::size() const
{
	return queue.size();
}