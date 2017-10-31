#pragma once
#include "Node_list.h"


class List
{

private:
	Node *head;
	Node *tail;
	int count;

public:
	List();
	~List();
	void pushBack(int _data_);
	void print() const;
	void pop();
	void leftpop();
	int size() const;
	void clear();
	void head_on_tail();
	void remove(int elem);
	int& operator[] (int i) const;
	List operator+ (const List &vector) const;
	List& operator= (const List &vector);
	void operator+= (const List &vector);
	void insert(int elem, int i);
};

