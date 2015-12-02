#include "util.h"

/*
	unordered_set<string> dict;
	dict.insert("cats");
	dict.insert("cat");
	dict.insert("sand");
	dict.insert("and");
	dict.insert("dog");
	string s = "catsanddog";

	Solution solu;
	vector<string> ret = solu.wordBreak(s, dict);
	for (auto it = ret.begin(); it != ret.end(); it++)
		cout << *it << endl;
*/

class Solution
{
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict)
	{
		m_str = s.data();
		m_len = s.length();
		int *ind = new int[m_len];
		int *num = new int[m_len];
		m_word.clear();
		auto dict_end = dict.end();
		int i, j;

		for (i = m_len-1; i >= 0; --i)
		{
			num[i] = 0;
			for (auto it = dict.begin(); it != dict_end; ++it)
			{
				const char *p = it->data();
				j = i;
				while (*p && *p == m_str[j])
					++p, ++j;
				if (*p == 0)
				{
					if (num[i] == 0)
						ind[i] = m_word.size();
					++num[i];
					m_word.push_back(j);
				}
			}
		}

		m_ret.clear();
		for (i = m_word.size()-1; i >= 0; --i)
			if (m_word[i] == m_len)
				break;
		if (i == -1) return m_ret;
		
		m_trace.clear();
		m_trace.push_back(0);
		split(0, ind, num);

		delete[] num, ind;
		return m_ret;
	}

private:
	const char *m_str;
	int m_len;
	vector<int> m_word;
	vector<string> m_ret;
	vector<int> m_trace;

private:
	void split(int off, int *ind, int *num)
	{
		if (off == m_len)
		{
			int n = m_trace.size();
			char *temp = new char[m_len+n];
			int i = 0, j = 0, k;
			for (k = 1; k < n; ++k)
			{
				for (; j < m_trace[k]; ++i, ++j)
					temp[i] = m_str[j];
				temp[i] = ' ';
				++i;
			}
			temp[i-1] = 0;
			m_ret.push_back(temp);
			delete[] temp;
			return;
		}
		else if (off > m_len)
			return;

		int n = ind[off] + num[off];
		for (int i = ind[off]; i < n; ++i)
		{
			m_trace.push_back(m_word[i]);
			split(m_word[i], ind, num);
			m_trace.pop_back();
		}
	}
};