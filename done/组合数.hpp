#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

/* 测试代码

   int A[] = { 1, 2, 3, 4, 5 };
   Solution solu;
   solu.combine(A, sizeof(A)/4, 3);

*/

class Solution
{
private:
	int SelectInd;

public:
	void combine(int A[], int n, int k)
	{
		if (k < 1 || k > n)
			return;

		SelectInd = 0;

		int *select = new int[k];
		select[0] = 0;

		combine(A, select, 0, n, k);

		delete[] select;
	}

private:
	void combine(int A[], int select[], int ind, int n, int k)
	{
		if (ind == k-1)
		{
			for (; select[ind] < n; select[ind]++)
			{
				cout << ++SelectInd << " : ";
				for (int i = 0; i < k; i++)
					cout << A[select[i]];
				cout << endl;
			}
			return;
		}

		int next = ind + 1;

		for (; select[ind] < n; select[ind]++)
		{
			select[next] = select[ind] + 1;
			combine(A, select, next, n, k);
		}
	}
};

#endif
