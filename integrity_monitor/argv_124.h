
#if !defined(argv_176)
#define argv_176

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "argv_122.h"
#include <string>
#include <vector>
#include <math.h>
#include <cstdio>
#include <string>
#include <list>
#include <map>
#include <Windows.h>
#include <windows.h>
#include <winnt.h>
#include <commctrl.h>
#include <string>
#include <assert.h>
#include <Wingdi.h>

#include "argv_135.hpp"
#include "..\\Lib\\argv_140.hpp"

using namespace std;

#define argv_708	128
#define argv_704			30000

#define argv_883	unsigned char
#define argv_849 	signed char
#define argv_884	unsigned short
#define argv_850	signed short
#define argv_885	unsigned int
#define argv_851	signed int
#define argv_886	unsigned long
#define argv_852	signed long


using namespace std;

void argv_199 (HWND);

// -db <path> -new <path> -modified <path> -create -check -auto <timeout_second>
class argv_231
{
public:
	string	argv_266;
	string	argv_770;
	string	argv_755;
	string	argv_874;
	argv_885	argv_875;

	bool	argv_269;
	bool	argv_267;	
	bool	argv_772;
	bool	argv_771;
	bool	argv_757;
	bool	argv_756;
	bool	argv_244;
	bool	argv_208;
	bool	argv_187;
	bool	argv_873;
	bool	argv_779;

	argv_231() {
		reset ();
	}

	void reset () {
		argv_266				= argv_770 = argv_755 = argv_874 = "";
		argv_875		= 0;
		argv_269		= argv_267 = argv_772 = false;
		argv_771	= argv_757 = argv_756 = false;
		argv_244	= argv_208 = argv_187 = argv_873 = false;
		argv_779			= false;
	}
};

enum argv_186 {
	argv_861  = 5478,
	argv_862,
	argv_860, 
	argv_859,
};


void argv_205 ();
void argv_890 ();


//===============================================================


#endif // !defined(argv_176)
