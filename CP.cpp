#include "stdafx.h"
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include "TFlow.h"
#include "TProc.h"
#include<locale.h>
#include "TQueue.h"
#pragma warning(disable : 4996)
#define MAX_RANDOM 100
#define PRINT_TICKS 20


int main()
{
	int ignored = 0, pass = 0;
	int pc, fc;
	TQueue q(3);
	TProc p(MAX_RANDOM);
	TFlow f(MAX_RANDOM);
	int ticks;
	int i, j = 0;
	srand(time(NULL));




	printf("Enter the number of cycles \n");
	do{
		scanf("%d", &ticks);
	} while (ticks <= 0);

	printf("Enter the critical value of the processor \n");
	do{
		scanf("%d", &pc);
	} while ((pc <= 0) || (pc >= MAX_RANDOM));
	p.InsCrit(pc);

	printf("Enter the critical value of the tasks\n");
	do{
		scanf("%d", &fc);
	} while ((fc <= 0) || (fc >= MAX_RANDOM));
	f.InsCrit(fc);



	for (i = 1; i <= ticks; i++)
	{
		if (f.TaskGen())
		{
			j++;
			printf(ticks< PRINT_TICKS ? " The task came \n" : "");
			if (q.IsFull())
			{
				printf(ticks< PRINT_TICKS ? "The task ignored\n" : "");
				++ignored;
			}
			else
			{
				printf(ticks<PRINT_TICKS ? "The task queued \n" : "");
				q.Put(1);
			}
		}
		if (p.IsOcc)
		{
			printf(ticks<PRINT_TICKS ? " The processor continues to process the last task \n" : "");
			if (p.TaskProc())
				printf(ticks<PRINT_TICKS ? " The processor has processed the task \n" : "");
		}
		else if (!q.IsEmpty())
		{
			printf(ticks<PRINT_TICKS ? " The processor has started processing a new task \n" : "");
			q.Push();
			if (p.TaskProc())
				printf(ticks<PRINT_TICKS ? " The processor has treated the task \n" : "");
		}
		else
		{
			printf(ticks<PRINT_TICKS ? " The processor is idle \n" : "");
			pass++;
		}
	}
	printf("tasks treated: %d\n", p.GetNum());
	int fl = 0;
	double mg = pass, mc = p.GetNum(), mv = ignored;
	while (!q.IsEmpty()) { fl++, q.Push(); }
	printf("Task in queue: %d\n", fl);
	printf("tasks received: %d\n", j);
	printf("The percentage of downtime: %f\n", (mg / ticks) * 100);
	if (mc != 0)
		printf("Average processing time: %f\n", (ticks - pass) / mc);
	else printf("The tasks are not treated\n");
	printf("The percentage of ignored problems: %f\n", (mv / ticks) * 100);
	return 0;

}

