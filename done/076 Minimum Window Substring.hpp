#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
public:
	string minWindow(string S, string T)
	{
		const char* str_s = S.data();
		const char* str_t = T.data();
		const int   len_s = S.length();
		const int   len_t = T.length();

		if (len_s == 0 || len_t == 0 || len_t > len_s)
			return "";
		int i, j;

		int table[128];
		memset(table, 0, sizeof(table));
		for (i = 0; i < len_t; i++)
			++table[str_t[i]];

		int nchar = 0;
		for (i = 0; i < 128; i++)
		{
			if (table[i])
				nchar++;
		}

		int len_s1 = len_s - len_t;

		for (i = 0; i <= len_s1; i++)
			if (table[str_s[i]])
				break;
		if (i > len_s1)
			return "";
		if (len_t == 1)
			return S.substr(i, 1);

		int mark[128], cnt = 0;
		memset(mark, 0, sizeof(mark));

		char ind = str_s[i];
		if (++mark[ind] == table[ind])
			cnt++;
		int start = i, width;

		for (j = i+1; j < len_s; j++)
		{
			ind = str_s[j];
			if (table[ind] && ++mark[ind] == table[ind])
				if (++cnt == nchar)
					break;
		}
		if (cnt < nchar)
			return "";

		width = j-i+1;
		if (width == len_t)
			return S.substr(start, len_t);

		char prev = str_s[i];

		for (i++; i <= len_s1; i++)
		{
			if (table[str_s[i]] == 0)
				continue;

			if (--mark[prev] >= table[prev])
			{
				prev  = str_s[i];
				if (width > j-i+1)
				{
					start = i;
					width = j-i+1;
				}
				continue;
			}

			for (j++; j < len_s; j++)
			{
				ind = str_s[j];
				if (table[ind])
				{
					++mark[ind];
					if (ind == prev)
						break;
				}
			}
			if (j == len_s)
				break;

			prev = str_s[i];
			if (width > j-i+1)
			{
				start = i;
				width = j-i+1;
				if (width == len_t)
					return S.substr(start, width);
			}
		}

		return S.substr(start, width);
	}
};

#endif