#include <stdlib.h>
#include "lfsr.h"
#include "util.h"

int _lfsrNextBit(lfsrPtr lfsr);

int _lfsrNextBit(lfsrPtr lfsr) {
	int val;

	log("--- _lfsrNextBit() ---");

	val = 0;
	/* finish me */

	return val;
}

lfsrPtr lfsrInit(int len, int* vals) {
	int i;
	lfsrPtr lfsr;

	log("--- lfsrInit() ---");

	log("allocating LFSR");
	lfsr = malloc(sizeof(struct lfsr));
	if (lfsr == NULL) {
		error("unable to allocate LFSR");
	}

	log("initializing LFSR");
	lfsr->len = len;
	lfsr->vals = malloc(sizeof(int) * len);
	if (lfsr->vals == NULL) {
		error("unable to allocate LFSR");
	}

	for (i = 0 ; i < len ; i++) {
		(lfsr->vals)[i] = vals[i];
	}

	return lfsr;
}

int lfsrClock(lfsrPtr lfsr) {
	int bit;
	int i;

	log("--- lfsrClock() ---");

	bit = _lfsrNextBit(lfsr);
	for (i = 0 ; i < lfsr->len - 1 ; i++) {
		(lfsr->vals)[i] = (lfsr->vals)[i + 1];
	}
	(lfsr->vals)[lfsr->len - 1] = bit;

	return bit;
}
