#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
public:
	int maxArea(vector<int> &height)
	{
		int n = height.size();
		int n1 = n-1;

		int max = 0, area;
		int h1, h2, maxh1, maxh2;

		maxh1 = 0;
		for (int i = 0; i < n1; ++i)
		{
			h1 = height[i];
			if (h1 <= maxh1) continue;
			maxh1 = h1;

			maxh2 = 0;
			for (int j = n1; j > i; --j)
			{
				h2 = height[j];
				if (h2 <= maxh2) continue;
				maxh2 = h2;

				area = (j-i) * (h1<=h2 ? h1 : h2);
				if (area > max) max = area;
				if (h2 >= h1) break;
			}
		}

		return max;
	}
};

#endif