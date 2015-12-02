#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
public:
	string intToRoman(int num)
	{
		char ret[15];
		int ind = 0, i;

		for (i = num/1000; i > 0; --i)
			ret[ind++] = 'M';

		const char *letter = "IVXLCDM";
		int rate = 1000;

		for (int a = 4; a >= 0; a -= 2)
		{
			num %= rate;
			rate /= 10;
			i = num / rate;

			if (i == 0)
				continue;
			else if (i < 4)
			{
				for (; i > 0; --i)
					ret[ind++] = letter[a];
			}
			else if (i == 4)
			{
				ret[ind++] = letter[a];
				ret[ind++] = letter[a+1];
			}
			else if (i < 9)
			{
				ret[ind++] = letter[a+1];
				for (i -= 5; i > 0; --i)
					ret[ind++] = letter[a];
			}
			else
			{
				ret[ind++] = letter[a];
				ret[ind++] = letter[a+2];
			}
		}

		ret[ind] = 0;
		return ret;
	}
};

#endif