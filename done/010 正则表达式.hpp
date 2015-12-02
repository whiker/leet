#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
public:
	bool isMatch(string s, string p)
	{
		return isMatch(s.data(), p.data(), 0, 0);
	}

private:
	bool isMatch(const char *s, const char *p, int i, int j)
	{
		while (s[i] && p[j])
		{
			if (p[j+1] != '*')
			{
				if (s[i] != p[j] && p[j] != '.')
					return false;
				i++, j++;
			}
			else
			{
				if (s[i] == p[j])
				{
					for (int k = i; s[k]==p[j]; k++)
						if (isMatch(s, p, k+1, j+2))
							return true;
				}
				else if (p[j] == '.')
				{
					for (int k = i; s[k]; k++)
						if (isMatch(s, p, k+1, j+2))
							return true;
				}

				j += 2;
			}
		}

		if (s[i] == 0 && p[j])
		{
			while (p[j+1] == '*')
			{
				j += 2;
				if (p[j] == 0)
					return true;
			}
			return false;
		}
		else if (s[i] && p[j] == 0)
			return false;
		else
			return true;
	}
};

#endif