int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
	if (duration == 0) return 0;
	if (timeSeriesSize == 1) return duration;

	int totalTime = duration;

	for (unsigned long i=1; i < timeSeriesSize; i++) {

		if (timeSeries[i] - timeSeries[i-1] >= duration) {
			totalTime += duration;
		} else {
			totalTime += timeSeries[i] - timeSeries[i-1];
		}
	}

	return totalTime;
}
