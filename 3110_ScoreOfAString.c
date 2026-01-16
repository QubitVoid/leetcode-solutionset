int scoreOfString(char* s) {
	int sum = 0;
	int whatever;
	for (unsigned int i=1; s[i] != 0; i++) {
		whatever = s[i-1] - s[i];
		if (whatever < 0) whatever*=-1;
		sum += whatever;
	}
	return sum;
}
