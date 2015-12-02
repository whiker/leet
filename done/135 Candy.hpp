#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
public:
	int candy(vector<int> &rate)
	{
		int nChild = rate.size();
		if (nChild <= 0)
			return 0;
		else if (nChild == 1)
			return 1;

		int nChild1 = nChild - 1;
		int i = 0, j, k, n1, n2;
		int sum = 0;

		while (i < nChild1)
		{
			if (rate[i] < rate[i+1])
			{
				for (j = i+1; j < nChild1; j++)
				{
					if (rate[j] >= rate[j+1])
						break;
				}
				n1 = j - i;
				sum += ( ( n1 * (n1+1) ) >> 1 );

				if (j==nChild1 || rate[j]==rate[j+1])
				{
					sum += n1+1;
					i = j+1;
				}
				else
				{
					for (k = j+1; k < nChild1; k++)
					{
						if (rate[k] <= rate[k+1])
							break;
					}
					n2 = k - j;
					sum += ( (n2 * (n2+1)) >> 1);
					sum--;
					if (n2 > n1) n1 = n2;
					sum += n1+1;
					i = k;
				}
			}
			else if (rate[i] > rate[i+1])
			{
				for (j = i+1; j < nChild1; j++)
				{
					if (rate[j] <= rate[j+1])
						break;
				}
				n1 = j-i;
				sum += ( ( n1 * (n1+1) ) >> 1 );
				sum += n1;
				i = j;
			}
			else
			{
				sum++;
				i++;
			}
		}
		if (i == nChild1)
			sum++;

		return sum;
	}
};

#endif