#ifndef __SWAP_TOOLS_C
#define __SWAP_TOOLS_C

#include "leggi_binario_ALaDyn_fortran.h"


int is_big_endian(void)
{
	union {
		uint32_t i;
		char c[4];
	} bint = { 0x01020304 };

	return bint.c[0] == 1;
}



void swap_endian_s(short* in_s, int n)
{
	int i;
	union { short smio; char arr[2]; }x;
	char buff;

	for (i = 0; i < n; i++)
	{
		x.smio = in_s[i];
		buff = x.arr[0];
		x.arr[0] = x.arr[1];
		x.arr[1] = buff;
		in_s[i] = x.smio;
	}
}


void swap_endian_i(int* in_i, int n)
{
	int i;
	union { int imio; float fmio; char arr[4]; }x;
	char buff;
	for (i = 0; i < n; i++)
	{
		x.imio = in_i[i];
		buff = x.arr[0];
		x.arr[0] = x.arr[3];
		x.arr[3] = buff;
		buff = x.arr[1];
		x.arr[1] = x.arr[2];
		x.arr[2] = buff;
		in_i[i] = x.imio;
	}
}


void swap_endian_f(float* in_f, size_t n)
{
	size_t i;
	union { int imio; float fmio; char arr[4]; }x;
	char buff;
	for (i = 0; i < n; i++)
	{
		x.fmio = in_f[i];
		buff = x.arr[0];
		x.arr[0] = x.arr[3];
		x.arr[3] = buff;
		buff = x.arr[1];
		x.arr[1] = x.arr[2];
		x.arr[2] = buff;
		in_f[i] = x.fmio;
	}
}


void swap_endian_f(float* in_f, unsigned int n)
{
	unsigned int i;
	union { int imio; float fmio; char arr[4]; }x;
	char buff;
	for (i = 0; i < n; i++)
	{
		x.fmio = in_f[i];
		buff = x.arr[0];
		x.arr[0] = x.arr[3];
		x.arr[3] = buff;
		buff = x.arr[1];
		x.arr[1] = x.arr[2];
		x.arr[2] = buff;
		in_f[i] = x.fmio;
	}
}


void swap_endian_f(float* in_f, int n)
{
	int i;
	union { int imio; float fmio; char arr[4]; }x;
	char buff;
	for (i = 0; i < n; i++)
	{
		x.fmio = in_f[i];
		buff = x.arr[0];
		x.arr[0] = x.arr[3];
		x.arr[3] = buff;
		buff = x.arr[1];
		x.arr[1] = x.arr[2];
		x.arr[2] = buff;
		in_f[i] = x.fmio;
	}
}

#endif
