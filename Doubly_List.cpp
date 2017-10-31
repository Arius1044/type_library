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
	Node *ptr = head;
	while (ptr != NULL)
	{
		head = head->next;
		delete ptr;
		ptr = head;
	}

}

void D_List::pushBack(int _data_)
{
	Node *temp = new Node;
	temp->next = NULL;
	temp->data = _data_;
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
	}
}

void D_List::print() const
{
	Node *ptr = head;
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
		return;
	}
	Node *temp = tail;
	tail = tail->prev;
	delete temp;
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
		return;
	}

	Node *temp = head;
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
