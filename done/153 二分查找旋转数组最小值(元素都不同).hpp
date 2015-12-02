#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
public:
	int findMin(vector<int>& v)
	{
		const int size = v.size();
		if (size == 0) return 0;
		if (size == 1) return v[0];

		int low = 0, high = size-1, mid;

		while (low < high)
		{
			if (v[low] < v[high])
				return v[low];
			mid = (low + high) >> 1;

			if (v[mid] > v[low])
				low = mid + 1;
			else if (v[mid] < v[low])
				high = mid;
			else  // mid == low
				return v[low]<v[high] ? v[low] : v[high];
		}

		if (low == high) return v[low];
		return v[mid];
	}
};

#endif