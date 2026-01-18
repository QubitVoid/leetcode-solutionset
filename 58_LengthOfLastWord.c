int lengthOfLastWord(char* s) {
	if (s == (void*)0) return 0;
	if (s[0] == 0) return 0;
	int length = 1;

    for (unsigned int i=1; s[i] != 0; i++) {
		if (s[i] == ' ') { }
		else if (s[i-1] == ' ') length = 0;
		if (s[i] != ' ') length++;
	}

	return length;
}
