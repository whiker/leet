#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
public:
	void print(int num0, int num1, int curr, int N, char s[])
	{
		if (num0 == num1)
		{
			if (num0 == N)
			{
				s[curr] = 0;
				cout << s << endl;
			}
			else if (num0 < N)
			{
				s[curr] = '(';
				print(num0+1, num1, curr+1, N, s);
			}
			else
				cout << "error" << endl;
		}
		else if (num0 > num1)
		{
			if (num0 < N)
			{
				s[curr] = '(';
				print(num0+1, num1, curr+1, N, s);
			}
			s[curr] = ')';
			print(num0, num1+1, curr+1, N, s);
		}
		else
			cout << "error" << endl;
	}
};

#endif