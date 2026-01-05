#include <stdbool.h>
#include <stdint.h>

/*
enum direction { up, down, left, right, none };
typedef struct {
	int x;
	int y;
} position;

int matrixCheck(const int **matrix, const position matrixSize, const position pos, const enum direction dir, bool *exists) {
	switch (dir) {
	case up:
		if (pos.y > 0) {
			*exists = true;
			return matrix[pos.y-1][pos.x];
		} else {
			*exists = false;
			return 0;
		}
		break;
	case down:
		if (pos.y < matrixSize.y) {
			*exists = true;
			return matrix[pos.y+1][pos.x];
		} else {
			*exists = false;
			return 0;
		}
		break;
	case left:
		if (pos.x > 0) {
			*exists = true;
			return matrix[pos.y][pos.x-1];
		} else {
			*exists = false;
			return 0;
		}
		break;
	case right:
		if (pos.x < matrixSize.x) {
			*exists = true;
			return matrix[pos.y][pos.x+1];
		} else {
			*exists = false;
			return 0;
		}
		break;

	case none:
		*exists = false;
		return 0;
		break;
	}
}

enum direction findSmallestAdjacent(const int **matrix, position matrixSize, position pos) {
	bool exists;
	int smallest, current;
	int *target = &smallest;
	enum direction smallestdir = none;

	*target = matrixCheck(matrix, matrixSize, pos, up, &exists);
	if (exists) {
		target = &current;
		smallestdir = up;
	}

	*target = matrixCheck(matrix, matrixSize, pos, left, &exists);
	if (exists) {
		if (smallest > *target) {
			smallest = *target;
			smallestdir = left;
		}
		target = &current;
	}

	*target = matrixCheck(matrix, matrixSize, pos, down, &exists);
	if (exists) {
		if (smallest > *target) {
			smallest = *target;
			smallestdir = down;
		}
		target = &current;
	}

	*target = matrixCheck(matrix, matrixSize, pos, right, &exists);
	if (exists) {
		if (smallest > *target) {
			smallest = *target;
			smallestdir = right;
		}
		target = &current;
	}

	return smallestdir;
}

long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
    position pos = {0, 0};
	position matrix_size = {matrixSize, matrixColSize[0]};
	int negativeValues = -1;
	int minNegativeValues = -1;
	unsigned int negativec;
	unsigned int smallest_negative;
	unsigned int smallest_negative_now;
	unsigned int totalSum;
	bool exists;

	while (negativeValues != minNegativeValues) {
		negativec = 0;
		for (unsigned int i=0; i < matrixSize; i++) {
			pos.x = i;
			for (unsigned int k=0; k < matrixColSize[0]; k++) {
				pos.y = k;
				if (matrix[k][i] < 0) {
					negativec++;
				}
			}
		}
		if (smallest_negative > smallest_negative_now) {
			smallest_negative = smallest_negative_now;
		}
		if (minNegativeValues == -1) {
			minNegativeValues = negativec % 2;
		}
	}
}
*/

/* Cheating */
long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
    int biggest_negative = INT32_MIN;
	int smallest_positive = INT32_MAX;
	int negativec = 0;
	long long totalSum = 0;
	long long negativeSum = 0;

	for (unsigned int i=0; i < matrixSize; i++) {
		for (unsigned int k=0; k < matrixColSize[0]; k++) {
			if (matrix[k][i] < 0) {
				negativec++;
				if (biggest_negative < matrix[k][i]) {
					biggest_negative = matrix[k][i];
				}
				negativeSum += matrix[k][i];
			}
			else if (matrix[k][i] >= 0) {
				if (matrix[k][i] < smallest_positive) {
					smallest_positive = matrix[k][i];
				}
			}

			totalSum += matrix[k][i];
		}
	}

	if (negativec % 2 == 1) {
		if (biggest_negative * -1 > smallest_positive) {
			biggest_negative = (smallest_positive * -1);
		}
		totalSum += (biggest_negative * 2);
	} 
	totalSum += (negativeSum * -2);

	return totalSum;
}
