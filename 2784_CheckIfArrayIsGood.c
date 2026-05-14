#include <stdbool.h>
#include <stdlib.h>

bool isGood(int* nums, int numsSize) {
    int n = numsSize-1;
	bool *presentNums = calloc(n, sizeof(bool));
	bool *n_present = presentNums+(n-1); 
	bool n_presentTwice = false;
	bool base_present = false;

	// look for all the numbers in a loop
	for (int i=0; i < numsSize; i++) {
		if (nums[i] > n) break;

		if (nums[i] == n) {
			if (*n_present) {
				n_presentTwice = true;
			} else  {
				*n_present = true;
			}
		}
		else if (presentNums[nums[i]-1]) break;

		presentNums[nums[i]-1] = true;
	}

	if (n_presentTwice) {
		for (int i=0; i < n; i++) {
			if (!presentNums[i]) break;
			if (i == n-1) base_present = true;
		}
	}

	free(presentNums);
	return n_presentTwice && base_present;
}
