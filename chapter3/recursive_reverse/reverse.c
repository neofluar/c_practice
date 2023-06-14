void recursive_reverse(char [], int, int);
void swap(char [], int, int);

void recursive_reverse(char s[], int i, int j) {
	if (i >= j)
		return;
	recursive_reverse(s, i + 1, j - 1);
	swap(s, i, j);
}

void swap(char s[], int i, int j) {
	int temp;
	temp = s[i];
	s[i] = s[j];
	s[j] = temp;
}

