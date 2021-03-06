#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ehandler(char* s, int exit_code)
{
	fprintf(stderr, "%s\n", s);
	exit(exit_code);
}

int main(int argc, char *argv[])
{
	FILE* fp = fopen("./input", "r");
	if (fp == NULL) {
		ehandler("Could not load ./input file", 1);
	}

	// Read data
	long num_valid = 0;
	int low;
	int high;
	char c;
	#define BUF_SIZE 256
	char s[BUF_SIZE] = {0};
	int count;
	for (int i = 0; fscanf(fp,"%d-%d %c: %s\n", &low, &high, &c, s) == 4; i++) {
		count = 0;
		for (int j = 0; j < BUF_SIZE && s[j] != '\0'; j++) {
			if (s[j] == c) { count++; }
		}
		if (low <= count && count <= high) { num_valid++; }
  }

	printf("num_valid=%ld\n", num_valid);

	// Cleanup
	fclose(fp);

	return 0;
}
