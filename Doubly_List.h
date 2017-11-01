#pragma once
#include <iostream>
#include "Node_doubly_list.h"


class D_List
{

private:
	D_Node *head;
	D_Node *tail;
	int count;


	void QuickSort(long b, long e);

public:
	D_List();
	~D_List();
	void pushBack(int _data_);
	void print() const;
	void pop();
	void leftpop();
	int size() const;
	void clear();
	void head_on_tail();
	void remove(int elem);
	int& operator[] (int i) const;
	D_List operator+ (const D_List &vector) const;
	D_List& operator= (const D_List &vector);
	void operator+= (const D_List &vector);
	void insert(int elem, int i);
	void reverse();
	void sort();
};

