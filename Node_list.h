#pragma once
#include <iostream>


struct Node
{

	int data;
	Node *next;

	Node(int _data_)
	{
		data = _data_;
		next = NULL;
	}
};