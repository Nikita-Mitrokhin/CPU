#include "stdafx.h"
#include "TFlow.h"



bool TFlow::TaskGen()
{
	return (rand() % MAX_RAND < crit);
}

void TFlow::InsCrit(int c)
{
	crit = c;
}

TFlow::TFlow(int max)
{
	MAX_RAND = max;
}