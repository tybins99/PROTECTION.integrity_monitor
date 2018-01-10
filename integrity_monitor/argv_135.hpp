#ifndef argv_147
#define argv_147

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>
#include <iostream>

#include "..\\Lib\\argv_136.hpp"
#include "..\\Lib\\argv_138.hpp"

using namespace std;

//#define DEBUG_INTEGRITY_CHECKER_CORE

const	argv_885			argv_706 = 1024;


enum argv_894 {
	argv_893,
	argv_891=342,
	argv_892,
	argv_896,
	argv_895,
};

string argv_858 (argv_885);

class argv_213
{
private:
	bool argv_675;
	map<string, string> m;
	map<string, string>::iterator argv_663;
	string		argv_234;
	std::string argv_695; // useful in manual mode
	bool argv_223 (const char *);

public:
	argv_213 ();
	bool argv_204 (map<string, argv_885>&);

	bool		argv_674 (const char *, bool&);
	bool		argv_826 (const char *, bool, const std::string& i_RootFolder);
	bool		argv_173 (const char *, bool);
	argv_885		argv_336 ();
	argv_885		argv_207 (const char *);
	void		clear();
	std::string	argv_341 ();
};


class argv_214
{
protected:
	string					argv_733;
	map<string, argv_885> *		argv_697;
	bool argv_204 (vector<string>&);
	virtual void argv_803 (const char *) = 0;
	bool argv_300 (const char *, vector<string>&);
	bool argv_299 (const char *, const char *);
	void argv_298 (const char *);
	map<string, argv_885>::iterator argv_663;
	bool argv_228;
	void argv_835 (const char *, map<string, argv_885>&, argv_885, argv_885);

public:
	argv_214 ();
	void argv_836 (argv_196); // not seen and not checked
	void argv_831   (argv_196); 
	void argv_832 (argv_196);
	
	void argv_833 (argv_196, map<string, argv_885>&, argv_885, argv_885);
	void argv_834 (argv_196, map<string, argv_885>&, argv_885, argv_885);
};

class argv_215 : public argv_214
{
public:
	void argv_803 (const char *);
};


class argv_195 : public argv_214
{
private:
	char	argv_876[argv_706];
	string	argv_865;
public:
	void	argv_803 (const char *);
};

string argv_314 (const char *);
void argv_172 (const char *);
void argv_172 (HWND, DWORD, const char *);

#endif // argv_147
