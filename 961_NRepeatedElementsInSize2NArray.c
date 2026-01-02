int repeatedNTimes(int* nums, int numsSize) {
	// First three elements and last
	if (nums[0] == nums[1] || nums[0] == nums[2]) return nums[0];
	if (nums[1] == nums[2]) return nums[1];
	if (nums[0] == nums[numsSize-1]) return nums[0];

	// Fallback
	for (int i=1; i <= (numsSize/2); i++) {
		if (nums[i-1] == nums[i] || nums[i] == nums[i+1]) {
			return nums[i];
		}
		if (nums[i-1] == nums[i+1]) {
			return nums[i-1];
		}
	}

	/* Values that lead to fallbackier:
	 * [9,1,2,5,1,3,1,1]
	 * [9,1,2,5,1,3,0,1,1,1] - numsSize/2 != the non-unique number
	 */
	
	// Fallbackier
	for (int i=0; i <= (numsSize/2); i++) {
		for (int k=0; k < numsSize; k++) {
			if (k == i) continue;

			if (nums[i] == nums[k]) return nums[k];
		}
	}

	return nums[(numsSize/2)-1];
}
