#ifndef _LFSR_H_
#define _LFSR_H_

struct lfsr {
	int len;
	int* vals;
};

typedef struct lfsr* lfsrPtr;

lfsrPtr lfsrInit(int len, int* vals);
int lfsrClock(lfsrPtr lfsr);

#endif
