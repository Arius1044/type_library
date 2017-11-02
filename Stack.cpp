#include "Stack.h"
#include <iostream>
using namespace std;
// реализация методов шаблона класса STack

// конструктор Стека
template <typename T>
Stack<T>::Stack(int maxSize) :
	size(maxSize) // инициализация константы
{
	stackPtr = new T[size]; // выделить память под стек
	head = 0; // инициализируем текущий элемент нулем;
}

// конструктор копирования
template <typename T>
Stack<T>::Stack(const Stack<T> & otherStack) :
	size(otherStack.getStackSize()) // инициализация константы
{
	stackPtr = new T[size]; // выделить память под новый стек
	head = otherStack.getHead();

	for (int couter = 0; couter < head; couter++)
		stackPtr[couter] = otherStack.getPtr()[couter];
}

// функция деструктора Стека
template <typename T>
Stack<T>::~Stack()
{
	delete[] stackPtr; // удаляем стек
}

// функция добавления элемента в стек
template <typename T>
inline void Stack<T>::push(const T &value)
{
	// проверяем размер стека
	if (head < size) { // номер текущего элемента должен быть меньше размера стека

		stackPtr[head++] = value; // помещаем элемент в стек
	}
	else {
		cout << "Wrong! (head > = size)" << endl;
	}
}

// функция удаления элемента из стека
template <typename T>
inline T Stack<T>::pop()
{
	// проверяем размер стека
	if (head > 0) { // номер текущего элемента должен быть больше 0

		stackPtr[head];// удаляем элемент из стека
	}
	else {
		cout << "Wrong! head < = 0. " << endl;
	}
	return stackPtr;
}

// функция возвращает n-й элемент от вершины стека
template <class T>
inline const T &Stack<T>::Peek(int nom) const
{
	//
	if (nom <= head) {

		return stackPtr[head - nom]; // вернуть n-й элемент стека
	}
	else {
		cout << "Wrong (nom > head)" << endl;
	}
}

// вывод стека на экран
template <typename T>
inline void Stack<T>::printStack()
{
	for (int counter = head - 1; counter >= 0; counter--)
		cout << "|" << stackPtr[counter] << endl;
}

// вернуть размер стека
template <typename T>
inline int Stack<T>::getStackSize() const
{
	return size;
}

// вернуть указатель на стек (для конструктора копирования)
template <typename T>
inline T *Stack<T>::getPtr() const
{
	return stackPtr;
}

// вернуть размер стека
template <typename T>
inline int Stack<T>::getHead() const
{
	return head;
}
