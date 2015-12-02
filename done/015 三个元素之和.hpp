#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int> &num)
	{
		const int size  = num.size();
		const int size2 = size - 2;

		int target, sum, i, j, k;
		vector<vector<int>> ret;
		vector<int> tuple(3);

		sort(num.begin(), num.end());

		for (k = 0; k < size2; k++)
		{
			if (k > 0 && num[k] == num[k-1])
				continue;

			target = -num[k];
			i = k+1;
			j = size-1;

			while (i < j)
			{
				sum = num[i] + num[j];
				if (sum == target)
				{
					tuple[0] = num[k];
					tuple[1] = num[i];
					tuple[2] = num[j];
					ret.push_back(tuple);
					j--;
					while (i < j && num[i] == tuple[1])
						i++;
					if (i >= j)
						break;
				}
				else if (sum < target)
					i++;
				else
					j--;
			}
		}

		return ret;
	}
};

#endif