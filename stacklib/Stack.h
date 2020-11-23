#pragma once
#include <iostream>
//#include "Queue.h"
using namespace std;
template<class A>
class TStack
{
protected:
	A* arr;
	int size;
	int tail;
public:
	TStack();
	TStack(const TStack& other);
	~TStack();
	TStack(int _size);

	bool IsFull();
	bool IsEmpty();

	//TQueue<A> transform();

	TStack(const initializer_list<A>& list) : TStack(list.size())
	{
		int count = 0;
		for (auto& element : list)
		{
			this->arr[count] = element;
			++count;
		}
		tail = size;
	};

	void push(A elem);
	A pop();

	A find_min()
	{
		A temp = arr[0];
		for (int i = 1; i < tail; i++)
			if (arr[i] < temp)
				temp = arr[i];
		return temp;
	}

	A find(A elem)
	{
		A pos = -1;
		for (int i = 0; i < tail; i++)
			if (arr[i] == elem)
			{
				pos = i;
				return pos;
			}
		return pos;
	}

	friend ostream& operator<<(ostream& ostr, const TStack<A>& lhs)
	{
		for (int i = 0; i < lhs.tail; i++)
			ostr << lhs.arr[i] << ' ';
		ostr << endl;
		return ostr;
	};

	template<class B>
	friend class TQueue;
};

template<class A>
inline TStack<A>::TStack()
{
	arr = new A[1];
	size = 1;
	tail = 0;
	arr[0] = 0;
}

template<class A>
inline TStack<A>::TStack(const TStack& other)
{
	this->size = other.size;
	this->arr = new A[size];
	this->tail = other.tail;
	for (int i = 0; i < size; i++)
		this->arr[i] = other.arr[i];
}

template<class A>
inline TStack<A>::~TStack()
{
	delete[] arr;
	size = 0;
	tail = 0;
}

template<class A>
inline TStack<A>::TStack(int _size)
{
	if (_size < 0) throw logic_error("invalid_argument");
	size = _size;
	arr = new A[size];

	tail = 0;
	for (int i = 0; i < size; i++)
		arr[i] = 0;
}

template<class A>
inline bool TStack<A>::IsFull()
{
	if (tail == size)
		return true;
	else
		return false;
}

template<class A>
inline bool TStack<A>::IsEmpty()
{
	if (tail == 0)
		return true;
	else
		return false;
}





/*template<class A>
inline TStack<A>::TStack(const std::initializer_list<A>& list) : TStack(list.size())
{
	int count = 0;
	for (auto& element : list)
	{
		this->arr[count] = element;
		++count;
	}
	tail = size;
}*/

template<class A>
inline void TStack<A>::push(A elem)
{
	if (tail >= size) throw logic_error("out of range");
	arr[tail] = elem;
	tail++;
}

template<class A>
inline A TStack<A>::pop()
{
	if (tail == 0) throw logic_error("stack empty");
	A temp = arr[tail - 1];
	tail--;
	return temp;
}

/*template<class A>
ostream& operator<<(ostream& ostr, const TStack<A>& lhs)
{
	for (int i = 0; i < lhs.tail; i++)
		ostr << lhs.arr[i] << ' ';
	ostr << endl;
	return ostr;
}*/

