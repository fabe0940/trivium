#include <stdlib.h>
#include <stdio.h>
#include "util.h"

void utilError(char* msg) {
	fprintf(stderr, "ERROR: %s\n", msg);
	fprintf(stderr, "exiting...\n");

	exit(1);
}

void utilWarning(char* msg) {
#ifdef DEBUG
	fprintf(stderr, "ERROR: %s\n", msg);
#endif

	return;
}

void utilLog(char* msg) {
#ifdef DEBUG
	fprintf(stderr, "LOG: %s\n", msg);
#endif

	return;
}
