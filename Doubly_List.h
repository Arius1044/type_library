#pragma once
#include <iostream>
#include "Node_doubly_list.h"


class D_List
{

private:
	Node *head;
	Node *tail;
	int count;

public:
	D_List();
	~D_List();
	void pushBack(int _data_);
	void print() const;
	void pop();
	void leftpop();
	int size() const;
	void clear();
};

