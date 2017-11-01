#ifndef QUEUE_H
#define QUEUE_H

#include <cassert>

template<typename T>
class Queue
{
private:
	T *queuePtr;     // вказівник на чергу
	const int size;  // максимальна кількість елементів
	int begin,       // початок черги
		end;           // кінець черги
	int elemCT;      // лічильник елементів
public:
	Queue(int =100);               // конструктор
	~Queue();                      // деструктор

	void enqueue(const T &);       // добавити елемент в чергу
	T dequeue();                   // видалити елемент з черги
	void printQueue();
};

// реалізація методів шаблона класса Queue

// конструктор 
template<typename T>
Queue<T>::Queue(int sizeQueue) :size(sizeQueue), begin(0), end(0), elemCT(0)
{
	// додаткова позиція яка відрізняє кінець і початок черги
	queuePtr = new T[size + 1];
}

// деструктор класса Queue
template<typename T>
Queue<T>::~Queue()
{
	delete[] queuePtr;
}

// добавлення елемента в чергу
template<typename T>
void Queue<T>::enqueue(const T &newElem)
{
	// перевіряє чи є вільне місце
	assert(elemCT < size);

	// заповнення з 0 індекса!
	queuePtr[end++] = newElem;

	elemCT++;

	// перевірка кругового заповнення черги
	if (end > size)
		end -= size + 1;     // повертаємо end на початок черги
}

// видалення елемента з черги
template<typename T>
T Queue<T>::dequeue()
{
	// перевірка чи є в черзі елементи
	assert(elemCT > 0);

	T returnValue = queuePtr[begin++];
	elemCT--;

	// перевірка кругового заповненння
	if (begin > size)
		begin -= size + 1; // повернення begin на початок черги

	return returnValue;
}

// друкування черги
template<typename T>
void Queue<T>::printQueue()
{
	cout << "Queue: ";

	// перевірка на наявність елементів
	if (end == 0 && begin == 0)
		cout << " empty\n";
	else
	{
		for (int i = end; i >= begin; i--)
			cout << queuePtr[i] << " ";
		cout << endl;
	}
}

#endif // QUEUE_H
