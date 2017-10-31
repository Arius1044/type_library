#pragma once
#include <iostream>

template <class ANY_TYPE>

struct Node
{

	ANY_TYPE data;
	Node *next;

	Node(int _data_)
	{
		data = _data_;
		next = NULL;
	}
};