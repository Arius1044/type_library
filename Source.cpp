#include "List.h"
#include "List.cpp"
#include "Doubly_List.h"
#include "Doubly_List.cpp"
#include <iostream>


using namespace std;

int main()
{
	D_List<char> l, l1;

	l.pushBack('a');
	l.pushBack('2');
	l.pushBack('c');
	l.pushBack('4');
	l.pushBack('d');
	l.pushBack('1');
	l.pushBack('z');
	l.pushBack('3');
	l.pushBack('v');
	l.pushBack('5');

	l1.pushBack('Z');
	l1.pushBack('A');
	l1.pushBack('B');
	l1.pushBack('C');
	l1.pushBack('D');
	l1.pushBack('C');
	l1.pushBack('D');
	l1.pushBack('B');
	l1.pushBack('Z');
	l1.pushBack('B');

	cout << "l: \n";
	l.print();
	cout << "\n\npop:";
	l.pop();
	cout << endl;
	l.print();
	cout << "\n\nhead_on_tail:";
	l.head_on_tail();
	cout << endl;
	l.print();
	cout << "\n\ninsert('T', 1):";
	l.insert('T', 1);
	cout << endl;
	l.print();
	cout << "\n\nleftpop:";
	l.leftpop();
	cout << endl;
	l.print();
	cout << "\n\nremove('3'):";
	l.remove('3');
	cout << endl;
	l.print();
	cout << "\n\nreverse:";
	l.reverse();
	cout << endl;
	l.print();
	cout << "\n\nl1:";
	cout << endl;
	l1.print();
	cout << "\n\nl+=l1:";
	l+=l1 ;
	cout << endl;
	l.print();
	cout << "\n\nsort:";
	l.sort();
	cout << endl;
	l.print();
	cout << endl <<"size of l: "<< l.size()<<endl<<endl;
	cout << endl << "l[-5]: " << l[-5] << endl << endl;
	system("pause");
	return 0;
}