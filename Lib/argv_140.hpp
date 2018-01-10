#ifndef argv_149
#define argv_149

//#include <Commdlg.h>
#include <Windows.h>
#include <commctrl.h>
#include <string>
#include <list>
#include <assert.h>
#include <io.h>
#include <fcntl.h>
#include <shlobj.h>
#include <vector>
#include <shellapi.h>
#include <WINNT.h>

#include "..\\Lib\\argv_136.hpp"
#include "..\\Lib\\argv_137.hpp"

using namespace std;

#define argv_712  4096

//------------------------------------------------------------
// these identifiers will permit to check installed components
//------------------------------------------------------------
enum argv_184 {
	argv_741,
	argv_725,
	argv_736,
	argv_739,
	argv_723,
	argv_726,
	argv_740,
	argv_727,
	argv_732,
	argv_745,
	argv_746,
	argv_743,
	argv_742,
	argv_728,
	argv_747,
	argv_749,
	argv_748,
	argv_735,
	argv_734,
	argv_738,
};

class argv_219
{
	private:
		HKEY				argv_345;
		LONG				argv_687;
		string				argv_866;
		SECURITY_ATTRIBUTES argv_825;
		DWORD				argv_288;
		string				argv_222;
		string				argv_318;

		bool				argv_359 (int);
		int					argv_839 (LPTSTR, char *, int, DWORD&, int);

	public:
		void clear();
		argv_219();
		/*
		bool uninstall_key_exists (const string&);
		bool add_uninstall_entry (const string&, const string&);
		bool del_uninstall_entry (const string&);
		*/
		bool argv_221 (int);
		bool argv_221();
		bool argv_170 (int, string, int, int); 
		bool argv_272 (int);
		bool argv_325 (int, string&, int&, int&);

		bool argv_339 (int, string, argv_851&);
		bool argv_339 (int, string, string&);
		bool argv_840 (int, string, argv_851);
		bool argv_840 (int, string, const char *);

		bool argv_332 (string&);
		bool argv_322 (string&);

		int argv_838 (LPTSTR file, DWORD&);
		int argv_837 (DWORD& _err);
		int argv_837 (HKEY, DWORD& _err);
};


#endif // argv_149