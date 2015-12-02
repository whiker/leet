#ifndef CLASS_BSTIterator
#define CLASS_BSTIterator

#include "util.h"

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator
{
private:
	TreeNode *m_root;
	TreeNode *m_current;

public:
	BSTIterator(TreeNode *root)
	{
		m_root = root;

		m_current = root;
		if (root != NULL)
		{
			while (m_current->left != NULL)
				m_current = m_current->left;
		}
	}

	bool hasNext()
	{
		return m_current != NULL;
	}

	int next()
	{
		int ret = m_current->val;

		if (m_current->right != NULL)
		{
			m_current = m_current->right;
			while (m_current->left != NULL)
				m_current = m_current->left;
		}
		else if (m_current != m_root)
		{
			TreeNode *p = m_root;
			TreeNode *q = NULL;
			while (p && p != m_current)
			{
				if (p->val >= ret)
				{
					q = p;
					p = p->left;
				}
				else
					p = p->right;
			}
			m_current = q;
		}
		else
			m_current = NULL;

		return ret;
	}
};

#endif