#include "Doubly_List.h"
#include "Node_doubly_list.h"
#include <iostream>


using namespace std;


D_List::D_List()
{
	head = NULL;
	tail = NULL;
	count = 0;
}


D_List::~D_List()
{
	if (head == NULL)
	{
		return;
	}
	D_Node *ptr = head;
	while (ptr != NULL)
	{
		head = head->next;
		delete ptr;
		ptr = head;
	}
	count = 0;

}

void D_List::pushBack(int _data_)
{
	D_Node *temp = new D_Node(_data_);

	if (head != NULL)
	{
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
		count++;
	}
	else
	{
		temp->prev = NULL;
		head = tail = temp;
		count++;
	}

}

void D_List::print() const
{
	D_Node *ptr = head;
	if (ptr == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}

	while (ptr != NULL)
	{
		cout << ptr->data << "  ";
		ptr = ptr->next;
	}
}

void D_List::pop()
{
	if (head == NULL)
		return;
	if (tail == head)
	{
		delete head;
		tail = NULL;
		head = NULL;
		count--;
		return;
	}

	D_Node *ptr = head;
	D_Node *temp = tail;

	while (ptr != tail)
	{
		temp = ptr;
		ptr = ptr->next;
	}



	tail = temp;
	delete ptr;
	tail->next = NULL;

	count--;
}

void D_List::leftpop()
{
	if (head == NULL)
		return;
	if (tail == head)
	{
		delete head;
		tail = NULL;
		head = NULL;
		count--;

		return;
	}

	D_Node *temp = head;
	head = head->next;
	delete temp;
	count--;
}

int D_List::size() const
{
	return count;
}

void D_List::clear()
{
	while (head != NULL)
		pop();
	count = 0;
}

void D_List::head_on_tail()
{
	if (head == NULL || head == tail) return;

	swap(head->data, tail->data);
}

void D_List::remove(int elem)
{
	D_Node *ptr = head;
	D_Node *temp = head;

	if (ptr == NULL)
		return;
	else if (head->data == elem)
	{
		leftpop();
		return;
	}
	else
	{
		int counter = 0;
		while (ptr->data != elem)
		{
			temp = ptr;
			ptr = ptr->next;
			counter++;
			if (counter == count)
			{
				return;
			}
		}
		if (ptr == tail) pop();
		else
		{
			temp->next = ptr->next;
			temp->prev = ptr->prev;
			delete ptr;
			count--;
		}
	}
}

int&  D_List::operator[] (int i) const
{
	int z = -1;
	if ((i >= count) || (i<0)) return z;

	D_Node *ptr = head;
	for (int j = 0; j < i; j++)
		ptr = ptr->next;

	return  ptr->data;
}

D_List D_List::operator+ (const D_List &vector) const
{
	D_List res(*this);


	if (vector.head != NULL)
		for (int i = 0; i < vector.size(); i++)
			res.pushBack(vector[i]);


	return res;
}

void D_List::operator+= (const D_List &vector)
{

	if (vector.head != NULL)
		for (int i = 0; i < vector.size(); i++)
			pushBack(vector[i]);

}

D_List& D_List::operator= (const D_List &vector)
{
	clear();
	if (vector.head != NULL)
		for (int i = 0; i < vector.size(); i++)
			pushBack(vector[i]);

	return *this;
}

void D_List::insert(int elem, int i)
{
	if (i >= count) pushBack(elem);
	else
	{
		if (head != NULL)
		{

			D_Node *ptr = head;
			for (int j = 0; j < i; j++) ptr = ptr->next;

			D_Node *temp = ptr->next;

			ptr->next = new D_Node(elem);
			ptr->next->next = temp;
			ptr->next->prev = temp->prev;
			count++;
		}
		else
		{
			pushBack(elem);
		}
	}

}

void D_List::reverse()
{
	for (int i = 0; i < count / 2; i++)
	{
		swap((*this)[i], (*this)[count - i - 1]);
	}
}

void D_List::sort()
{
	QuickSort(0, count - 1);
}

void D_List::QuickSort(long b, long e)
{
	long left = b, right = e, m = (*this)[int((right + left) / 2)];

	while (left <= right)
	{
		while ((*this)[left] < m) left++;
		while ((*this)[right] > m) right--;
		if (left <= right) swap((*this)[left++], (*this)[right--]);
	}
	if (left < e) QuickSort(left, e);
	if (right > b) QuickSort(b, right);
}