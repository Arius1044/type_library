#include "List.h"
#include <iostream>


using namespace std;

template<class Type>
List<Type>::List()
{
	head = NULL;
	tail = NULL;
	count = 0;
}

template<class Type>
List<Type>::~List()
{
	if (head == NULL)
	{
		return;
	}
	Node<Type> *ptr = head;
	while (ptr != NULL)
	{
		head = head->next;
		delete ptr;
		ptr = head;
	}
	count = 0;
}

template<class Type>
void List<Type>::pushBack(Type _data_)
{
	if (head != NULL)
	{
		tail->next = new Node<Type>(_data_);
		tail = tail->next;
		count++;
	}
	else
	{
		head = new Node<Type>(_data_);
		tail = head;
		count++;
	}
}

template<class Type>
void List<Type>::print() const
{
	Node<Type> *ptr = head;
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

template<class Type>
void  List<Type>::pop()
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

	Node<Type> *ptr= head;
	Node<Type> *temp = tail;

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

template<class Type>
void List<Type>::leftpop()
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

	Node<Type> *temp = head;
	head = head->next;
	delete temp;
	count--;

}

template<class Type>
int List<Type>::size() const
{
	return count;
}

template<class Type>
void List<Type>::head_on_tail()
{
	if (head == NULL || head == tail) return;

	swap(head->data, tail->data);


}

template<class Type>
void List<Type>::clear()
{

	while (head != NULL)
	{
		leftpop();
	}
	count = 0;
}

template<class Type>
void List<Type>::remove(Type elem)
{
	Node<Type> *ptr = head;
	Node<Type> *temp = head;

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

template<class Type>
Type&  List<Type>::operator[] (int i) const
{
	Type z = NULL;
	if ((i >= count)||(i<0)) return z;

	Node<Type> *ptr = head;
	for (int j = 0; j < i; j++)
		ptr = ptr->next;
	
	return  ptr->data;
}

template<class Type>
List<Type> List<Type>::operator+ (const List &vector) const
{
	List res(*this);


	if (vector.head != NULL)
		for (int i = 0; i < vector.size(); i++) 
			res.pushBack(vector[i]);
	

	return res;
}

template<class Type>
void List<Type>::operator+= (const List &vector)
{
	
	if (vector.head != NULL)
		for (int i = 0; i < vector.size(); i++)
			pushBack(vector[i]);

}

template<class Type>
List<Type>& List<Type>::operator= (const List &vector)
{
	clear();
	if (vector.head != NULL)
		for (int i = 0; i < vector.size(); i++)
			pushBack(vector[i]);

	return *this;
}

template<class Type>
void List<Type>::insert(Type elem, int i)
{
	if (i>=count) pushBack(elem);
	else
	{
		if (head != NULL)
		{

			Node<Type> *ptr = head;
			for (int j = 0; j < i; j++) ptr = ptr->next;

			Node<Type> *temp = ptr->next;

			ptr->next = new Node<Type>(elem);
			ptr->next->next = temp;
			count++;
		}
		else
		{
			pushBack(elem);
		}
	}
	
}

template<class Type>
void List<Type>::reverse()
{
	for (int i = 0; i < count/2; i++)
	{
		swap((*this)[i],(*this)[count-i-1]);
	}
}

template<class Type>
void List<Type>::sort()
{
	QuickSort(0, count - 1);
}

template<class Type>
void List<Type>::QuickSort(long b, long e)
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
