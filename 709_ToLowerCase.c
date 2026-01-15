char* toLowerCase(char* s) {
    for (unsigned int i=0; s[i] != 0; i++) {
		if (s[i] >= 65 && s[i] <= 90) {
			s[i] += 32;
		}
	}
	return s;
}
