#include <stdbool.h>
#include <string.h>

bool isAnagram(char* s, char* t) {
	int lettersUse[26];
	memset(lettersUse, 0, 26*(sizeof(int)));
	unsigned long ctr = 0;
	
	while (s+ctr != (void*)0 && s[ctr] != (char)0) {
		lettersUse[s[ctr++]-97]++;
	}

	ctr = 0;
	while (t+ctr != (void*)0 && t[ctr] != (char)0) {
		if (lettersUse[t[ctr++]-97]-- == 0) {
			return false;
		}
	}
	for (int i=0; i < 26; i++) {
		if (lettersUse[i] != 0) return false;
	}

	return true;
}
