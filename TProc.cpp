#include "stdafx.h"
#include "TProc.h"
#include <stdio.h>


TProc::TProc(int max)
{
	MAX_RAND = max;
}

void TProc::InsCrit(int c)
{
	crit = c;
}

bool TProc::TaskProc()
{
	int result = rand() % MAX_RAND;
	if (result < crit)
	{
		tasknumber++;
		IsOcc = 0;
	}
	else
		IsOcc = 1;
	return (result < crit);
}

int TProc::GetNum()
{
	return tasknumber;
}