#include "List.h"
#include "Node_list.h"
#include <iostream>


using namespace std;


List::List()
{
	head = NULL;
	tail = NULL;
	count = 0;
}


void List::pushBack(int _data_)
{
	if (head != NULL)
	{
		tail->next = new Node<int>(_data_);
		tail = tail->next;
		count++;
	}
	else
	{
		head = new Node<int>(_data_);
		tail = head;
		count++;
	}
}

void List::print() const
{
	Node<int> *ptr = head;
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

void List::pop()
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

	Node<int> *ptr= head;
	Node<int> *temp = tail;

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



void List::leftpop()
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

	Node<int> *temp = head;
	head = head->next;
	delete temp;
	count--;

}

int List::size() const
{
	return count;
}

void List::head_on_tail()
{
	if (head == NULL || head == tail) return;

	swap(head->data, tail->data);


}

void List::clear()
{

	while (head != NULL)
	{
		leftpop();
	}
	count = 0;
}

void List::remove(int elem)
{
	Node<int> *ptr = head;
	Node<int> *temp = head;

	if (ptr == NULL)
		return;
	else if ((head->data == elem)&&(tail == head))
	{
		delete ptr, head;
		tail = NULL;
		head = NULL;
		count--;
		return;
	}
	else if (head->data == elem)
	{
		leftpop();
		return;
	}
	else
	{
		while ((ptr!=NULL)&&(ptr->data != elem))
		{
			temp = ptr;
			ptr = ptr->next;

		}
		if (ptr == NULL)
		{
			return;
		}
		else if ((ptr->data == elem) || (ptr->next == NULL)) pop();
		else
		{
			temp->next = ptr->next;
			delete ptr;
			count--;
		}
	}
}

List::~List()
{
	if (head == NULL)
	{
		return;
	}
	Node<int> *ptr = head;
	while (ptr != NULL)
	{
		head = head->next;
		delete ptr;
		ptr = head;
	}
	count = 0;
}
