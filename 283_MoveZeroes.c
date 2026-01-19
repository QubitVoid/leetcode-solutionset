void moveZeroes(int* nums, int numsSize) {
	int zeroes = 0;

    for (int i=0; i < numsSize; i++) {
		if (nums[i] == 0) {
			zeroes++;
			continue;
		}

		if (nums[i] != 0 && zeroes > 0 && i >= zeroes) {
			nums[i-zeroes] = nums[i];
		}

		if (i >= numsSize - zeroes) {
			nums[i] = 0;
		}
	}
	
	for (int i=numsSize-zeroes; i < numsSize; i++) {
		nums[i] = 0;
	}
}
