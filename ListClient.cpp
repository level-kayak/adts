#include <iostream>
#include "List.h"

using namespace std;

int main()
{

 List L1, L2;
 
	L1.insert(5,1);
	L1.insert(6,2);
	L1.insert(7,2);
	L1.insert(8,3);
	L1.insert(9,3);
	L1.insert(4,4);
	L1.remove(1);
	cout << L1.get(4) << endl << L1.size() << endl;
	L1.display();
	L1.~List();
L1.display();

 //Do some stuff with L1, L2, ...
 // ...

}
