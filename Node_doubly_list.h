#include <iostream>
template <typename Type>

struct D_Node
{
	Type data;
	D_Node *next, *prev;

	D_Node(Type _data_)
	{
		data = _data_;
		next = NULL;
	}
};