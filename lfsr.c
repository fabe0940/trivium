#include <stdlib.h>
#include "lfsr.h"
#include "util.h"
#include "varArray.h"

lfsrPtr lfsrInit(int fb, int ff, struct pair a, int len, int* vals) {
	lfsrPtr ptr;

	utilLog("--- lfsrInit() ---");

	utilLog("allocating shift register");
	ptr = malloc(sizeof(struct lfsr));
	if (ptr == NULL) {
		utilError("unable to allocate shift register");
	}

	utilLog("allocating shift register contents");
	ptr->feedback = fb;
	ptr->feedforward = ff;
	ptr->and = a;
	ptr->bits = varArrayInit(len, vals);

	return ptr;
}

int lfsrOutput(lfsrPtr lfsr) {
	int out;

	out = 0;
	out += lfsr->bits->vals[lfsr->feedforward];
	out += lfsr->bits->vals[(lfsr->and).left] * lfsr->bits->vals[(lfsr->and).right];
	out += lfsr->bits->vals[lfsr->bits->len - 1];
	out = out % 2;

	return out;
}

void lfsrShift(lfsrPtr lfsr, int input) {
	int i;

	for (i = 1 ; i < lfsr->bits->len ; i++) {
		lfsr->bits->vals[i] = lfsr->bits->vals[i - 1];
	}

	lfsr->bits->vals[0] = (lfsr->bits->vals[lfsr->feedback] + input) % 2;

	return;
}
