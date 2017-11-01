#include <iostream>

using namespace std;

#include "queue.h"           // підключення шаблон класу

int main()
{
	cout << "Input size of queue " << endl;
	int n;                    // кількість елементів для добавлення
	cin >> n;              
	Queue<char> myQueue(n);   // об'єкт шаблон класу

	myQueue.printQueue();     // друкування черги

	int ct = 0;
	char ch;

	// добавлення елементів у чергу
	cout << "Input queue " << endl;
	while (ct++ < n)
	{
		cin >> ch;
		myQueue.enqueue(ch);
	}
	myQueue.printQueue();    // друкування черги
						    
	myQueue.dequeue();       // видалення елементів з черги


	myQueue.printQueue();    // друкування черги

	system("pause");
	return 0;
}
