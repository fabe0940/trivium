#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define KEY_LEN 80

void usage(char* name);

int main(int argc, char** argv) {
	int i;
	char* fname;
	FILE* fout;

	/* Check for necessary number of arguments */
	if (argc != 2) {
		usage(argv[0]);
		exit(0);
	}

	/* Capture arguments */
	fname = argv[1];

	/* Seed PRNG */
	srand((int) getpid());

	/* Open output file */
	fout = fopen(fname, "w");
	if (fout == NULL) {
		fprintf(stderr, "unable to open file: %s\n", fname);
	}

	/* Write output file */
	for (i = 0; i < KEY_LEN; i++) {
		fprintf(fout, "%i", rand() % 2);
	}

	/* Close output file */
	fclose(fout);

	exit(0);
}

void usage(char* name) {
	/* Print usage information */
	fprintf(stdout, "Usage: %s <FILE>\n", name);
	fprintf(stdout, "Generate a key for the Trivium cipher.\n\n");
	fprintf(stdout, "  FILE\tThe file to write the key to.\n");
}
