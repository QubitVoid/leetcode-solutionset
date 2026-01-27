#include <math.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize) {
    int width, length;
	int area_sqrt = sqrt(area);
	int *rect = malloc(sizeof(int) * 2);
	*returnSize = 2;
	int diff, mindiff = INT32_MAX, mindiffw, mindiffl;

	for (unsigned int i=area_sqrt; i > 0; i--) {
		length = i;
		width = area / i;

		if (area % i != 0) {
			continue;
		}

		if (length == width) {
			rect[0] = length;
			rect[1] = width;
			return rect;
		}

		if (width > length) {
			int tmp = length;
			length = width;
			width = tmp;
		}

		diff = length - width;
		if (diff < mindiff) {
			mindiff = diff;
			mindiffl = length;
			mindiffw = width;
		}
	}

	rect[0] = mindiffl;
	rect[1] = mindiffw;

	return rect;
}
