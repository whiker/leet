#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

// Solution solu;
// solu.crossTowString("ABC", "DE");

class Solution
{
public:
	void crossTwoString(string s1, string s2)
	{
		int m = s1.length();
		int n = s2.length();
		if (m == 0)
		{
			if (n) cout << s2 << endl;
			return;
		}
		else if (n == 0)
		{
			cout << s1 << endl;
			return;
		}

		char *s3 = new char[m+n+1];
		s3[m+n] = 0;

		int *leftNum = new int[m+1];

		cross(s1.data(), s2.data(), m, n, s3, leftNum, 0);

		delete[] s3;
		delete[] leftNum;
	}

private:
	void cross(const char *s1, const char *s2, 
		int m, int n, char s3[], int leftNum[], int curr)
	{
		int num = (curr == 0) ? 0 : leftNum[curr-1];
		int n1 = n - num;
		char *dst = s3 + curr + num;
		const char *src = s2 + num;

		if (curr == m-1)
		{
			for (int i = 0; i <= n1; i++)
			{
				memcpy(dst, src, i);
				dst[i] = s1[curr];
				memcpy(dst+i+1, src+i, n1-i);
				cout << s3 << endl;
			}
		}
		else
		{
			for (int i = 0; i <= n1; i++)
			{
				memcpy(dst, src, i);
				s3[curr+num+i] = s1[curr];
				leftNum[curr] = num + i;
				cross(s1, s2, m, n, s3, leftNum, curr+1);
			}
		}
	}
};

#endif