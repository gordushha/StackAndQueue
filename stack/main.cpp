#include "Stack.h"
#include "Queue.h"
#include <string> 

int main()
{
	TStack<int> a({ 5, 10, 22 });
	for (int i = 0; i < 3; i++)
		cout << a.pop() << ' ';

	cout << endl;


	TStack<int> b({ 1,2,3,4,5 });
	cout << b << endl;


	TQueue<int> c({ 4,5,6,7,8 });

	cout << c << endl;

	c.pop();
	c.pop();

	cout << c << endl;

	c.push(666);

	cout << c << endl;

	TStack<int> d(a);

	return 0;
}