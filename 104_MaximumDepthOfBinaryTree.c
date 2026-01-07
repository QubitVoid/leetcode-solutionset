#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int maxDepthContinue(struct TreeNode *root, int startAt) {
	if (!root) return -1;
	
	int depthLeft = maxDepthContinue(root->left, startAt+1);
	int depthRight = maxDepthContinue(root->right, startAt+1);
	
	if (depthRight == -1 && depthLeft == -1) return startAt;

	return depthLeft >= depthRight ? depthLeft : depthRight;
}

int maxDepth(struct TreeNode* root) {
	return maxDepthContinue(root, 0) + 1;
}
