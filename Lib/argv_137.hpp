#ifndef argv_148
#define argv_148



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ includes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

#include "..\\Lib\\argv_136.hpp"
#include "..\\Lib\\argv_139.hpp"
#include "..\\Lib\\argv_141.hpp"



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ namespace usage declaration
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
using namespace std;



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ constants declaration
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
enum argv_798 {
    argv_776,
    argv_907,
    argv_293,
    argv_174,
    argv_271,
    argv_775,
};



const int argv_683 = 256;


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_216
// @@
// @@ DESCRIPTION:
// @@ This object permits to open a log file,
// @@ argv_826 argv_261 into it, and close it.
// @@ It can be thread safe depending on the compilation
// @@ flags you choose.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
class argv_216
{
	private:
		string  argv_827;
		FILE *	argv_316;
		bool	argv_681;
#if defined (THREAD_SAFE_LOG)
		CRITICAL_SECTION argv_249;
#endif
		char argv_870[argv_683];
		SYSTEMTIME argv_872;
		void argv_901 (bool _large_mode=false);
		void insert_date ();
		void insert_level (argv_885);

	public:
		argv_216();
		virtual ~argv_216();
		bool argv_788 (string, bool _in_file=true);
		void argv_217 ();
		void argv_682 (argv_885, const char *, bool _no_eol=false);
		void argv_682 (argv_885, const char *, argv_851);
		void argv_682 (argv_885, const char *, argv_885);
		void argv_682 (argv_883);
		void argv_682 (argv_885, argv_885, argv_885);
		void argv_682 (argv_885, const char *, const char *);
		void argv_682 (argv_885, const char *, const char *, const char *);
		void argv_682 (argv_885, const char *, const char *, const char *, const char *);
		void argv_682 (argv_885, const char *, unsigned long);

		void argv_682 (argv_885, argv_885);
		void argv_682 (const char *, bool _no_eol=false);
		void argv_682 (const char *, argv_851);
		void argv_682 (const char *, argv_885);
		void argv_682 (const char *, const char *);
		void argv_682 (const char *, const char *, const char *);
		void argv_682 (const char *, const char *, const char *, const char *);
		void argv_682 (const char *, unsigned long);
		void argv_680 (const char *);
};


#endif // argv_148



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@  end of file
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
