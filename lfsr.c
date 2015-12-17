#include <stdlib.h>
#include "lfsr.h"
#include "util.h"
#include "varArray.h"

int _lfsrNextBit(lfsrPtr lfsr);

int _lfsrNextBit(lfsrPtr lfsr) {
	int val;

	utilLog("--- _lfsrNextBit() ---");

	val = 0;
	/* finish me */

	return val;
}

lfsrPtr lfsrInit(int bitLen, int* bitVals, int fbLen, int* fbVals) {
	lfsrPtr ptr;

	utilLog("--- lfsrInit() ---");

	utilLog("allocating shift register");
	ptr = malloc(sizeof(struct lfsr));
	if (ptr == NULL) {
		utilError("unable to allocate shift register");
	}

	utilLog("allocating shift register contents");
	ptr->bits = varArrayInit(bitLen, bitVals);
	ptr->fb = varArrayInit(fbLen, fbVals);

	return ptr;
}

int lfsrClock(lfsrPtr lfsr) {
	int bit;
	int i;

	utilLog("--- lfsrClock() ---");

	bit = _lfsrNextBit(lfsr);

	for (i = 0 ; i < lfsr->bits->len - 1 ; i++) {
		(lfsr->bits->vals)[i] = (lfsr->bits->vals)[i + 1];
	}
	lfsr->bits->vals[lfsr->bits->len - 1] = bit;

	return bit;
}
