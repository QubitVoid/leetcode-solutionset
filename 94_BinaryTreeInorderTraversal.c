#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void traverse(struct TreeNode *root, int *inorder, int *inorder_used) {
	if (!root) return;

	if (root->left) {
		traverse(root->left, inorder, inorder_used);
	}

	inorder[*inorder_used] = root->val;
	*inorder_used += 1;

	if (root->right) {
		traverse(root->right, inorder, inorder_used);
	}
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    // if (!root) return NULL;
	int *inorder = malloc(sizeof(int) * 100);
	int inorder_used = 0;

	traverse(root, inorder, &inorder_used);
	
	*returnSize = inorder_used;
	return inorder;
}
