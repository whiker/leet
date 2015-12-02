#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
public:
	vector<string> findRepeatedDnaSequences(string s)
	{
		const char *str = s.data();
		const int len = s.length();

		if (len < 11)
			return vector<string>();

		unordered_map<int, int> m;
		int v = strToInt(str);
		++m[v];

		const int C=1<<18, G=2<<18, T=3<<18;

		for (int i = 10; i < len; i++)
		{
			v >>= 2;
			if (str[i] == 'C')
				v |= C;
			else if (str[i] == 'G')
				v |= G;
			else if (str[i] == 'T')
				v |= T;
			++m[v];
		}

		vector<string> ret;
		char temp[11];

		for (auto it = m.begin(); it != m.end(); it++)
		{
			if (it->second > 1)
			{
				intToStr(it->first, temp);
				ret.emplace_back(temp);
			}
		}

		return ret;
	}

	int strToInt(const char *s)
	{
		int v = 0;

		for (int i = 0; i < 20; i+=2)
		{
			if (*s == 'C')
				v |= 1 << i;
			else if (*s == 'G')
				v |= 2 << i;
			else if (*s == 'T')
				v |= 3 << i;
			s++;
		}

		return v;
	}

	void intToStr(int v, char s[])
	{
		const char arr[] = { 'A', 'C', 'G', 'T' };
		s[10] = 0;

		for (int i = 0; i < 10; i++)
		{
			s[i] = arr[v&3];
			v >>= 2;
		}
	}
};

#endif