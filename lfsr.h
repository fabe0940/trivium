#ifndef _LFSR_H_
#define _LFSR_H_

#include "varArray.h"

struct lfsr {
	varArrayPtr bits;
	varArrayPtr fb;
};
typedef struct lfsr* lfsrPtr;

lfsrPtr lfsrInit(int bitLen, int* bitVals, int fbLen, int* fbVals);
int lfsrClock(lfsrPtr lfsr);

#endif
