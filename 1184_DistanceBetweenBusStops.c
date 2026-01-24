int distanceBetweenBusStops(int* distance, int distanceSize,
							int start, int destination)
{
	int loc = start;
	int fdistance, bdistance, dist = 0;
	int dir = 1;

	if (distanceSize/2 > destination) dir = 1;
	else dir = -1;

	for (int i=-1; i <= 1; i+=2) {
		dist = 0;
		loc = start;
		while (loc != destination) {
			dist += distance[i == -1
							 ? (loc == 0 ? distanceSize-1-loc : loc-1) : loc];
			loc += i;

			if (i == -1 && loc < 0) loc = distanceSize-1;
			if (i == 1 && loc > distanceSize-1) loc = 0;
		}
		if (i==-1) bdistance = dist;
		else fdistance = dist;
	}

	return fdistance > bdistance ? bdistance : fdistance;

}
