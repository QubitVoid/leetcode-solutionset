int findMin(int* nums, int numsSize) {
	int left, right;
	left = 0;
	right = numsSize-1;
	int loop = 0;
	int *smaller;

	while (loop++ < numsSize) {
		smaller = nums[left] > nums[right] ? &right : &left;
		*(nums[left] > nums[right] ? &left : &right) = (right+left)/2;

		if (right == left) {
			if (left > 0) left--;
			else if (right < numsSize-1) right++;
			else return nums[right];
		}
	}

	return nums[*smaller];
}
