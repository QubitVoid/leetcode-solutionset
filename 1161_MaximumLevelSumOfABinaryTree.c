#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// My runtime is about 185ms O(N*H) bruh

/**
 * Definition for a binary tree node. */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


long long levelSum(struct TreeNode *root, int deepDown, bool *exists) {
	int currentDeep;
	long long sum = 0;
	long long sumRight, sumLeft;
	bool rightExists = true, leftExists = true;

	if (root == NULL) {
		*exists = false;
		return 0;
	}
	if (deepDown == 0) { 
		printf("This shouldn't be happening\n");
		return root->val;
	}
	if (deepDown == 1) {
		if (root->left) {
			sum += root->left->val;
			leftExists = true;
		} else leftExists = false;
		if (root->right) {
			sum += root->right->val;
			rightExists = true;
		} else rightExists = false;
		*exists = leftExists || rightExists;

		return sum;
	}

	sumLeft = levelSum(root->left, deepDown - 1,
			&leftExists);
	sumRight = levelSum(root->right, deepDown - 1,
			&rightExists);
	*exists = rightExists || leftExists;

	if (exists) sum = sumLeft + sumRight;
	else return 0;

	return sum;
}

int maxLevelSum(struct TreeNode* root) {
	if (root == NULL) return -1;
	
	bool exists = true;
	long long levelSumMax = root->val; // the biggest sum of the levels
	int maxLevelSum = 0; // the level which sum is the biggest
	long long currentSum;
	int currentLevel = maxLevelSum;
	
	while (exists) {
		currentLevel++;
		currentSum = levelSum(root, currentLevel, &exists);
		if (!exists) break;

		if (currentSum > levelSumMax) {
			maxLevelSum = currentLevel;
			levelSumMax = currentSum;
		}
	}

	return maxLevelSum + 1;
}
