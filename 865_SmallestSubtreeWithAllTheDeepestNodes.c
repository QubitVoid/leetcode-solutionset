#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
	int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeDepth {
	int depth;
	struct TreeNode *tree;
};

struct TreeDepth* getTreeDepth(struct TreeNode *root) {
	if (!root) return NULL;

	struct TreeDepth *treeDepth;
	struct TreeDepth *tdleft, *tdright, *tdbigger = NULL;

	tdleft = getTreeDepth(root->left);
	tdright = getTreeDepth(root->right);

	treeDepth = malloc(sizeof(struct TreeDepth));
	treeDepth->tree = NULL;
	treeDepth->depth = 1;

	if (tdleft && tdright) {
		if (tdleft->depth == tdright->depth) {
			treeDepth->tree = root;
			tdbigger = tdleft;
			free(tdright);
		} else {
			tdbigger = tdleft->depth > tdright->depth ? tdleft : tdright;
			free(tdleft->depth > tdright->depth ? tdright : tdleft);
		}
	} else if (tdleft) {
		tdbigger = tdleft;
	} else if (tdright) {
		tdbigger = tdright;
	}
	
	if (tdbigger) {
		if (!treeDepth->tree) treeDepth->tree = tdbigger->tree;
		treeDepth->depth += tdbigger->depth;
	} else {
		treeDepth->tree = root;
	}

	free(tdbigger);

	return treeDepth;
}

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
	struct TreeNode *swad;
	struct TreeDepth *treeDepth;

	treeDepth = getTreeDepth(root);
	swad = treeDepth->tree;
    
	free(treeDepth);

	return swad;
}
