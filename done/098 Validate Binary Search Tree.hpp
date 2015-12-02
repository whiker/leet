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
	bool isValidBST(TreeNode *root)
	{
		if (root == NULL)
			return true;

		if (root->left != NULL)
		{
			if (!isValidBST(root->left))
				return false;
			if (getValidBSTmax(root->left) >= root->val)
				return false;
		}

		if (root->right != NULL)
		{
			if (!isValidBST(root->right))
				return false;
			if (getValidBSTmin(root->right) <= root->val)
				return false;
		}

		return true;
	}

	int getValidBSTmax(TreeNode *root)
	{
		while (root->right != NULL)
			root = root->right;
		return root->val;
	}

	int getValidBSTmin(TreeNode *root)
	{
		while (root->left != NULL)
			root = root->left;
		return root->val;
	}
};

#endif