#include <stdlib.h>
#include <stdio.h>
#include "lfsr.h"
#include "util.h"

int main(int argc, char** argv) {
	int i;
	int bits[3] = {0, 1, 0};
	int fb[3] = {0, 2};
	lfsrPtr lfsr;

	if (argc > 0) {
		for (i = 0; i < argc ; i++) {
			fprintf(stdout, "%i: %s\n", i, argv[i]);
		}
	}

	lfsr = lfsrInit(3, bits, 2, fb);

	fprintf(stdout, "\ni | output\n-----------\n");
	for (i = 1 ; i <= 25; i++) {
		fprintf(stdout, "%2i: %i\n", i, lfsrClock(lfsr));
	}

	exit(0);
}
