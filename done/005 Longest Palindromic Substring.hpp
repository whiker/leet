#include "util.h"

/*
	Solution solu;
	cout << solu.longestPalindrome("") << endl;
	cout << solu.longestPalindrome("a") << endl;
	cout << solu.longestPalindrome("abcbacba") << endl;
	cout << solu.longestPalindrome("aaa") << endl;
	cout << solu.longestPalindrome("aaaa") << endl;
	cout << solu.longestPalindrome("aaaaa") << endl;
	cout << solu.longestPalindrome("aaaaaa") << endl;
	cout << solu.longestPalindrome("aaabbbb") << endl;
	cout << solu.longestPalindrome("aaaabb") << endl;
*/

class Solution
{
public:
	string longestPalindrome(string s)
	{
		const char *inp = s.data();
		int n = s.length() - 1;
		int i, j, k, p, q;

		for (i = 1; i <= n; ++i)
		{
			j=0, k=n-i+1;
			for (; j < i; ++j, ++k)
			{
				p=j, q=k;
				while (inp[p]==inp[q] && p<q)
					++p, --q;
				if (p >= q)
					return s.substr(j, k-j+1);
			}
		}

		return s.substr(0,1);
	}
};