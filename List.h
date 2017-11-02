#ifndef LIST_H
#define LIST_H
#include "Node_list.h"


template<class Type>
class List
{

private:
	Node<Type> *head;
	Node<Type> *tail;
	int count;

	void QuickSort(long b, long e);

public:
	List();
	~List();
	void pushBack(Type _data_);
	void print() const;
	void pop();
	void leftpop();
	int size() const;
	void clear();
	void head_on_tail();
	void remove(Type elem);
	Type& operator[] (int i) const;
	List operator+ (const List &vector) const;
	List& operator= (const List &vector);
	void operator+= (const List &vector);
	void insert(Type elem, int i);
	void reverse();
	void sort();
};


#endif 