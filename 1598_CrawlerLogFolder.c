#include <string.h>

int minOperations(char** logs, int logsSize) {
	int mino = 0;
	for (unsigned int i=0; i < logsSize; i++) {
		if (strcmp("../", logs[i]) == 0) {
			if (mino > 0) mino--;
		} else if (strcmp ("./", logs[i]) == 0) {
			continue;
		} else {
			mino++;
		}
	}

	return mino;
}
