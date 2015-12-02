#include <stdio.h>

template <class T>
class Matrix
{
private:
	T**          m_data;
	unsigned int m_nRow;
	unsigned int m_nCol;

public:
	Matrix(unsigned int m, unsigned int n)
	{
		m_data = new T*[m];
		for (int i = 0; i < m; i++)
			m_data[i] = new T[n];
		m_nRow = m;
		m_nCol = n;
	}

	~Matrix()
	{
		for (unsigned int i = 0; i < m_nRow; i++)
			delete[] m_data[i];
		delete[] m_data;
		m_data = NULL;
	}

	T* operator[] (unsigned int i)
	{
		return i < m_nRow ? m_data[i] : NULL;
	}
};

int main()
{
	int m = 5, n = 7;
	Matrix<int> A(m, n);

	int m1 = m-1, n1 = n-1;
	int num = m*n;
	int i, j, cnt;
	bool goUp = true;

	for (i = j = cnt = 0; cnt < num; cnt++)
	{
		A[i][j] = cnt;

		if (goUp)
		{
			if (j < n1)
			{
				j++;
				if (i > 0) i--;
				else goUp = false;
			}
			else
			{
				i++;
				goUp = false;
			}
		}
		else
		{
			if (i < m1)
			{
				i++;
				if (j > 0) j--;
				else goUp = true;
			}
			else
			{
				j++;
				goUp = true;
			}
		}
	}

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("% 4d", A[i][j]);
		printf("\n");
	}

	return 0;
}