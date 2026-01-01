#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

char* addBinary(char* a, char* b) {
	unsigned int aSize = strlen(a), bSize = strlen(b);
	char *smaller = aSize <= bSize ? a : b;
	char *larger = aSize <= bSize ? b : a;
	unsigned int resultSize = strlen(larger);
	unsigned int smId = strlen(smaller) - 1;
    char *result = malloc(resultSize + 2);
	result[resultSize] = '\0';
	result[resultSize+1] = '\0';
	bool carry = 0;
	
	for (int i=resultSize-1; i >= 0; i--) {
		result[i] = larger[i];

		if (carry) {
			if (result[i] == '1') {
				carry = 1;
				result[i] = '0';
			} else {
				carry = 0;
				result[i] = '1';
			}
		}

		if (smaller[smId] == '1' && result[i] == '1') {
			carry = 1;
			result[i] = '0';
		} else if (smaller[smId] == '1') {
			result[i] = '1';
		}



		if (smId > 0) smId--;
		else smaller[smId] = '0';

		if (i == 0 && carry) {
			memmove(result+1, result, resultSize);
			resultSize++;
			result[0] = '1';
		}
	}

	return result;
}

int main() {
	char a[] = "1010";
	char b[] = "1011";
	char expected[] = "10101";

	printf("A: %s | B: %s\n", a, b);

	char *result = addBinary(a, b);

	if (strcmp(result, expected) == 0) {
		printf("Passed");
	} else {
		printf("Wrong");
	}

	printf(": Expected: %s | Got: %s\n", expected, result);

	free(result);
}
