#ifndef CLASS_Solution
#define CLASS_Solution

#include "util.h"

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	int maxPathSum(TreeNode *root)
	{
		if (root == NULL)
			return 1 | (1<<31);

		int max1, max2;
		maxPathSum(root, max1, max2);
		return max2;
	}

private:
	void maxPathSum(TreeNode *root, int &max1, int &max2)
	{
		int val = root->val;
		max1 = max2 = val;

		if (root->left  == NULL &&
			root->right == NULL)
			return;

		int a1, a2, b1, b2;

		// max1 = max(val, val+a1, val+b1)
		// max2 = max(val, val+a1, val+b1, a2, b2, val+a1+a2)

		if (root->left)
		{
			maxPathSum(root->left, a1, a2);
			if (a1 > 0)    max1 = max2 = val + a1;
			if (a2 > max2) max2 = a2;
		}

		if (root->right)
		{
			maxPathSum(root->right, b1, b2);
			if (b1 > 0)
			{
				val += b1;
				if (val > max1) max1 = val;
				if (val > max2) max2 = val;
			}
			if (b2 > max2) max2 = b2;
		}

		if (root->left && root->right && b1 > 0)
		{
			val += a1;
			if (val > max2) max2 = val;
		}
	}
};

#endif