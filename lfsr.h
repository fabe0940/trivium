#ifndef _LFSR_H_
#define _LFSR_H_

#include "varArray.h"

struct pair {
	int left;
	int right;
};

struct lfsr {
	int feedback;
	int feedforward;
	struct pair and; 
	varArrayPtr bits;
};
typedef struct lfsr* lfsrPtr;

lfsrPtr lfsrInit(int len, int fb, int ff, int l, int r, int* vals);
int lfsrOutput(lfsrPtr lfsr);
void lfsrShift(lfsrPtr lfsr, int input);

#endif
