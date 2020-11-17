#ifndef __CLUSTER_H__
#define __CLUSTER_H__

#include "queue.h"
#include "tasks.h"
#include <iostream>

class statistics
{
	int createdTasks;
	int countPerformedTasks;
	int countQueueTasks;
	double averageLoad;
	int tact;
public:
	statistics()
	{
		countQueueTasks = 0;
		countPerformedTasks = 0;
		createdTasks = 0;
		tact = 0;
	}
	void create()
	{
		createdTasks++;
	}
	void addPerformed(int tasks)
	{
		if (tasks < 0)
			throw "Error";
		countPerformedTasks += tasks;
	}
	void inQueue(int tasks)
	{
		if (tasks < 0)
			throw "Error";
		countQueueTasks = tasks;
	}
	void congestion(double x)
	{
		if (x < 0)
			throw "Error";
		averageLoad += x;
	}
	void countTacts(int t)
	{
		tact += t;
	}
	void print() const
	{
		std::cout << "Completed tasks: " << countPerformedTasks << std::endl;
		std::cout << "Created Tasks: " << createdTasks << std::endl;
		std::cout << "Tasks in line: " << countQueueTasks << std::endl;
		if (tact != 0)
			std::cout << "Average Load: " << averageLoad/tact <<std::endl;
	}
};

class cluster
{
	int processors;
	int freeProcessors;
	listTask performeTasks;
	statistics stat;
	TQueue <Task> q;
public:
	cluster(int pr):q(MaxQueueSize)
	{
		if (pr < 1)
			throw "Error";
		processors = pr;
		freeProcessors = pr;
	}
	void doTacts(int tacts);
	void printStatistic()
	{
		stat.print();
	}
};
#endif
