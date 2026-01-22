#include <stdbool.h>
#include <string.h>

bool isSubsequence(char* s, char* t) {
    int slen, tlen;
	slen = strlen(s);
	tlen = strlen(t);
	int si = 0;
	
	if (!tlen && !slen) return true;
	if (!tlen) return false;
	if (!slen) return true;
	if (slen > tlen) return false;

	for (int i=0; i <= tlen; i++) {
		if (si == slen) { return true; }

		if (i == tlen) return false;
		if (t[i] == s[si]) {
			si++;
		}
	}

	return false;
}
