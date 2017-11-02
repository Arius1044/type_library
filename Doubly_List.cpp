#include "Doubly_List.h"
#include <iostream>



using namespace std;

template<class Type>
D_List<Type>::D_List()
{
	head = NULL;
	tail = NULL;
	count = 0;
}

template<class Type>
D_List<Type>::~D_List()
{
	if (head == NULL)
	{
		return;
	}
	D_Node<Type> *ptr = head;
	while (ptr != NULL)
	{
		head = head->next;
		delete ptr;
		ptr = head;
	}
	count = 0;

}

template<class Type>
void D_List<Type>::pushBack(Type _data_)
{
	D_Node<Type> *temp = new D_Node<Type>(_data_);

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

template<class Type>
void D_List<Type>::print() const
{
	D_Node<Type> *ptr = head;
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
void D_List<Type>::pop()
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

	D_Node<Type> *temp = tail;
	tail = temp->prev;
	tail->next = NULL;
	delete temp ;
	count--;
}

template<class Type>
void D_List<Type>::leftpop()
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

	D_Node<Type> *temp = head;
	head = head->next;
	delete temp;
	count--;
}

template<class Type>
int D_List<Type>::size() const
{
	return count;
}

template<class Type>
void D_List<Type>::clear()
{
	while (head != NULL)
		pop();
	count = 0;
}

template<class Type>
void D_List<Type>::head_on_tail()
{
	if (head == NULL || head == tail) return;

	swap(head->data, tail->data);
}

template<class Type>
void D_List<Type>::remove(Type elem)
{
	D_Node<Type> *ptr = head;
	D_Node<Type> *temp = head;

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

template<class Type>
Type&  D_List<Type>::operator[] (int i) const
{
	Type z = NULL;
	if ((i >= count) || (i<=-count)) return z;

	D_Node<Type> *ptr = head;
	D_Node<Type> *ptr2 = tail;
	if (i >= 0)
	{
		for (int j = 0; j < i; j++)
			ptr = ptr->next;
		return  ptr->data;
	}
	else
	{
		i *= -1;
		for (int j = i-2; j >= 0; j--)
			ptr2 = ptr2->prev;
		return  ptr2->data;
	}
	
}

template<class Type>
D_List<Type> D_List<Type>::operator+ (const D_List &vector)
{
	D_List res(*this);


	if (vector.head != NULL)
		for (int i = 0; i < vector.size(); i++)
			res.pushBack(vector[i]);


	return res;
}

template<class Type>
void D_List<Type>::operator+= (const D_List &vector)
{

	if (vector.head != NULL)
		for (int i = 0; i < vector.size(); i++)
			pushBack(vector[i]);

}

template<class Type>
D_List<Type>& D_List<Type>::operator= (const D_List &vector)
{
	clear();
	if (vector.head != NULL)
		for (int i = 0; i < vector.size(); i++)
			pushBack(vector[i]);

	return *this;
}

template<class Type>
void D_List<Type>::insert(Type elem, int i)
{
	if (i >= count) pushBack(elem);
	else
	{
		if (head != NULL)
		{

			D_Node<Type> *ptr = head;
			for (int j = 0; j < i; j++) ptr = ptr->next;

			D_Node<Type> *temp = ptr->next;

			ptr->next = new D_Node<Type>(elem);
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

template<class Type>
void D_List<Type>::reverse()
{
	for (int i = 0; i < count / 2; i++)
	{
		swap((*this)[i], (*this)[count - i - 1]);
	}
}

template<class Type>
void D_List<Type>::sort()
{
	QuickSort(0, count - 1);
}

template<class Type>
void D_List<Type>::QuickSort(long b, long e)
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