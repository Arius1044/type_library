#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List c;
	c.pushBack(10);
	c.pushBack(100);
	c.pushBack(-10);
	c.pushBack(20);
	c.pushBack(35);
	c.pushBack(41);
	c.pushBack(90);
	c.print();
	cout << "\n\n";
	c.head_on_tail();
	c.print();
	cout << "\n\n";
	c.leftpop();
	c.print();
	cout << "\n\n";
	c.pop();
	c.print();
	cout << "\n\n";
	system("pause");
	return 0;
}