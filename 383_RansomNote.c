#include <stdbool.h>
#include <string.h>

static int charCount(int *clist, char c) {
	return clist[c-'a'];
}

static int cutChar(int *clist, char c) {
	return ++(clist[c-'a']);
}

bool canConstruct(char* ransomNote, char* magazine) {
    int ransomSize = strlen(ransomNote);
	int magazineSize = strlen(magazine);

	if (ransomSize > magazineSize) return false;

	int rnlist[26] = {0};
	int mglist[26] = {0};

	for (int i=0; i < magazineSize; i++) {
		cutChar(mglist, magazine[i]);
	}
	for (int i=0; i < ransomSize; i++) {
		if (!(cutChar(rnlist, ransomNote[i]) <= charCount(mglist, ransomNote[i])))
			return false;
	}

	return true;
}
