#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
public:
	bool wordBreak(string s, unordered_set<string>& dict)
	{
		const int len = s.length();

		vector<bool> isBreakable(len+1, false);

		unordered_set<string>::iterator dictEnd = dict.end();
		isBreakable[len] = true;

		for (int from = len-1; from >= 0; from--)
		{
			for (int i = len-from; i >= 1; i--)
			{
				if (isBreakable[from+i] && dict.find(s.substr(from, i)) != dictEnd)
				{
					isBreakable[from] = true;
					break;
				}
			}
		}

		return isBreakable[0];
	}
};

#endif