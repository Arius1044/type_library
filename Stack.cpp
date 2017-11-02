#include "Stack.h"

using namespace std;

template<typename Type>
Stack<Type>::Stack()
{

}

template<typename Type>
Stack<Type>::~Stack()
{
}

template<typename Type>
void Stack<Type>::pushBack(Type elem)
{
	stack.pushBack(elem);
}

template<typename Type>
Type Stack<Type>::pop()
{
	Type temp = stack[-1];
	stack.pop();
	return temp;
}

template<typename Type>
void Stack<Type>::print()
{
	stack.print();
}

template<typename Type>
int Stack<Type>::size() const
{
	return stack.size();
}