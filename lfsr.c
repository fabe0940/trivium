#include <stdlib.h>
#include "lfsr.h"
#include "util.h"
#include "varArray.h"

int _lfsrNextBit(lfsrPtr lfsr);

int _lfsrNextBit(lfsrPtr lfsr) {
	int i;
	int sum;

	utilLog("--- _lfsrNextBit() ---");

	sum = 0;
	for (i = 0; i < lfsr->fb->len ; i++) {
		sum += lfsr->bits->vals[lfsr->fb->vals[i]];
	}

	return sum % 2;
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
	int i;
	int last;
	int next;

	utilLog("--- lfsrClock() ---");

	last = lfsr->bits->vals[0];
	next = _lfsrNextBit(lfsr);

	for (i = 0 ; i < lfsr->bits->len - 1 ; i++) {
		lfsr->bits->vals[i] = lfsr->bits->vals[i + 1];
	}
	lfsr->bits->vals[lfsr->bits->len - 1] = next;

	return last;
}
