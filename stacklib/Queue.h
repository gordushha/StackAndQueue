#pragma once
#include "Stack.h"
template<class A>
class TQueue : public TStack<A>
{
protected:
	int head, count;
public:
	TQueue() :TStack<A>() { head = 0; count = 0; };
	TQueue(TQueue& lhs) :TStack<A>(lhs)
	{
		head = lhs.head;
		count = lhs.count;
	};
	TQueue(int _size) :TStack<A>(_size) { head = 0; count = 0; };
	TQueue(const std::initializer_list<A>& list) :TStack<A>(list) { head = 0; this->tail = 0; count = this->size; };
	~TQueue() { head = 0; this->tail = 0; count = 0; this->size = 0; };

	TQueue(TStack<A> _s)
	{
		this->size = _s.size;
		this->arr = new A[this->size];
		this->tail = _s.tail;
		head = 0;
		count = tail;
		for (int i = 0; i < size; i++)
			this->arr[i] = _s.arr[i];
	}

	void push(A elem);
	A pop();

	bool IsFull();
	bool IsEmpty();

	A find_min()
	{
		TQueue<A> t(*this);
		A min = t.pop();
		for (int i = 1; i < count; i++)
		{
			A temp = t.pop();
			if (min > temp)
				min = temp;
		}

		return min;
	}

	friend ostream& operator<<(ostream& ostr, const TQueue<A>& lhs)
	{
		if (lhs.tail == lhs.head)
			for (int i = lhs.head; i < lhs.size; i++)
				ostr << lhs.arr[i] << ' ';
		else
			if (lhs.tail > lhs.head)
				for (int i = lhs.head; i < lhs.tail; i++)
					ostr << lhs.arr[i] << ' ';
			else
			{
				int t = lhs.tail + lhs.head + lhs.head + 1;
				for (int i = lhs.head; i < t; i++)
					ostr << lhs.arr[i % lhs.size] << ' ';
			}
		ostr << endl;
		return ostr;

	};


};

template<class A>
inline void TQueue<A>::push(A elem)
{
	if (this->IsFull())
		throw logic_error("queue full");
	count++;
	this->arr[this->tail] = elem;
	this->tail = (this->tail + 1) % this->size;
}

template<class A>
inline A TQueue<A>::pop()
{
	if (this->IsEmpty())
		throw logic_error("queue empty");
	count--;
	A temp = this->arr[head];
	head = (head + 1) % this->size;
	return temp;
}

template<class A>
inline bool TQueue<A>::IsFull()
{
	if (count == size)
		return true;
	else
		return false;
}

template<class A>
inline bool TQueue<A>::IsEmpty()
{
	if (count == 0)
		return true;
	else
		return false;
}

/*template<class A>
ostream& operator<<(ostream& ostr, const TQueue<A>& lhs)
{
	if (lhs.tail == lhs.head)
		for (int i = lhs.head; i < lhs.size; i++)
			ostr << lhs.arr[i] << ' ';
	else
		if (lhs.tail > lhs.head)
			for (int i = lhs.head; i < lhs.tail; i++)
				ostr << lhs.arr[i] << ' ';
		else
		{
			int t = lhs.tail + lhs.head + lhs.head + 1;
			for (int i = lhs.head; i < t; i++)
				ostr << lhs.arr[i % lhs.size] << ' ';
		}
	ostr << endl;
	return ostr;
}*/

