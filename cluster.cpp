#include "cluster.h"

void cluster::doTacts(int tacts)
{
	if (tacts < 1)
		throw "Error";
	for (int i = 0; i < tacts; i++)
	{
		if (rand() % 100 > 50 + rand() % 51)
		{
			Task temp;
			temp.setProcessors(processors);
			q.push(temp);
			stat.create();
		}
		while ((!q.empty()))
		{
			Task temp = q.getBottom();
			if (temp.countProcessors() <= freeProcessors)
			{
				performeTasks.AddNewTask(temp);
				q.pop();
				freeProcessors -= temp.countProcessors();
			}
			else
				break;
		}
		performeTasks.performe();
		int temp = performeTasks.countTasks();
		freeProcessors += performeTasks.DeletePerformedTask();
		temp -= performeTasks.countTasks();
		stat.addPerformed(temp);
		stat.inQueue(q.countQueue());
		stat.congestion(100*(processors - freeProcessors) / processors);
	}
	stat.countTacts(tacts);
}