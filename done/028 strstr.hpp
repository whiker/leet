#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
public:
	int strStr(char *src, char *pat)
	{
		if (src == 0) return -1;
		if (pat == 0) return 0;

		char *s = src, *t1, *t2;
		char first = *pat;

		int diff = strlen(src) - strlen(pat);
		if (diff < 0) return -1;
		char *end = s + diff;

		for (; s <= end; s++)
		{
			while (s <= end && *s != first)
				s++;
			if (s > end) return -1;

			t1 = s + 1;
			t2 = pat + 1;
			while (*t2 && *t1 == *t2)
				t++, t1++;
			if (*t2 == 0)
				return s - src;
		}

		return -1;
	}
};

#endif