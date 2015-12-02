#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
public:
	int divide(int dividend, int divisor)
	{
		if (divisor == 0)
			return -1 ^ (1<<31);

		bool flag = 0 != ( (dividend ^ divisor) & (1<<31) );
		long a = abs((long) dividend);
		long b = abs((long) divisor);

		long pow_b, pows[32];
		pow_b = pows[0] = b;
		int n = 0;

		while (pow_b > 0 && pow_b < a && n < 31)
		{
			pow_b <<= 1;
			pows[++n] = pow_b;
		}

		if (pow_b == a)
		{
			if (flag == false)
				return n==31 ? (-1 ^ (1<<31)) : (1<<n);
			else
				return -(1<<n);
		}
		int ret = 0;

		for (n--; n >= 0; n--)
		{
			if (a >= pows[n])
			{
				a -= pows[n];
				ret |= (1<<n);
			}
		}

		return flag ? -ret : ret;
	}
};

#endif