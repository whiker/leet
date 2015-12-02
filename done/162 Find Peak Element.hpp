#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
public:
	int findPeakElement(const vector<int> &num)
	{
		int low = 0, high = num.size()-1, mid;

		while (low != high)
		{
			mid = (low + high) / 2;
			if (num[mid] > num[mid+1])
				high = mid;
			else
				low = mid + 1;
		}

		return low;
	}
};

#endif