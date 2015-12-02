#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
public:
	string longestCommonPrefix(vector<string> &strs)
	{
		int nStrs = strs.size();
		if (nStrs <= 0) return "";
		int l = strs[0].length(), l1;

		for (int i = 1; l > 0 && i < nStrs; ++i)
		{
			l1 = compare(strs[i-1], strs[i], l);
			if (l1 < l) l = l1;
		}

		return strs[0].substr(0, l);
	}

	int compare(string &s1, string &s2, int n)
	{
		int l = s2.length();
		if (l < n) n = l;

		l = 0;
		while (l<n && s1[l]==s2[l])
			++l;
		return l;
	}
};

#endif