#include <stdbool.h>
#include <stdint.h>

// Definition for a binary tree node.
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

static bool isValidBSTLimited(struct TreeNode *root, int64_t limitLeft, int64_t limitRight) {
	if (!root) return false;

	bool leftValid = true; // true, in case if node doesn't exist
	bool rightValid = true;

	if (root->left) {
		if (root->left->val < root->val && root->left->val > limitLeft) {
			leftValid = isValidBSTLimited(root->left, limitLeft, root->val);
		} else return false;
	}
	if (root->right) {
		if (root->right->val > root->val && root->right->val < limitRight) {
			rightValid = isValidBSTLimited(root->right, root->val, limitRight);
		} else return false;
	}

    
	return leftValid && rightValid;
}

bool isValidBST(struct TreeNode* root) {
	return isValidBSTLimited(root, INT64_MIN, INT64_MAX);
}
