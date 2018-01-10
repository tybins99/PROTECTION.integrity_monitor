#ifndef argv_716
#define argv_716

#include <string>
#include "..\\Lib\\argv_137.hpp"
#include "..\\Lib\\argv_142.hpp"

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ namespace usage declaration
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
using namespace std;

#ifdef __alpha
typedef unsigned int argv_889;
#else
typedef unsigned long argv_889;
#endif

#define argv_851			signed int
#define argv_321	-1
#define argv_235	32

extern		argv_216			argv_684;
const argv_851	argv_714		= 65536;

struct argv_717 {
	argv_889 argv_191[4];
	argv_889 argv_190[2];
	unsigned char in[64];
};

void argv_719(struct argv_717 *context);
void argv_722(struct argv_717 *context, unsigned char const *argv_191,
	       unsigned len);
void argv_718(unsigned char digest[16], struct argv_717 *context);
void argv_721(argv_889 argv_191[4], argv_889 const in[16]);

/*
 * This is needed to make RSAREF happy on some MS-DOS compilers.
 */
typedef struct argv_717 argv_715;

enum argv_309 {
	argv_658 = 1000,
	argv_648,
	argv_646,
	argv_642,
	argv_651,
	argv_650,
	argv_660,
	argv_654,
	argv_657,
	argv_655,
	argv_656,
	argv_644,
	argv_662,
	argv_641,
	argv_640,
	argv_649,
};

class argv_212 {
private:
	bool argv_653(const string&);

public:
	argv_212();
	argv_851 argv_180 (string);
	string argv_685(argv_851);
};

bool argv_289 (char * cptr, int n, FILE * argv_316);
string argv_225 (const char *);
string argv_226 (const char *, bool&);
string argv_226 (const char *, bool&, argv_202&);



#endif /* !argv_716 */



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@  end of file
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

