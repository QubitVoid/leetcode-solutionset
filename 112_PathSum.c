#include <stdbool.h>
#include <stdlib.h>

///**
 //* Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
// */

bool hasPathSumInitial(struct TreeNode* root, int targetSum, int initialSum) {
	if (root == NULL) return false;

	initialSum += root->val;

	if (root->left == NULL && root->right == NULL) {
		if (initialSum == targetSum) return true;
		else return false;
	}

	return (hasPathSumInitial(root->left, targetSum, initialSum)
		 || hasPathSumInitial(root->right, targetSum, initialSum));
}

bool hasPathSum(struct TreeNode* root, int targetSum) {
	return hasPathSumInitial(root, targetSum, 0);
}
