#pragma once
#include "Node_list.h"


class List
{

private:
	Node<int> *head;
	Node<int> *tail;
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
};

