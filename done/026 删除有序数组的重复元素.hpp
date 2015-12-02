#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
public:
	int removeDuplicates(int A[], int n)
	{
		if (n == 0) return 0;

		int p = 0, i = 1;

		while (i < n)
		{
			while (i < n && A[i] == A[p])
				i++;

			if (i < n)
				A[++p] = A[i++];
		}

		return p+1;
	}
};

#endif