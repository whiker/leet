#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

class Solution
{
public:

	bool isBalanced_01(TreeNode *root)
	{
		int h = treeHeight(root);
		return h != -1;
	}

	int treeHeight(TreeNode *root)
	{
		if (root == NULL)
			return 0;

		int h1 = 1 + treeHeight(root->left);
		if (h1 == 0) return -1;

		int h2 = 1 + treeHeight(root->right);
		if (h2 == 0) return -1;

		if (abs(h1 - h2) > 1)
			return -1;

		return h1 > h2 ? h1 : h2;
	}

	bool isBalanced(TreeNode *root)
	{
		stack<TreeNode*> nodes;
		stack<char>      marks;
		stack<int>       depth;
		TreeNode *p = root;
		char m; int d1, d2;

		while (p || !nodes.empty())
		{
			while (p)
			{
				nodes.push(p);
				marks.push(0);
				depth.push(0);
				p = p->left;
			}

			p = nodes.top();
			m = marks.top();

			if (m == 0)  // has not visit right node
			{
				marks.pop();
				marks.push(1);

				if (depth.top() == 0)  // left node is NULL
				{
					depth.pop();
					depth.push(1);
				}

				if (p->right == NULL && depth.top() > 2)
					return false;
				p = p->right;
			}
			else
			{
				nodes.pop();
				marks.pop();

				d1 = depth.top() + 1;
				depth.pop();

				if (!depth.empty())
				{
					d2 = depth.top();
					depth.pop();

					if (d2 > 0)
					{
						if (abs(d1 - d2) > 1)
							return false;
						if (d1 < d2)
							d1 = d2;
					}

					depth.push(d1);
				}

				p = NULL;
			}
		}

		return true;
	}
};

#endif