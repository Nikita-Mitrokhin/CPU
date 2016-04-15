#pragma once
#include <stdlib.h>
#include <time.h>


class TFlow
{
	int MAX_RAND;

public:
	TFlow(int max = 100);
	int  crit = 100;
	void InsCrit(int c);
	bool TaskGen();
};