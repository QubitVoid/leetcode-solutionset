#include <stdio.h>

int convertTime(char* current, char* correct) {
    int cur[2];
	int target[2];
	int curMin, targetMin;
	int operations = 0;
	const int timeIncrease[4] = {60,15,5,1};

	// Parse time
	sscanf(current, "%d:%d", cur, cur+1);
	sscanf(correct, "%d:%d", target, target+1);

	targetMin = target[0]*60 + target[1];
	curMin = cur[0]*60 + cur[1];
	if (targetMin < curMin) {
		targetMin += (24*60);
	}

	while (curMin != targetMin) {
		int diff = targetMin - curMin;
		if (diff < 0) diff = (targetMin+(24*60)) - curMin;
		for (int m=0; m < 4; m++) {
			if (diff < timeIncrease[m]) continue;
			
			curMin += timeIncrease[m];
			break;
		}

		operations++;
	}

	cur[0] = (curMin / 60) % 24;
	cur[1] = curMin % 60;


	return operations;
}
