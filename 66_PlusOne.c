#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *finalDigits = malloc(sizeof(int) * (digitsSize + 1));
	int carry = 0;

	memcpy(finalDigits, digits, sizeof(int) * digitsSize);
	*returnSize = digitsSize;

	finalDigits[digitsSize-1] += 1;

	for (int i=digitsSize-1; i >= 0; i--) {
		if (carry) {
			finalDigits[i]++;
			carry--;
		}

		if (finalDigits[i] >= 10) {
			carry++;

			finalDigits[i] = 0;

			if (i == 0) {
				*returnSize += 1;
				memmove(finalDigits+1, finalDigits, sizeof(int) * digitsSize);
				finalDigits[0] = carry;
			}
		} else {
			break;
		}
	}

	return finalDigits;
}
