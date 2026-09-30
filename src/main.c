#include <stdio.h>
#include <stdlib.h>
#include <analyzer.h>

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <input_file>
", argv[0]);
		return EXIT_FAILURE;
	}

	char *input_file = argv[1];
	FILE *file = fopen(input_file, "r");
	if (!file) {
		perror("Failed to open file");
		return EXIT_FAILURE;
	}

	analyze_file(file);
	fclose(file);

	return EXIT_SUCCESS;
}