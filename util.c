#include <stdlib.h>
#include <stdio.h>
#include "util.h"

#ifdef DEBUG
#define DEBUG 1
#else
#define DEBUG 0
#endif

void utilError(char* msg) {
	fprintf(stderr, "ERR: %s\n", msg);
	fprintf(stderr, "exiting...\n");

	exit(1);
}

void utilWarning(char* msg) {
	if (DEBUG) {
		fprintf(stderr, "WARN: %s\n", msg);
	}

	return;
}

void utilLog(char* msg) {
	if (DEBUG) {
		fprintf(stderr, "LOG: %s\n", msg);
	}

	return;
}
