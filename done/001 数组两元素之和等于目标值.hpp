#include "util.h"

class Solution
{
public:
	vector<int> twoSum(vector<int> &nums, int T)
	{
		vector<int> ret(2);
		int n = nums.size();

		unordered_map<int, int> ind_map;
		for (int i = 0; i < n; i++)
		{
			if (ind_map[nums[i]])
			{
				ret[0] = ind_map[nums[i]];
				ret[1] = i + 1;
				return ret;
			}
			else
				ind_map[T-nums[i]] = i+1;
		}

		return ret;
	}
};