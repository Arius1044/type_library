#ifndef D_LIST_H
#define D_LIST_H
#include "Node_doubly_list.h"

template<class Type>

class D_List
{

private:
	D_Node<Type> *head;
	D_Node<Type> *tail;
	int count;


	void QuickSort(long b, long e);

public:
	D_List();
	~D_List();
	void pushBack(Type _data_);
	void print() const;
	void pop();
	void leftpop();
	int size() const;
	void clear();
	void head_on_tail();
	void remove(Type elem);
	Type& operator[] (int i) const;
	D_List operator+ (const D_List &vector);
	D_List& operator= (const D_List &vector);
	void operator+= (const D_List &vector);
	void insert(Type elem, int i);
	void reverse();
	void sort();
};

#endif 