#include <stdlib.h>
#include <stdio.h>
#include "lfsr.h"
#include "util.h"

int main(int argc, char** argv) {
	int i;

	if (argc > 0) {
		for (i = 0; i < argc ; i++) {
			fprintf(stdout, "%i: %s\n", i, argv[i]);
		}
	}

	exit(0);
}
