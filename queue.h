#ifndef __QUEUE_H__
#define __QUEUE_H__

const int MaxQueueSize = 1000;

template <class T>
class TQueue
{
	T *pMem;
	int size;
	int top;
	int count;
	TQueue(const TQueue &st) {}
	TQueue& operator=(const TQueue &st) {}
public:
	TQueue(int _size)
	{
		size = _size;
		top = -1;
		count = 0;
		if ((size < 1) || (size > MaxQueueSize))
			throw "Error";
		pMem = new T[size];
	}
	bool empty() const
	{
		return count == 0;
	}
	bool full() const
	{
		return count == size;
	}
	void push(T val)
	{
		if (full())
			throw "Error";
		top = (top + 1) % size;
		count++;
		pMem[top] = val;
	}
	int countQueue() const
	{
		return count;
	}
	T pop()
	{
		if (empty())
			throw "Error";
		count--;
		return pMem[(size + top - count) % size];
	}
	T getBottom() const
	{
		return pMem[(size + 1 + top - count) % size];
	}
	~TQueue()
	{
		delete[] pMem;
	}
};
#endif