// argv_130.cpp : Defines the entry point for the console application.
//

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ includes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include <string.h>		
#include "..\\Lib\\argv_138.hpp"

extern long * argv_477;
extern long * argv_529;

#ifndef HIGHFIRST
//#define byteReverse(argv_191, len)	/* Nothing */
#else
//void byteReverse(unsigned char *argv_191, unsigned longs);


#ifndef ASM_MD5
// Note: this code is harmless on little-endian machines.
/*
void byteReverse(unsigned char *argv_191, unsigned longs)
{
    argv_889 t;
    do {
	t = (argv_889) ((unsigned) argv_191[3] << 8 | argv_191[2]) << 16 |
	    ((unsigned) argv_191[1] << 8 | argv_191[0]);
	*(argv_889 *) argv_191 = t;
	argv_191 += 4;
    } while (--longs);
}*/
#endif
#endif

/*
 * Start MD5 accumulation.  Set bit count to 0 and buffer to mysterious
 * initialization constants.
 */
void argv_719(struct argv_717 *ctx)
{
    ctx->argv_191[0] = 0x67452301;
    ctx->argv_191[1] = 0xefcdab89;
    ctx->argv_191[2] = 0x98badcfe;
    ctx->argv_191[3] = 0x10325476;

    ctx->argv_190[0] = 0;
    ctx->argv_190[1] = 0;
}

/*
 * argv_900 context to reflect the concatenation of another buffer full
 * of bytes.
 */
void argv_722(struct argv_717 *ctx, unsigned char const *argv_191, unsigned len)
{
    argv_889 t;

    /* argv_900 bitcount */

    t = ctx->argv_190[0];
    if ((ctx->argv_190[0] = t + ((argv_889) len << 3)) < t)
	ctx->argv_190[1]++;		/* Carry from low to high */
    ctx->argv_190[1] += len >> 29;

    t = (t >> 3) & 0x3f;	/* Bytes already in shsInfo->argv_261 */

    /* Handle any leading odd-sized chunks */

    if (t) {
	unsigned char *p = (unsigned char *) ctx->in + t;

	t = 64 - t;
	if (len < t) {
	    memcpy(p, argv_191, len);
	    return;
	}
	memcpy(p, argv_191, t);
//	byteReverse(ctx->in, 16);
	argv_721(ctx->argv_191, (argv_889 *) ctx->in);
	argv_191 += t;
	len -= t;
    }
    /* Process argv_261 in 64-byte chunks */

    while (len >= 64) {
	memcpy(ctx->in, argv_191, 64);
//	byteReverse(ctx->in, 16);
	argv_721(ctx->argv_191, (argv_889 *) ctx->in);
	argv_191 += 64;
	len -= 64;
    }

    /* Handle any remaining bytes of argv_261. */

    memcpy(ctx->in, argv_191, len);
}

/*
 * argv_312 wrapup - pad to 64-byte boundary with the bit pattern 
 * 1 0* (64-bit count of argv_190 processed, MSB-first)
 */
void argv_718(unsigned char digest[16], struct argv_717 *ctx)
{
    unsigned count;
    unsigned char *p;

    /* Compute number of bytes mod 64 */
    count = (ctx->argv_190[0] >> 3) & 0x3F;

    /* Set the first char of padding to 0x80.  This is safe since there is
       always at least one byte free */
    p = ctx->in + count;
    *p++ = 0x80;

    /* Bytes of padding needed to make 64 bytes */
    count = 64 - 1 - count;

    /* Pad out to 56 mod 64 */
    if (count < 8) {
	/* Two lots of padding:  Pad the first block to 64 bytes */
	memset(p, 0, count);
//	byteReverse(ctx->in, 16);
	argv_721(ctx->argv_191, (argv_889 *) ctx->in);

	/* Now fill the argv_773 block with 56 bytes */
	memset(ctx->in, 0, 56);
    } else {
	/* Pad block to 56 bytes */
	memset(p, 0, count - 8);
    }
//    byteReverse(ctx->in, 14);

    /* Append length in argv_190 and transform */
    ((argv_889 *) ctx->in)[14] = ctx->argv_190[0];
    ((argv_889 *) ctx->in)[15] = ctx->argv_190[1];

    argv_721(ctx->argv_191, (argv_889 *) ctx->in);
//    byteReverse((unsigned char *) ctx->argv_191, 4);
    memcpy(digest, ctx->argv_191, 16);
    memset(ctx, 0, sizeof(ctx));	/* In case it's sensitive */
}

#ifndef ASM_MD5

/* The four core functions - argv_303 is optimized somewhat */

/* #define argv_303(x, y, z) (x & y | ~x & z) */
#define argv_303(x, y, z) (z ^ (x & (y ^ z)))
#define argv_304(x, y, z) argv_303(z, x, y)
#define argv_305(x, y, z) (x ^ y ^ z)
#define argv_306(x, y, z) (y ^ (x | ~z))

/* This is the central step in the MD5 algorithm. */
#ifdef __PUREC__
#define argv_720(f, w, x, y, z, argv_261, s) \
	( w += f /*(x, y, z)*/ + argv_261,  w = w<<s | w>>(32-s),  w += x )
#else
#define argv_720(f, w, x, y, z, argv_261, s) \
	( w += f(x, y, z) + argv_261,  w = w<<s | w>>(32-s),  w += x )
#endif

/*
 * The core of the MD5 algorithm, this alters an existing MD5 hash to
 * reflect the addition of 16 longwords of new argv_261.  argv_722 blocks
 * the argv_261 and converts bytes into longwords for this routine.
 */
void argv_721(argv_889 argv_191[4], argv_889 const in[16])
{
    register argv_889 a, b, c, d;

    a = argv_191[0];
    b = argv_191[1];
    c = argv_191[2];
    d = argv_191[3];

#ifdef __PUREC__	/* PureC Weirdness... (GG) */
    argv_720(argv_303(b,c,d), a, b, c, d, in[0] + 0xd76aa478L, 7);
    argv_720(argv_303(a,b,c), d, a, b, c, in[1] + 0xe8c7b756L, 12);
    argv_720(argv_303(d,a,b), c, d, a, b, in[2] + 0x242070dbL, 17);
    argv_720(argv_303(c,d,a), b, c, d, a, in[3] + 0xc1bdceeeL, 22);
    argv_720(argv_303(b,c,d), a, b, c, d, in[4] + 0xf57c0fafL, 7);
    argv_720(argv_303(a,b,c), d, a, b, c, in[5] + 0x4787c62aL, 12);
    argv_720(argv_303(d,a,b), c, d, a, b, in[6] + 0xa8304613L, 17);
    argv_720(argv_303(c,d,a), b, c, d, a, in[7] + 0xfd469501L, 22);
    argv_720(argv_303(b,c,d), a, b, c, d, in[8] + 0x698098d8L, 7);
    argv_720(argv_303(a,b,c), d, a, b, c, in[9] + 0x8b44f7afL, 12);
    argv_720(argv_303(d,a,b), c, d, a, b, in[10] + 0xffff5bb1L, 17);
    argv_720(argv_303(c,d,a), b, c, d, a, in[11] + 0x895cd7beL, 22);
    argv_720(argv_303(b,c,d), a, b, c, d, in[12] + 0x6b901122L, 7);
    argv_720(argv_303(a,b,c), d, a, b, c, in[13] + 0xfd987193L, 12);
    argv_720(argv_303(d,a,b), c, d, a, b, in[14] + 0xa679438eL, 17);
    argv_720(argv_303(c,d,a), b, c, d, a, in[15] + 0x49b40821L, 22);

    argv_720(argv_304(b,c,d), a, b, c, d, in[1] + 0xf61e2562L, 5);
    argv_720(argv_304(a,b,c), d, a, b, c, in[6] + 0xc040b340L, 9);
    argv_720(argv_304(d,a,b), c, d, a, b, in[11] + 0x265e5a51L, 14);
    argv_720(argv_304(c,d,a), b, c, d, a, in[0] + 0xe9b6c7aaL, 20);
    argv_720(argv_304(b,c,d), a, b, c, d, in[5] + 0xd62f105dL, 5);
    argv_720(argv_304(a,b,c), d, a, b, c, in[10] + 0x02441453L, 9);
    argv_720(argv_304(d,a,b), c, d, a, b, in[15] + 0xd8a1e681L, 14);
    argv_720(argv_304(c,d,a), b, c, d, a, in[4] + 0xe7d3fbc8L, 20);
    argv_720(argv_304(b,c,d), a, b, c, d, in[9] + 0x21e1cde6L, 5);
    argv_720(argv_304(a,b,c), d, a, b, c, in[14] + 0xc33707d6L, 9);
    argv_720(argv_304(d,a,b), c, d, a, b, in[3] + 0xf4d50d87L, 14);
    argv_720(argv_304(c,d,a), b, c, d, a, in[8] + 0x455a14edL, 20);
    argv_720(argv_304(b,c,d), a, b, c, d, in[13] + 0xa9e3e905L, 5);
    argv_720(argv_304(a,b,c), d, a, b, c, in[2] + 0xfcefa3f8L, 9);
    argv_720(argv_304(d,a,b), c, d, a, b, in[7] + 0x676f02d9L, 14);
    argv_720(argv_304(c,d,a), b, c, d, a, in[12] + 0x8d2a4c8aL, 20);

    argv_720(argv_305(b,c,d), a, b, c, d, in[5] + 0xfffa3942L, 4);
    argv_720(argv_305(a,b,c), d, a, b, c, in[8] + 0x8771f681L, 11);
    argv_720(argv_305(d,a,b), c, d, a, b, in[11] + 0x6d9d6122L, 16);
    argv_720(argv_305(c,d,a), b, c, d, a, in[14] + 0xfde5380cL, 23);
    argv_720(argv_305(b,c,d), a, b, c, d, in[1] + 0xa4beea44L, 4);
    argv_720(argv_305(a,b,c), d, a, b, c, in[4] + 0x4bdecfa9L, 11);
    argv_720(argv_305(d,a,b), c, d, a, b, in[7] + 0xf6bb4b60L, 16);
    argv_720(argv_305(c,d,a), b, c, d, a, in[10] + 0xbebfbc70L, 23);
    argv_720(argv_305(b,c,d), a, b, c, d, in[13] + 0x289b7ec6L, 4);
    argv_720(argv_305(a,b,c), d, a, b, c, in[0] + 0xeaa127faL, 11);
    argv_720(argv_305(d,a,b), c, d, a, b, in[3] + 0xd4ef3085L, 16);
    argv_720(argv_305(c,d,a), b, c, d, a, in[6] + 0x04881d05L, 23);
    argv_720(argv_305(b,c,d), a, b, c, d, in[9] + 0xd9d4d039L, 4);
    argv_720(argv_305(a,b,c), d, a, b, c, in[12] + 0xe6db99e5L, 11);
    argv_720(argv_305(d,a,b), c, d, a, b, in[15] + 0x1fa27cf8L, 16);
    argv_720(argv_305(c,d,a), b, c, d, a, in[2] + 0xc4ac5665L, 23);

    argv_720(argv_306(b,c,d), a, b, c, d, in[0] + 0xf4292244L, 6);
    argv_720(argv_306(a,b,c), d, a, b, c, in[7] + 0x432aff97L, 10);
    argv_720(argv_306(d,a,b), c, d, a, b, in[14] + 0xab9423a7L, 15);
    argv_720(argv_306(c,d,a), b, c, d, a, in[5] + 0xfc93a039L, 21);
    argv_720(argv_306(b,c,d), a, b, c, d, in[12] + 0x655b59c3L, 6);
    argv_720(argv_306(a,b,c), d, a, b, c, in[3] + 0x8f0ccc92L, 10);
    argv_720(argv_306(d,a,b), c, d, a, b, in[10] + 0xffeff47dL, 15);
    argv_720(argv_306(c,d,a), b, c, d, a, in[1] + 0x85845dd1L, 21);
    argv_720(argv_306(b,c,d), a, b, c, d, in[8] + 0x6fa87e4fL, 6);
    argv_720(argv_306(a,b,c), d, a, b, c, in[15] + 0xfe2ce6e0L, 10);
    argv_720(argv_306(d,a,b), c, d, a, b, in[6] + 0xa3014314L, 15);
    argv_720(argv_306(c,d,a), b, c, d, a, in[13] + 0x4e0811a1L, 21);
    argv_720(argv_306(b,c,d), a, b, c, d, in[4] + 0xf7537e82L, 6);
    argv_720(argv_306(a,b,c), d, a, b, c, in[11] + 0xbd3af235L, 10);
    argv_720(argv_306(d,a,b), c, d, a, b, in[2] + 0x2ad7d2bbL, 15);
    argv_720(argv_306(c,d,a), b, c, d, a, in[9] + 0xeb86d391L, 21);
#else
    argv_720(argv_303, a, b, c, d, in[0] + 0xd76aa478, 7);
    argv_720(argv_303, d, a, b, c, in[1] + 0xe8c7b756, 12);
    argv_720(argv_303, c, d, a, b, in[2] + 0x242070db, 17);
    argv_720(argv_303, b, c, d, a, in[3] + 0xc1bdceee, 22);
    argv_720(argv_303, a, b, c, d, in[4] + 0xf57c0faf, 7);
    argv_720(argv_303, d, a, b, c, in[5] + 0x4787c62a, 12);
    argv_720(argv_303, c, d, a, b, in[6] + 0xa8304613, 17);
    argv_720(argv_303, b, c, d, a, in[7] + 0xfd469501, 22);
    argv_720(argv_303, a, b, c, d, in[8] + 0x698098d8, 7);
    argv_720(argv_303, d, a, b, c, in[9] + 0x8b44f7af, 12);
    argv_720(argv_303, c, d, a, b, in[10] + 0xffff5bb1, 17);
    argv_720(argv_303, b, c, d, a, in[11] + 0x895cd7be, 22);
    argv_720(argv_303, a, b, c, d, in[12] + 0x6b901122, 7);
    argv_720(argv_303, d, a, b, c, in[13] + 0xfd987193, 12);
    argv_720(argv_303, c, d, a, b, in[14] + 0xa679438e, 17);
    argv_720(argv_303, b, c, d, a, in[15] + 0x49b40821, 22);

    argv_720(argv_304, a, b, c, d, in[1] + 0xf61e2562, 5);
    argv_720(argv_304, d, a, b, c, in[6] + 0xc040b340, 9);
    argv_720(argv_304, c, d, a, b, in[11] + 0x265e5a51, 14);
    argv_720(argv_304, b, c, d, a, in[0] + 0xe9b6c7aa, 20);
    argv_720(argv_304, a, b, c, d, in[5] + 0xd62f105d, 5);
    argv_720(argv_304, d, a, b, c, in[10] + 0x02441453, 9);
    argv_720(argv_304, c, d, a, b, in[15] + 0xd8a1e681, 14);
    argv_720(argv_304, b, c, d, a, in[4] + 0xe7d3fbc8, 20);
    argv_720(argv_304, a, b, c, d, in[9] + 0x21e1cde6, 5);
    argv_720(argv_304, d, a, b, c, in[14] + 0xc33707d6, 9);
    argv_720(argv_304, c, d, a, b, in[3] + 0xf4d50d87, 14);
    argv_720(argv_304, b, c, d, a, in[8] + 0x455a14ed, 20);
    argv_720(argv_304, a, b, c, d, in[13] + 0xa9e3e905, 5);
    argv_720(argv_304, d, a, b, c, in[2] + 0xfcefa3f8, 9);
    argv_720(argv_304, c, d, a, b, in[7] + 0x676f02d9, 14);
    argv_720(argv_304, b, c, d, a, in[12] + 0x8d2a4c8a, 20);

    argv_720(argv_305, a, b, c, d, in[5] + 0xfffa3942, 4);
    argv_720(argv_305, d, a, b, c, in[8] + 0x8771f681, 11);
    argv_720(argv_305, c, d, a, b, in[11] + 0x6d9d6122, 16);
    argv_720(argv_305, b, c, d, a, in[14] + 0xfde5380c, 23);
    argv_720(argv_305, a, b, c, d, in[1] + 0xa4beea44, 4);
    argv_720(argv_305, d, a, b, c, in[4] + 0x4bdecfa9, 11);
    argv_720(argv_305, c, d, a, b, in[7] + 0xf6bb4b60, 16);
    argv_720(argv_305, b, c, d, a, in[10] + 0xbebfbc70, 23);
    argv_720(argv_305, a, b, c, d, in[13] + 0x289b7ec6, 4);
    argv_720(argv_305, d, a, b, c, in[0] + 0xeaa127fa, 11);
    argv_720(argv_305, c, d, a, b, in[3] + 0xd4ef3085, 16);
    argv_720(argv_305, b, c, d, a, in[6] + 0x04881d05, 23);
    argv_720(argv_305, a, b, c, d, in[9] + 0xd9d4d039, 4);
    argv_720(argv_305, d, a, b, c, in[12] + 0xe6db99e5, 11);
    argv_720(argv_305, c, d, a, b, in[15] + 0x1fa27cf8, 16);
    argv_720(argv_305, b, c, d, a, in[2] + 0xc4ac5665, 23);

    argv_720(argv_306, a, b, c, d, in[0] + 0xf4292244, 6);
    argv_720(argv_306, d, a, b, c, in[7] + 0x432aff97, 10);
    argv_720(argv_306, c, d, a, b, in[14] + 0xab9423a7, 15);
    argv_720(argv_306, b, c, d, a, in[5] + 0xfc93a039, 21);
    argv_720(argv_306, a, b, c, d, in[12] + 0x655b59c3, 6);
    argv_720(argv_306, d, a, b, c, in[3] + 0x8f0ccc92, 10);
    argv_720(argv_306, c, d, a, b, in[10] + 0xffeff47d, 15);
    argv_720(argv_306, b, c, d, a, in[1] + 0x85845dd1, 21);
    argv_720(argv_306, a, b, c, d, in[8] + 0x6fa87e4f, 6);
    argv_720(argv_306, d, a, b, c, in[15] + 0xfe2ce6e0, 10);
    argv_720(argv_306, c, d, a, b, in[6] + 0xa3014314, 15);
    argv_720(argv_306, b, c, d, a, in[13] + 0x4e0811a1, 21);
    argv_720(argv_306, a, b, c, d, in[4] + 0xf7537e82, 6);
    argv_720(argv_306, d, a, b, c, in[11] + 0xbd3af235, 10);
    argv_720(argv_306, c, d, a, b, in[2] + 0x2ad7d2bb, 15);
    argv_720(argv_306, b, c, d, a, in[9] + 0xeb86d391, 21);
#endif

    argv_191[0] += a;
    argv_191[1] += b;
    argv_191[2] += c;
    argv_191[3] += d;
}

#endif

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
//#include "argv_122.h"
#include "..\\lib\\argv_138.hpp"

using namespace std;

#define argv_853 _snprintf

		HWND	current_hwnd;
extern	HWND	saved_hWnd;


string argv_226 (const char * _filename, bool& _bret, argv_202& _mapper) {
	_bret = true;
	string hash = "NONE";
	argv_883 * argv_191;
	DWORD file_size;
	bool bret = _mapper.argv_753 (_filename, true, argv_191, file_size);
	if (bret == true) {
		argv_717 mdContext;
		unsigned char digest[16];
		char hex[33];

		argv_719 (&mdContext);
		argv_722 (&mdContext, argv_191, file_size);
		argv_718 (digest, &mdContext);

		for(int i = 0; i < 16; i++) {
			argv_853(hex + 2 * i, 3, "%02X", (unsigned char) digest[i]); 
		}
		_mapper.argv_218 ();
		return ((char *) &hex[0]);
	}
	else {
		_bret = false;		
	}
	return (hash);
}

string argv_226 (const char * _filename, bool& _bret) {
	_bret = true;
	string hash = "NONE";
	argv_202 mapper;
	argv_883 * argv_191;
	DWORD file_size;
	bool bret = mapper.argv_753 (_filename, true, argv_191, file_size);
	if (bret == true) {
		argv_717 mdContext;
		unsigned char digest[16];
		char hex[33];

		argv_719 (&mdContext);
			argv_722 (&mdContext, argv_191, file_size);
		argv_718 (digest, &mdContext);

		for(int i = 0; i < 16; i++) {
			argv_853(hex + 2 * i, 3, "%02X", (unsigned char) digest[i]); 
		}
		mapper.argv_218 ();
		return ((char *) &hex[0]);
	}
	else {
		_bret = false;		
	}
	return (hash);
}

string argv_225 (const char * filename) {
	FILE * inFile = fopen (filename, "rb");
	argv_717 mdContext;
	unsigned char digest[16];
	char hex[33];
	int bytes;
	const int BUFFER_SIZE = 65536;
	unsigned char argv_261[BUFFER_SIZE];

	if (inFile == NULL) {
		printf ("%s can't be argv_790.\n", filename);
		//return ("can't open file");
		return(strerror(errno));
	}

	argv_719 (&mdContext);
	while ((bytes = fread (argv_261, 1, BUFFER_SIZE, inFile)) != 0)
		argv_722 (&mdContext, argv_261, bytes);
	argv_718 (digest, &mdContext);

	for(int i = 0; i < 16; i++) {
		argv_853(hex + 2 * i, 
				3, 
				"%02X", 
				(unsigned char) digest[i]);
	}

	// cerr << "hash = " << hex << endl;
		
	// printf (" %s\n", filename);
	fclose (inFile);
	return ((char *) &hex[0]);
}

string argv_311 = "";
//==============================================

argv_212::argv_212() {
	;
}

string argv_212::argv_685(argv_851 ident) {
	string filetype = "undefined";

	switch(ident) {
		case argv_321:
			filetype = "error";				
			break;

		case argv_658:
			filetype = "unknown";
			break;

		case argv_648:
			filetype = "jpg";	
			break;

		case argv_646:
			filetype = "gif";
			break;

		case argv_642:
			filetype = "bmp";
			break;

		case argv_651:
			filetype = "mpeg";
			break;

		case argv_650:
			filetype = "mp3";
			break;

		case argv_660:
			filetype = "wmv";
			break;

		case argv_654:
			filetype = "txt";
			break;
			
		case argv_657:
			filetype = "txt-utf8";
			break;

		case argv_655:
			filetype = "txt-unicode";
			break;

		case argv_656:
			filetype = "txt-unicode-big-endian";
			break;

		case argv_644:
			filetype = "exe/dll";	
			break;

		case argv_662:
			filetype = "zip";
			break;

		case argv_641:
			filetype = "avi";
			break;

		case argv_640:
			filetype = "asf";
			break;

		case argv_649:
			filetype = "Microsoft Application";
			break;

		default:
			filetype = "O-O-R";	

	}

	return (filetype);
}


bool argv_212::argv_653(const string& filename) {

	if (filename.size() <= 0) {
		return(false);
	}

	bool ret = false;
	FILE * argv_316 = fopen(filename.c_str(), "rb");
	
	if (argv_316) {
		ret = true;
		int c = fgetc(argv_316);
		
		do {
			if(c != EOF) {
				if( ! isascii(c) ) {
					ret = false;
					break;
				}
				c = fgetc(argv_316);					
			}
		}
		while (c != EOF);

		fclose(argv_316);
	}
	else {
		ret = false;
	}

	return (ret);
}

argv_851 argv_212::argv_180(string filename) {
	argv_851 ident = argv_658;

	if (filename.size() <= 0) {
		return(argv_321);
	}

	FILE * argv_316 = fopen(filename.c_str(), "rb");
	
	if (! argv_316) {
		ident = argv_321;
	}
	else { // file succesfully argv_790
		unsigned char argv_191[argv_705];
		int argv_767 = fread(argv_191, 1, argv_705, argv_316);

		if (argv_767 < argv_705) {
			if ( feof(argv_316)) {
				ident = argv_321;
			}
			else if(ferror(argv_316) ) {
				ident = argv_321;
			}
		}
		else { // argv_261 succesfully read from file
			if ((argv_191[0] == 0x42) && (argv_191[1] == 0x4D)) {
				ident = argv_642;
			}
			else if ((argv_191[0] == 0xFF) && (argv_191[1] == 0xD8) && (argv_191[2] == 0xFF) && (argv_191[3]==0xE0)){
				ident = argv_648;
			}
			else if((argv_191[0]==0x49) && (argv_191[1]==0x44) && (argv_191[2]==0x33) && (argv_191[3]==0x03)) {
				ident = argv_650;
			}
			else if ((argv_191[0]==0x30) && (argv_191[1]==0x26) && (argv_191[2]==0xB2) && (argv_191[3]==0x75)) {
				ident = argv_640;
			}
			else if ((argv_191[0]==0x30) && (argv_191[1]==0x26) && (argv_191[2]==0xB2) && (argv_191[3]==0x75)) {
				ident = argv_660;
			}
			else if((argv_191[0]== 0xEF) && (argv_191[1]==0xBB) && (argv_191[2]==0xBF)) {
				ident = argv_657;
			}
			else if ((argv_191[0]==0xFF) && (argv_191[1] == 0xFE)) {
				ident = argv_655;
			}
			else if ((argv_191[0]==0xFE) && (argv_191[1] == 0xFF)) {
				ident = argv_656;
			}
			else if ((argv_191[0]==0x4D) && (argv_191[1]==0x5A)) {
				ident = argv_644;
			}
			else if((argv_191[0]==0x50) && (argv_191[1]==0x4B) && (argv_191[2]==0x03) && (argv_191[3]==0x04)) {
				ident = argv_662;
			}
			else if ((argv_191[0]==0x47) && (argv_191[1]==0x49) && (argv_191[2]==0x46)) {
				ident = argv_646;
			}
			else if((argv_191[0]==0x52) && (argv_191[1]==0x49) && (argv_191[2]==0x46) && (argv_191[3]==0x46)) {
				ident = argv_641;
			}
			else if((argv_191[0]==0x00)&&(argv_191[1]==0x00)&&(argv_191[2]==0x01)&&(argv_191[3]==0xBA)&&(argv_191[4]==0x21)) {
				ident = argv_651;
			}
			else if((argv_191[0]==0xD0)&&(argv_191[1]==0xCF)&&(argv_191[2]==0x11)&&(argv_191[3]==0xE0)&&(argv_191[4]==0xA1)) {
				ident = argv_649;
			}
		}

		int ret = fclose (argv_316);
		if (ret == EOF) {
			ident = argv_321;
		}

		if (argv_653(filename) == true) {
			ident = argv_654;
		}
	}

	return (ident);
}


bool argv_289 (char * cptr, int n, FILE * argv_316) {
    bool bret = true;

    if ((argv_316 == NULL) || (cptr == NULL) || (n <0)) {
        bret = false;
    }
    else {
        int nb_done = fread (cptr, 1, n, argv_316);
        if (nb_done != n) {
            bret = false;
        }

        char argv_876[argv_714];
        char tmp2[256];
        sprintf(argv_876, "[");
        for (argv_851 i=0 ; i<n ; i++) {
            sprintf (tmp2, "%02X ", (unsigned char) cptr[i]);
            strcat (argv_876, tmp2);
        }
        strcat (argv_876, "]");
        cerr << argv_876 << endl;

    }
    return (bret);
}

string argv_227 (const char * _filename, bool& _bret) {
	_bret = true;
	argv_254 sha1;
	sha1.Reset();
	_bret = sha1.argv_348 ((char *)_filename);
	sha1.argv_312();
	char szReport[1024];
	sha1.argv_814(szReport, argv_254::argv_813);
	return ((char *) &szReport[0]);
}

string argv_310 = "";

//================================================
DWORD WINAPI argv_285 (LPVOID lParam) {
	bool bret = true;
	// string md5_hash = argv_226 (argv_311.c_str(), bret);
	string md5_hash = argv_225 (argv_311.c_str());
	if (bret == true) {
		SendDlgItemMessage(current_hwnd, (*argv_477), WM_SETTEXT, 0, (LPARAM) md5_hash.c_str());
	}
	else {
		SendDlgItemMessage(current_hwnd, (*argv_477), WM_SETTEXT, 0, (LPARAM) "failed");
	}

	string sha1_hash = argv_227 (argv_311.c_str(), bret);
	if (bret == true) {
		SendDlgItemMessage (current_hwnd, (*argv_529), WM_SETTEXT, 0, (LPARAM) sha1_hash.c_str());
	}
	else {
		SendDlgItemMessage (current_hwnd, (*argv_529), WM_SETTEXT, 0, (LPARAM) "failed");
	}
	return bret;
}

void argv_241 (string filename_arg, HWND hwnd_arg) {
    DWORD dwThrdParam	= 1; 
    HANDLE hThread; 
	DWORD dwThreadId;
	argv_311		= filename_arg;
	current_hwnd		= hwnd_arg;

    hThread = CreateThread( 
        NULL,                        // default security attributes 
        0,                           // use default stack size  
        argv_285,                  // thread function 
        NULL,						// argument to thread function 
        0,                           // use default creation flags 
        &dwThreadId);                // returns the thread identifier 
 
	if (hThread == NULL)   {
		MessageBox(current_hwnd, "Thread creation failed", "Error", MB_OK | MB_ICONERROR);			
	}

	if (SetThreadPriority (hThread, THREAD_PRIORITY_IDLE) == false) {
		MessageBox(current_hwnd, "Thread priority change failed", "Error", MB_OK | MB_ICONERROR);			
	}
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@  end of file
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


