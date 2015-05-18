#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
public:
	void perm(int arr[], int len, int from)
	{
		if (from == len)
		{
			for (int i = 0; i < len; i++)
				printf("%d  ", arr[i]);
			cout << endl;
			return;
		}

		int headval = arr[from];
		int *head = arr + from;

		for (int i = from; i < len; i++)
		{
			*head = arr[i];
			arr[i] = headval;

			perm(arr, len, from+1);

			arr[i] = *head;
			*head = headval;
		}
	}
};

#endif