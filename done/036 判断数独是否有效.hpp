#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
public:
	bool isValidSudoku(vector<vector<char>> &board)
	{
		char row[12][9], col[12][9], reg[12][9];
		memset(row, 0, 108);
		memset(col, 0, 108);
		memset(reg, 0, 108);

		for (int i = 0; i < 9; i++)
		{
			int k = i / 3;
			k *= 3;

			for (int j = 0; j < 9; j++)
			{
				char c = board[i][j] - '.';
				int l = j / 3;

				row[c][i]++;
				col[c][j]++;
				reg[c][k+l]++;
			}
		}

		for (int i = 2; i < 12; i++)
		{
			for (int j = 0; j < 10; j++)
				if (row[i][j] > 1 || col[i][j] > 1 || reg[i][j] > 1)
					return false;
		}

		return true;
	}
};

#endif