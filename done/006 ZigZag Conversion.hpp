#include "util.h"

class Solution
{
public:
	string convert(string s, int nRows)
	{
		int n = s.length();
		const char *src = s.data();
		if (nRows == 1) return s;

		char* const dst = new char[n+1];
		dst[n] = 0;
		int i, j, u, v, p = 0;

		int nrow = nRows - 1;
		int rate = 2 * nrow;

		for (i = 0; i < n; i+=rate)
			dst[p++] = src[i];

		for (i=1, j=rate-1; i < nrow; ++i, --j)
		{
			for (u=i, v=j; u<n || v<n; u+=rate, v+=rate)
			{
				if (u<n) dst[p++] = src[u];
				if (v<n) dst[p++] = src[v];
			}
		}

		for (i = nrow; i < n; i+=rate)
			dst[p++] = src[i];

		string ret(dst);
		delete[] dst;
		return ret;
	}
};