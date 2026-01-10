int singleNumber(int* nums, int numsSize) {
	int result = nums[0];
    for (int i=1; i < numsSize; i++) {
        // printf("Number: %d (%08b) ^ Result: %d (%08b)\n", nums[i], nums[i], result, result);
		result ^= nums[i]; // ^ - XOR
	}
	return result;
}
