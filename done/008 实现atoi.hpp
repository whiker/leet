#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
public:
	int myAtoi(string S)
	{
		const char *s = S.data();
		const int len = S.length();

		if (len == 0)
			return 0;
		if (len == 1)
		{
			return ('0' <= s[0] && s[0] <= '9') ?
				   (s[0] - '0') : 0;
		}

		int sign, start, end;
		sign = check(s, len, &start, &end);

		int overflow = 1 << 31;
		if (sign == 0) overflow--;

		int i = end - 1;
		if (end - start > 10)
			return overflow;
		else if (end - start == 10)
			if ( s[start] > '2' || (s[start] == '2' && s[start+1] >= '2') )
				return overflow;

		int v = 0, power = 1, v1;
		for (; i >= start; i--)
		{
			v1 = v + (s[i] - '0') * power;
			if (v1 < 0) return overflow;
			v = v1;
			power *= 10;
		}
		return sign==0 ? v : -v;
	}

private:
	int check(const char *s, const int len, int *start, int *end)
	{
		int i = 0, sign;
		for (; i < len && s[i] == ' '; i++);
		if (i == len) return false;

		if (s[i] == '+')
		{
			sign = 0;
			i++;
		}
		else if (s[i] == '-')
		{
			sign = 1;
			i++;
		}
		else
		{
			sign = 0;
			for (; i < len && s[i] == '0'; i++);
			if (i == len) return false;
		}
		*start = i;

		for (; i < len; i++)
		{
			if (s[i] < '0' || s[i] > '9')
				break;
		}

		*end = i;
		return sign;
	}
};

#endif