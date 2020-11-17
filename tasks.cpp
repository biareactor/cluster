#include "tasks.h"

void listTask::AddNewTask(const Task &t)
{
	Link *p = new Link;
	p->data = t;
	p->pNext = nullptr;
	if (size != 0)
	{
		int i = 0;
		Link *pp = pFirst;
		Link *ppp = nullptr;
		for (i = 0; i < size; i++)
		{
			if (p->data < pp->data)
			{
				if (ppp != nullptr)
					ppp->pNext = p;
				else
					pFirst = p;
				p->pNext = pp;
				break;
			}
			ppp = pp;
			pp = pp->pNext;
		}
		if (i == size)
			ppp->pNext = p;
	}
	else pFirst = p;
	size++;
}

int listTask::DeletePerformedTask()
{
	int k = 0;
	int s = size;
	for (int i = 0; i < s; i++)
	{
		Link *p = pFirst;
		if (!(p->data.isPerformed()))
		{
			break;
		}
		else
		{
			size--;
			k += p->data.countProcessors();
			pFirst = p->pNext;
			delete p;
		}
	}
	return k;
}
void listTask::performe()
{
	Link *p = pFirst;
	for (int i = 0; i < size; i++)
	{
		p->data.performeTact();
		p = p->pNext;
	}
}

listTask::~listTask()
{
	while (pFirst != nullptr)
	{
		Link *p = pFirst;
		pFirst = p->pNext;
		delete p;
	}
}