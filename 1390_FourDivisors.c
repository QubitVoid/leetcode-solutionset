// Brute force algorithm but with sqrt
#include <math.h>

int sumFourDivisors(int* nums, int numsSize) {
	unsigned int sum = 0;
	int result_sum = 0;
	// I found the sqrt use in the discussion
	unsigned int num_sqrt;
	unsigned int divisors = 0;
	unsigned int div;

    for (int i=0; i < numsSize; i++) {
		if (nums[i] == 1) continue;
		sum += 1 + nums[i];
		divisors += 2;
		num_sqrt = sqrt(nums[i]); // save up a little bit of time

		for (int n=2; n <= num_sqrt; n++) {
			if (nums[i] % n == 0) {
				sum += n;
				divisors++;
				if (divisors >= 4) break;
				div = nums[i] / n;
				if (div != n) {
					sum += nums[i] / n;
					divisors++;
				}
			}

			if (divisors > 4) break;
		}

		if (divisors == 4) result_sum += sum;
		sum = 0;
		divisors = 0;
	}

	return result_sum;
}
