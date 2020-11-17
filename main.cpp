#include <iostream>
#include "queue.h"
#include "tasks.h"
#include "cluster.h"

using namespace std;

int main()
{
	srand(time(NULL));
	int a;
	int processors;
	int tact;
	try {
		cout << "Enter the number of processors: ";
		cin >> processors;
		cluster b(processors);
		cout << "Enter the number of tact: ";
		cin >> tact;
		b.doTacts(tact);
		cout << "Statistics: ";
		b.printStatistic();
	}
	catch(const char* s)
	{
		cout << s;
	}
	cin >> a;
}