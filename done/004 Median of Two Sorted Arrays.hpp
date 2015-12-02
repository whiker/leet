#include "util.h"

/*
	int A[] = { 1, 2 };
	int B[] = { 1, 2, 3 };

	Solution solu;
	cout << solu.findMedianSortedArrays(A, 2, B, 3) << endl;
*/

class Solution
{
private:
	int a1, a2, b1, b2;

private:
	double find(int A[], int B[], int target)
	{
		// A empty or B empty
		if (a2 < a1)
			return B[b1+target];
		else if (b2 < b1)
			return A[a1+target];

		int c = (a1 + a2) / 2;
		int t = A[c];

		int mid, low = b1, high = b2;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (t < B[mid])
				high = mid - 1;
			else if (t > B[mid])
				low = mid + 1;
			else
			{
				low = mid;
				break;
			}
		}

		int n = c + low - a1 - b1;
		if (n > target)
		{
			a2 = c-1;
			b2 = low-1;
			return find(A, B, target);
		}
		else if (n < target)
		{
			a1 = c+1;
			b1 = low;
			return find(A, B, target-n-1);
		}
		else
			return t;
	}

public:
	double findMedianSortedArrays(int A[], int m, int B[], int n)
	{
		int target = (m + n) / 2;
		a1 = 0, a2 = m-1;
		b1 = 0, b2 = n-1;
		double ret = find(A, B, target);

		if ((m+n)%2 == 0)
		{
			a1 = 0, a2 = m-1;
			b1 = 0, b2 = n-1;
			double ret1 = find(A, B, target-1);
			ret = (ret + ret1) / 2;
		}

		return ret;
	}
};