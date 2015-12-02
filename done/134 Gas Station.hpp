#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
	{
		int n = gas.size(), i;
		if (n < 0) return -1;

		for (i = 0; i < n; i++)
			gas[i] -= cost[i];

		int maxsum, presum;
		int from, prefrom, limit;
		maxsum = presum = gas[0];
		from = prefrom = 0;
		limit = n;
		bool flag = false;

		for (i = 1; i < limit; )
		{
			if (presum <= 0)
			{
				presum = gas[i];
				prefrom = i;
			}
			else
				presum += gas[i];

			if (presum > maxsum)
			{
				maxsum = presum;
				from = prefrom;
			}

			i++;
			if (i == limit)
			{
				if (flag || presum <= 0)
					break;
				flag = true;
				limit = prefrom;
				i = 0;
			}
		}

		int sum = 0;
		for (i = from; i < n; i++)
		{
			sum += gas[i];
			if (sum < 0)
				return -1;
		}
		for (i = 0; i < from; i++)
		{
			sum += gas[i];
			if (sum < 0)
				return -1;
		}

		return from;
	}
};

#endif