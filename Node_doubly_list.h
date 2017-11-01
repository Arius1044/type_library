#pragma once
#include <iostream>
struct D_Node
{
	int data;
	D_Node *next, *prev;

	D_Node(int _data_)
	{
		data = _data_;
		next = NULL;
	}
};