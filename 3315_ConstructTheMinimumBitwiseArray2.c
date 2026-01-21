#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
	*returnSize = numsSize;
    int *ans = malloc(*returnSize * sizeof(int));
	int numsi_sqrt;

	for (int i=0; i < numsSize; i++) {
		ans[i] = -1;
		if (nums[i] % 2 == 0) continue;
		
		unsigned int lonelyBit = (1u << ((sizeof(int)*8)-1));
		for (int k=0; k < 8*sizeof(int); k++) {
			int num = nums[i] & ~lonelyBit;
			if (num >= nums[i]) { }
			else if ((num | (num+1)) == nums[i]) {
				ans[i] = num;
				break;
			}

			lonelyBit >>= 1;
		}
	}

	return ans;
}
