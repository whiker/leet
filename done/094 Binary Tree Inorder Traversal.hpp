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
	vector<int> inorderTraversal(TreeNode *root)
	{
		if (root == NULL)
			return vector<int>();

		vector<int> ret;
		if (root->left != NULL)
			ret = inorderTraversal(root->left);

		ret.push_back(root->val);

		if (root->right != NULL)
		{
			vector<int> ret1 = inorderTraversal(root->right);
			ret.insert(ret.end(), ret1.begin(), ret1.end());
		}

		return ret;
	}
};

#endif