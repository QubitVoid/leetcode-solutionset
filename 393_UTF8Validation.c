#include <stdbool.h>

bool validUtf8(int* data, int dataSize) {
	int cnum = 0;

    for (int i=0; i < dataSize; i++) {
		if (cnum > 0) {
			if ((data[i] & 0b11000000) == 0b10000000) {
				cnum--;
				continue;
			} else {
				return false;
			}
		}
		
		// If plain ascii
		else if ((data[i] & 0b10000000) == 0) continue;

		// If 2-byte symbol
		else if ((data[i] & 0b11100000) == 0b11000000) {
			cnum = 1;
		}
		// If 3-byte symbol
		else if ((data[i] & 0b11110000) == 0b11100000) {
			cnum = 2;
		}
		// If 4-byte symbol
		else if ((data[i] & 0b11111000) == 0b11110000) {
			cnum = 3;
		}

		else {
			return false;
		}
	}

	if (cnum > 0) return false;

	return true;
}
