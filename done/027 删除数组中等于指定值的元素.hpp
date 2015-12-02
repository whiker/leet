#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
public:
	int removeElement(int A[], int n, int elem)
	{
		int p = 0;
		for (int i = 0; i < n; i++)
		{
			if (A[i] != elem)
				A[p++] = A[i];
		}
		return p;
	}
};

#endif