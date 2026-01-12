int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize) {
	if (!points || !points[0]) return 0;
	int seconds = 0;
	int x = points[0][0];
	int y = points[0][1];
	int vel[] = {0,0};

	for (int i=1; i < pointsSize; seconds++) {
		// Determine X movement
		if (points[i][0] == x) {
			vel[0] = 0;
		} else if (points[i][0] < x) {
			vel[0] = -1;
		} else if (points[i][0] > x) {
			vel[0] = 1;
		}
		// Determine Y movement
		if (points[i][1] == y) {
			vel[1] = 0;
		} else if (points[i][1] < y) {
			vel[1] = -1;
		} else if (points[i][1] > y) {
			vel[1] = 1;
		}

		if (!vel[0] && !vel[1]) {
			seconds--;
			i++;
			continue;
		}

		x += vel[0];
		y += vel[1];
	}

	return seconds;
}
