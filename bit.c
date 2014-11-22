#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#include "common.h"

int isPowerOf2(int n)
{
	/* if n is power of 2, it must be only one set bit in binary presation,
	 * so  (n - 1) must be all set bit . if n is 0x100, then n- 1 is 0xff
	 */
	return (n && (!(n & (n - 1))));
}

/* if n is 4, getSetBit return 3 ,mean the 3rd bit is one */
int getSetBit(int n)
{
	if (!isPowerOf2(n))
		return -1;
	int count = 0;
	while (n){
		n = n >> 1;
		++count;
	}
	return count;
}

/* if n is 0b00100001,then 0010 and 0001 are two nibbles */
uint8_t swapNibbles(uint8_t n)
{
	return ( (n & 0x0f) << 4 | (n &0xf0) >> 4);
}
