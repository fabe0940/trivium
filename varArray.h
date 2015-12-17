#ifndef _VAR_ARRAY_H_
#define _VAR_ARRAY_H_

struct varArray {
	int size;
	int* value;
};

struct varArray* varArrayInit(int size, int* value);

#endif
