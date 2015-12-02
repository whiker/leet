#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
public:
	void rotate(int nums[], int n, int k)
	{
		k = k % n;
		if (k == 0)
			return;

		reverse(nums, 0, n-1);
		reverse(nums, 0, k-1);
		reverse(nums, k, n-1);
	}

	void reverse(int nums[], int first, int last)
	{
		int t;
		while (first < last)
		{
			t = nums[first];
			nums[first] = nums[last];
			nums[last] = t;
			++first;
			--last;
		}
	}
};

#endif