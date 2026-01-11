// Around 800ms Runtime, but thats my first Hard promblem solved

enum direction { up, down, left, right, direction_none };

typedef struct {
	char **matrix;
	int matrixSize;
	int *matrixColSize;
} Matrix;

typedef struct {
	int x;
	int y;
} Position;

static int matrixPeekY(Matrix *matrix, Position *pos, enum direction dir) {
	int ones = 0;
	if (dir == down) {
		for (int i=pos->y + 1; i < matrix->matrixSize; i++) {
			if (matrix->matrix[i][pos->x] != '1') return ones;
			else ones++;
		}
	}

	return ones;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
	Matrix smatrix = { matrix, matrixSize, matrixColSize };
	Position pos = { 0, 0 };
	int maxRect = 0;
	int curMaxRect = 0;
	int rectStartedAt = -1;
	int rectX = 0;
	int rectY = 0;
	int rectYtmp = 0;
	int rememberPos = -1;

	for (int i=0; i < matrixSize; i++) {
		pos.y = i;
		for (int k=0; k < matrixColSize[i]; k++) {
			pos.x = k;

			if (matrix[i][k] == '1') {
				if (rectStartedAt == -1) rectStartedAt = k;

				rectYtmp = matrixPeekY(&smatrix, &pos, down) + 1;
				if (rectY == 0 || rectY > rectYtmp) rectY = rectYtmp;
				else if (rememberPos == -1) rememberPos = pos.x;
				
				if (rectYtmp > maxRect) maxRect = rectYtmp;

				rectYtmp = 0;
			} else {
				rectX = 0;
				rectY = 0;
				curMaxRect = 0;
				rectStartedAt = -1;
			}

			if (rectStartedAt != -1)
				curMaxRect = (pos.x+1 - rectStartedAt) * rectY;
			if (curMaxRect > maxRect) maxRect = curMaxRect;

			if (rememberPos != -1 && k == matrixColSize[i]-1) {
				k -= matrixColSize[i] - rememberPos;
				rememberPos = -1;

				rectX = 0;
				rectY = 0;
				curMaxRect = 0;
				rectStartedAt = -1;
			}
		}
		rectX = 0;
		rectY = 0;
		curMaxRect = 0;
		rectStartedAt = -1;
	}

	return maxRect;
}
