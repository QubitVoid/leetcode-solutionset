#include <string.h>
#include <stdlib.h>

int compareVersion(char* version1, char* version2) {
	long v1_size = strlen(version1), v2_size = strlen(version2);
	unsigned int v1_untilDot, v2_untilDot;
	unsigned int v1_part, v2_part;

	while (1) {
		if (v1_size > 0) {
			v1_untilDot = strcspn(version1, ".");
			version1[v1_untilDot] = 0;
			v1_part = atoi(version1);
			version1[v1_untilDot] = '.';
		}

		if (v2_size > 0) {
			v2_untilDot = strcspn(version2, ".");
			version2[v2_untilDot] = 0;
			v2_part = atoi(version2);
			version2[v2_untilDot] = '.';
		}

		if (v1_size > 0 && v2_size > 0 && v1_part != v2_part) {
			return v1_part > v2_part ? 1 : -1;
		}

		version1 += v1_untilDot + 1;
		v1_size -= v1_untilDot + 1;
		version2 += v2_untilDot + 1;
		v2_size -= v2_untilDot + 1;

		if (!v1_untilDot && !v2_untilDot) {
			return 0;
		} else if (!v1_untilDot && v2_part != 0) {
			return -1;
		} else if (!v2_untilDot && v1_part != 0) {
			return 1;
		}

		v1_untilDot = 0;
		v2_untilDot = 0;
	}

    return 0;
}
