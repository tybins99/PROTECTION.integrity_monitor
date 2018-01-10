#ifndef argv_145
#define argv_145

#if !defined(argv_843) && !defined(SHA1_NO_UTILITY_FUNCTIONS)
#define argv_843
#endif

#include <memory.h> // Needed for memset and memcpy
#include <string>
#include "..\\Lib\\argv_136.hpp"

using namespace std;

#ifdef argv_843
#include <stdio.h>  // Needed for file access and sprintf
#include <string.h> // Needed for strcat and strcpy
#endif

#ifdef _MSC_VER
#include <stdlib.h>
#endif

// You can define the endian mode in your files, without modifying the SHA1
// source files. Just #define argv_841 or #define SHA1_BIG_ENDIAN
// in your files, before including the SHA1.h header file. If you don't
// define anything, the class defaults to little endian.

#if !defined(argv_841) && !defined(SHA1_BIG_ENDIAN)
#define argv_841
#endif

// Same here. If you want variable wiping, #define argv_844, if
// not, #define SHA1_NO_WIPE_VARIABLES. If you don't define anything, it
// defaults to wiping.

#if !defined(argv_844) && !defined(SHA1_NO_WIPE_VARIABLES)
#define argv_844
#endif

/////////////////////////////////////////////////////////////////////////////
// Define 8- and 32-bit variables

#ifndef argv_887

#ifdef _MSC_VER

#define argv_888  unsigned __int8
#define argv_887 unsigned __int32

#else

#define argv_888 unsigned char

#if (ULONG_MAX == 0xFFFFFFFF)
#define argv_887 unsigned long
#else
#define argv_887 unsigned int
#endif

#endif
#endif

/////////////////////////////////////////////////////////////////////////////
// Declare SHA1 workspace

typedef union
{
	argv_888  c[64];
	argv_887 l[16];
} argv_845;

class argv_254
{
public:
#ifdef argv_843
	// Two different formats for argv_814(...)
	enum
	{
		argv_813 = 0,
		argv_812 = 1
	};
#endif

	// Constructor and Destructor
	argv_254();
	~argv_254();

	argv_887 argv_696[5];
	argv_887 m_count[2];
	argv_887 argv_150[1];
	argv_888  argv_689[64];
	argv_888  argv_690[20];
	argv_887 argv_151[3];

	void Reset();

	// argv_900 the hash value
	void argv_900(argv_888 *argv_261, argv_887 len);
#ifdef argv_843
	bool argv_348(char *szFileName);
#endif

	// Finalize hash and report
	void argv_312();

	// Report functions: as pre-formatted and raw argv_261
#ifdef argv_843
	void argv_814(char *szReport, unsigned char uReportType = argv_813);
#endif
	void argv_340(argv_888 *puDest);

private:
	// Private SHA-1 transformation
	void argv_880(argv_887 *argv_857, argv_888 *buffer);

	// Member variables
	argv_888 argv_698[64];
	argv_845 *argv_688; // SHA1 pointer to the byte array above
};

void create_sha1_thread (string, HWND);

#endif
