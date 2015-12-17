#include <stdlib.h>
#include <stdio.h>
#include "lfsr.h"
#include "util.h"

int main(int argc, char** argv) {
	int i;
	int len;
	int* vals;
	lfsrPtr lfsr;

	if (argc > 0) {
		for (i = 0; i < argc ; i++) {
			fprintf(stdout, "%i: %s\n", i, argv[i]);
		}
	}

	len = 1;
	vals = malloc(len * sizeof(int));
	if(vals == NULL) {
		error("unable to allocate vals");
	}

	for (i = 0 ; i < len ; i++) {
		vals[i] = 0;
	}

	lfsr = lfsrInit(len, vals);

	for (i = 0 ; i < 10; i++) {
		lfsrClock(lfsr);
	}

	exit(0);
}
