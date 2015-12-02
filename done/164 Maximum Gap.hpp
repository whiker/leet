#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
public:
	int maximumGap(vector<int> &num)
	{
		int n = num.size();
		if (n < 2) return 0;

		int min, max, diff;
		min = max = num[0];
		for (int i = num.size()-1; i > 0; i--)
		{
			if (num[i] > max)
				max = num[i];
			else if (num[i] < min)
				min = num[i];
		}
		diff = max - min;

		if (diff < n)
		{
			int *bucket = new int[n];
			memset(bucket, 0, n<<2);
			for (int i = 0; i < n; i++)
				bucket[num[i]-min] = 1;

			int prev = 0, max_gap = 0;
			for (int i = 1; i <= diff; i++)
			{
				if (bucket[i])
				{
					if (i-prev > max_gap)
						max_gap = i-prev;
					prev = i;
				}
			}
			delete[] bucket;
			return max_gap;
		}
		else
		{
			int *bucket_min = new int[n];
			int *bucket_max = new int[n];
			for (int i = 0; i < n; i++)
				bucket_min[i] = bucket_max[i] = -1;

			double d = n / (double)diff;
			int ind, t;

			for (int i = 0; i < n; i++)
			{
				t = num[i];
				ind = (t - min) * d;
				if (ind >= n) ind = n-1;

				if (bucket_min[ind] == -1 || t < bucket_min[ind])
					bucket_min[ind] = t;

				if (bucket_max[ind] == -1 || t > bucket_max[ind])
					bucket_max[ind] = t;
			}

			int prev_max = bucket_max[0];
			int max_gap = 0;

			for (int i = 1; i < n; i++)
			{
				if (bucket_min[i] >= 0)
				{
					if (bucket_min[i] - prev_max > max_gap)
						max_gap = bucket_min[i] - prev_max;
					prev_max = bucket_max[i];
				}
			}

			delete[] bucket_min, bucket_max;
			return max_gap;
		}
	}
};

#endif