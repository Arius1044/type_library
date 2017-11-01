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

List::~List()
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
	count = 0;
}

void List::pushBack(int _data_)
{
	if (head != NULL)
	{
		tail->next = new Node (_data_);
		tail = tail->next;
		count++;
	}
	else
	{
		head = new Node (_data_);
		tail = head;
		count++;
	}
}

void List::print() const
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

	Node *ptr= head;
	Node *temp = tail;

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

	Node *temp = head;
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
	Node *ptr = head;
	Node *temp = head;

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

		
		if ((ptr == tail) || (ptr->next == NULL)) pop();
		else
		{
			temp->next = ptr->next;
			delete ptr;
			count--;
		}
	}
}

int&  List::operator[] (int i) const
{
	int z = -1;
	if ((i >= count)||(i<0)) return z;

	Node *ptr = head;
	for (int j = 0; j < i; j++)
		ptr = ptr->next;
	
	return  ptr->data;
}


List List::operator+ (const List &vector) const
{
	List res(*this);


	if (vector.head != NULL)
		for (int i = 0; i < vector.size(); i++) 
			res.pushBack(vector[i]);
	

	return res;
}

void List::operator+= (const List &vector)
{
	
	if (vector.head != NULL)
		for (int i = 0; i < vector.size(); i++)
			pushBack(vector[i]);

}

List& List::operator= (const List &vector)
{
	clear();
	if (vector.head != NULL)
		for (int i = 0; i < vector.size(); i++)
			pushBack(vector[i]);

	return *this;
}

void List::insert(int elem, int i)
{
	if (i>=count) pushBack(elem);
	else
	{
		if (head != NULL)
		{

			Node *ptr = head;
			for (int j = 0; j < i; j++) ptr = ptr->next;

			Node *temp = ptr->next;

			ptr->next = new Node(elem);
			ptr->next->next = temp;
			count++;
		}
		else
		{
			pushBack(elem);
		}
	}
	
}

void List::reverse()
{
	for (int i = 0; i < count/2; i++)
	{
		swap((*this)[i],(*this)[count-i-1]);
	}
}

void List::sort()
{
	QuickSort(0, count - 1);
}

void List::QuickSort(long b, long e)
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