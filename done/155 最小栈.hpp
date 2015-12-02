#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
private:
	stack<int> m_sta;
	stack<int> m_staMin;

public:
	void push(int x)
	{
		m_sta.push(x);

		if (!m_staMin.empty())
		{
			int min = m_staMin.top();
			if (min < x) x = min;
		}

		m_staMin.push(x);
	}

	void pop()
	{
		m_sta.pop();
		m_staMin.pop();
	}

	int top()
	{
		return m_sta.top();
	}

	int getMin()
	{
		return m_staMin.top();
	}
};

#endif