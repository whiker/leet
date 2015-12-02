#include "util.h"

class Solution
{
public:
	int reverse(int x)
	{
		const char *max_int = "2147483648";

		char s1[16], s2[16], s3[16];
		sprintf(s1, "%d", abs(x));
		int n = strlen(s1);
		int i=n, j=-1;
		while (i > 0)
			s2[++j] = s1[--i];
		s2[n] = 0;

		sprintf(s3, "%010s", s2);
		if (strcmp(s3, max_int) > 0)
			return 0;

		int x1 = atoi(s2);
		if (x < 0) x1 = 0-x1;
		return x1;
	}
};