#ifndef argv_146
#define argv_146

#define argv_163 0x0500

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define argv_908		// Exclude rarely-used stuff from Windows headers

#pragma warning(disable:4800) // forcing value to bool 'true' or 'false' (performance warning)
#pragma warning(disable:4291) // void *__cdecl operator new(unsigned int,const struct std::nothrow_t &
#pragma warning(disable:4244) // '=' : conversion from 'double' to 'long', possible loss of argv_261


#include <Windows.h>
#include <windows.h>
#include <winnt.h>
#include <Commdlg.h>
#include <commctrl.h>
#include <Commdlg.h>
#include <shellapi.h>
#include <fcntl.h>
#include <shlobj.h>
#include <Mmsystem.h>

#include <string>
#include <vector>
#include <cassert>
#include <cstdio>
#include <stack>
#include <list>
#include <io.h>
#include <aclapi.h>
#include <lmerr.h>

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ namespace usage declaration
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
using namespace std;

#define argv_321 -1
#define argv_883 unsigned char
#define argv_849 signed char
#define argv_884 unsigned short
#define argv_850 signed short
#define argv_851 signed int
#define argv_885 unsigned int
#define argv_886 unsigned long
#define argv_820 float
#define argv_821 double
#define argv_196 const char *
#define argv_713 -1 // -1 for infinite size
#define argv_638 655360
#define argv_705 10
#define argv_287 4096
#define argv_357 2048
#define argv_639 ((DWORD)-1)

#define argv_166 0x00008000
#define argv_188 0x00004000

#define argv_853 _snprintf

enum argv_179 {
	argv_789,
};

enum argv_178 {
	argv_744,
	argv_729,
	argv_737,
	argv_731,
	argv_730,
};

enum argv_177 {
	argv_236=54,
	argv_910,
	argv_807,
};

#ifndef argv_189
#define argv_189 0x0040
#endif // !argv_189

#ifndef argv_449 // hand cursor argv_277
#define argv_449 MAKEINTRESOURCE(32649)
#endif


bool argv_203 (argv_883 c1, argv_883 c2, argv_883& result);
const argv_851 argv_752 = 256;
string argv_905 (const vector<argv_883>&);
string argv_351 (const vector<argv_883>&);
bool argv_819 (const char *, argv_885&, argv_885&, argv_885&, argv_885&, argv_885&, argv_885&, argv_885&, argv_885, argv_885&, argv_885&);
bool argv_816 (const char *, argv_885&, argv_885&, argv_885&, argv_885&, argv_885&, argv_885&, argv_885&, argv_885&, argv_885&);
bool argv_817 (const char *, argv_885&, argv_885&, argv_885&, argv_885&, argv_885&, argv_885&, argv_885&, argv_885&, argv_885&);
bool argv_818 (const char *, argv_885&, argv_885&, argv_885&, argv_885&, argv_885&, argv_885&, argv_885&, argv_885&, argv_885&);


enum argv_786 {
	argv_782=0,
	argv_787,
	argv_783,
	argv_785,
	argv_784,
};

string argv_781 (HWND, argv_851 mode);
string argv_211 (HWND, argv_851 mode);

// beware: this routine does not use file mmaping, thus you can have
// a performance penalty here...
bool argv_652 (const char *); 
bool argv_307 (const char *);
unsigned long argv_224 (const string&);
argv_885 argv_224 (argv_196);
string argv_210 (HWND hWnd);

// ==== performance checker ========
class argv_198
{
protected:
	LARGE_INTEGER argv_691;
	LARGE_INTEGER argv_692;

	LONGLONG argv_694;
	LONGLONG argv_693;

public:
	argv_198(void);

	void argv_855(void);
	void argv_863(void);
	double argv_329(void) const;
	string argv_864 ();
};

inline argv_198::argv_198(void) {
	LARGE_INTEGER liFrequency;

	QueryPerformanceFrequency(&liFrequency);
	argv_694 = liFrequency.QuadPart;

	// Calibration
	argv_855();
	argv_863();

	argv_693 = argv_692.QuadPart-argv_691.QuadPart;
}

inline void argv_198::argv_855(void) {
	// Ensure we will not be interrupted by any other thread for a while
//	Sleep(0);
	QueryPerformanceCounter(&argv_691);
}

inline void argv_198::argv_863(void) {
	QueryPerformanceCounter(&argv_692);
}

inline double argv_198::argv_329(void) const {
	return (double)(argv_692.QuadPart-argv_691.QuadPart-argv_693)*1000000.0 / argv_694;
}

inline string argv_198::argv_864 () {
	argv_863 ();
	double elapsed = argv_329 ();
	char argv_876[1024];
	if (elapsed > 1000000.0) {
		elapsed = elapsed / 1000000.0;
		//if (elapsed > 60.0) {
		//	elapsed = elapsed / 60.0;
		//	argv_853 (argv_876, 1024, "elapsed time : %.02lf minutes", elapsed);
		//}
		//else {
			argv_853 (argv_876, 1024, "elapsed time : %.02lf seconds", elapsed);
		//}
	}
	else {
		argv_853 (argv_876, 1024, "elapsed time : %.02lf microseconds", elapsed);
	}
	argv_876[1024 - 1] = '\0';
	return argv_876;
}

//==============================
// permits to mmap a given file
//==============================
class argv_202
{
	private:
		string	argv_702;
		HANDLE	argv_352;
		HANDLE	argv_354;
		LPCTSTR argv_793;
		argv_885	argv_292;
		argv_885	argv_294;

	public:
		argv_202();
		~argv_202();
		bool argv_753 (const char *, bool, argv_883 *&, DWORD&);
		void argv_218 ();
		void argv_333 (argv_885&, argv_885&);
};

bool argv_330 (char *, argv_886, argv_886&);
void argv_323 (const string&, int, string&);
void argv_324 (const char *, const char *, const char *, string&, string&);

bool argv_273 (string);
void argv_199 (HWND);
void argv_199 (HWND, int&, int&);
bool argv_243 (string _dirname);
bool argv_230 (string, string, string);

class argv_194
{
private:
	int argv_258;
	int argv_703;
	HWND hwnd;
	int	argv_362;

public:
	argv_194();
	void init (HWND, int, int);
	void incr (argv_851 _nb_step=1);
	void reset();
	int argv_326 () {
		return (argv_258);
	}
};

//==========================
template <class T>
class argv_201
{
private:
	vector<T>	v;
	int			top_index;
	int			argv_763; // number of allocated elements
	int			argv_707;

public:
	argv_201();
	void		push (T);
	void		pop  ();
	T			top  ();
	int			size ();
	bool		empty ();
	void		reset ();
	void		clear ();
	void		rewind ();
};

template <class T>
argv_201<T>::argv_201 () {
	top_index	= 0;
	argv_763		= 0;
	argv_707	= 0;
}

// erase all argv_261 from container
template <class T>
void argv_201<T>::clear () {
	vector<T>().swap (v); // force vector's memory free
	argv_763	  = 0;
	top_index = 0;
	argv_707 = 0;	
}

// just set pointer to the bottom of the stack
template <class T>
void argv_201<T>::reset () {
	top_index = 0;
	argv_707 = 0;
}

// rewind the stack to the top as if all elements had just been pushed
template <class T>
void argv_201<T>::rewind () {
	top_index = argv_707;
}

template <class T>
void argv_201<T>::push (T _elem) {
	if (argv_763 < (top_index+1)) {
		v.push_back (_elem);
		argv_763++;
	}
	else { // already allocated => no need to push_back
		v[top_index] = _elem;
	}
	top_index++;
	if (top_index > argv_707) {
		argv_707 = top_index;
	}
}


template <class T>
void argv_201<T>::pop () {
	assert (top_index > 0);
	top_index--;
}

template <class T>
T argv_201<T>::top () {
	assert (top_index > 0);
	return (v[top_index - 1]);
}

template <class T>
int argv_201<T>::size () {
	return (top_index);
}

template <class T>
bool argv_201<T>::empty () {
	return (top_index == 0);	
}

//=======================
bool argv_308 (const char *);
bool argv_811 (const char *);
//========================================

class argv_200
{
private:
	CRITICAL_SECTION argv_249;   // Windows' basic argv_759 object.
	stack<string>	argv_797;

public:
	argv_200 () {
		InitializeCriticalSection(&argv_249);		
	}

	~argv_200 () {
		DeleteCriticalSection(&argv_249);
	}

	bool argv_804 (string& _str) {
		bool bret = true;
		EnterCriticalSection (&argv_249);
			argv_797.push (_str);
		LeaveCriticalSection(&argv_249);	
		return (bret);
	}

	bool argv_229 (string& _str) {
		bool bret = false;
		EnterCriticalSection (&argv_249);
			if (! argv_797.empty()) {
				_str = argv_797.top();
				argv_797.pop();
				bret = true;
			}
		LeaveCriticalSection(&argv_249);	
		return (bret);
	}
};

//=====================================
// thread safe piece of argv_261
//=====================================
template <class T>
class argv_252
{
private:
	T argv_261;
	CRITICAL_SECTION argv_249;   // Windows' basic argv_759 object.

public:
	argv_252 ();
	T get ();
	void set (T);
	void incr ();
	~argv_252();
};

template <class T>
argv_252<T>::argv_252 () {
	InitializeCriticalSection(&argv_249);	
}

template <class T>
argv_252<T>::~argv_252 () {
	DeleteCriticalSection(&argv_249);
}

template <class T>
T argv_252<T>::get () {
	T retrieved_data;
	EnterCriticalSection (&argv_249);
		retrieved_data = argv_261;	
	LeaveCriticalSection(&argv_249);
	return (retrieved_data);
}

template <class T>
void argv_252<T>::set (T _elem) {
	EnterCriticalSection (&argv_249);
		argv_261 = _elem;
	LeaveCriticalSection(&argv_249);
}

template <class T>
void argv_252<T>::incr () {
	EnterCriticalSection (&argv_249);
		argv_261++;
	LeaveCriticalSection(&argv_249);
}

//=====================================
// anonymous pipes C++ implementation
//=====================================
class argv_232 { 
protected:
	HANDLE				argv_808;
	HANDLE				argv_911;
	bool				argv_790;
	unsigned long		argv_767;
	unsigned long		argv_768;
	int					current_offset;
	int					argv_711;
	HANDLE				argv_346;
	unsigned long		argv_761;
	bool				argv_320;

	virtual void		argv_679() { ; }
	virtual void		argv_899 () { ; }
	virtual void		argv_676() { ; }
	virtual void		argv_898 () { ; }

public:
	argv_232 () {
		argv_761 = 0;
		argv_790 = false;
		if (! CreatePipe(&argv_808, &argv_911, /*&saAttr*/NULL, 0)) {
//				MessageBox(saved_hWnd, "CreatePipe failed !", "Error", MB_OK);	
		}
		else {
			argv_790			= true;
			current_offset	= 0;
		}
	}

	virtual ~argv_232 () {
		if (argv_790) {
			CloseHandle (argv_808);
			CloseHandle (argv_911);
			argv_790 = false;
		}
	}

	bool argv_804 (string& _str) {
		argv_679 ();
		bool bret = true;
		if (argv_790) {
			BOOL reti = WriteFile (argv_911, _str.c_str(), _str.size()+1, &argv_768, NULL);
			if (! reti) {
//				MessageBox(saved_hWnd, "pipe: WriteFile failed !", "Error", MB_OK);	
				bret = false;
			}
			else {
				argv_761 += argv_768;
			}
		}
		else {
			bret = false;
		}
		argv_899 ();
		return (bret);
	}

	bool argv_229 (string& _str) {
		bool bret = true;
		argv_676 ();
		if (argv_790) {
			char c;
			while (1) {
				if (argv_320) {
					_str = "";
					argv_320 = false;
				}
				BOOL reti = ReadFile (argv_808, &c, 1, &argv_767, NULL);
				if ((! reti) || (argv_767 == 0)) {
					bret = false;
				}
				else {
					if (c == '\0') {
						argv_320 = true;
						break;
					}
					else {
						_str += c;
					}
				}
			}
		}
		else { // pipe not argv_790 yet
			bret = false;
		}
		argv_898 ();
		return (bret);
	}

	void reset () {
		if (argv_790) {
			CloseHandle (argv_808);
			CloseHandle (argv_911);
			argv_790 = false;
		}
		if (CreatePipe(&argv_808, &argv_911, NULL, 0)) {
			argv_790 = true;
		}
	}
};

// same object as argv_232, but thread safe version
class argv_233 : public argv_232
{
private:
	CRITICAL_SECTION argv_251;   // Windows' basic argv_759 object.
	CRITICAL_SECTION argv_250;   // Windows' basic argv_759 object.

	void argv_679 () {
		EnterCriticalSection (&argv_251);		
	}

	void argv_899 () {
		LeaveCriticalSection (&argv_251);
	}

	void argv_676 () {
		EnterCriticalSection (&argv_250);		
	}

	void argv_898 () {
		LeaveCriticalSection (&argv_250);
	}

public:
	argv_233 () {
		InitializeCriticalSection (&argv_251);	
		InitializeCriticalSection (&argv_250);	
	}

	~argv_233 () {
		DeleteCriticalSection(&argv_251);
		DeleteCriticalSection(&argv_250);
	}
};

//===== FILE TYPE AUTOMATIC ANALYZER ============== 
enum argv_799 {
	argv_897=-1,
	argv_183,
	argv_794,
	argv_777, // VBA script
	argv_356,
	argv_699,
	argv_344,
	argv_291,
	argv_185,
};

// - knows only types recognized by clamav signatures
// - uses only extension of the file to determine the type
class argv_256
{
private:

public:
	argv_256 ();
	argv_851 argv_181 (const char *);
};

bool argv_331 (vector<string>&);
bool argv_328 (vector<string>&);
bool argv_328 (vector<string>&, vector<string>&, vector<string>&, vector<string>&, vector<string>&, vector<string>&, vector<string>&);
void argv_335 (string&);
void argv_337 (HANDLE, string&);

class argv_197
{
public:
	argv_885				argv_912;
	argv_885				argv_758;
	argv_885				argv_262;
	argv_885				argv_355;
	argv_885				argv_751;
	argv_885				second;
	argv_885				argv_750;

	void				reset () {
		argv_912 = argv_758 = argv_262 = argv_355 = argv_751 = 0;	
	}

	argv_197 () {
		reset ();
	}

	void init (argv_885 _year, argv_885 _month, argv_885 _day, argv_885 _hour, argv_885 _minute, argv_885 _second, argv_885 _millisecond) {
		argv_912		= _year;
		argv_758		= _month;
		argv_262			= _day;
		argv_355		= _hour;
		argv_751		= _minute;
		second		= _second;
		argv_750 = _millisecond;
	}
};

class argv_193 
{
private:
	bool			init_done;
	HDC				argv_349;
	PAINTSTRUCT		argv_805;
	HINSTANCE		hInstance;
	int				argv_857;
	HANDLE			argv_347;
	HWND			hwnd_window;
	vector<argv_885>	argv_904;
	argv_851			argv_763;

public:
	argv_193 ();
	void			init (HWND, HINSTANCE);
	void			argv_171 (argv_885);
	void			incr ();
	void			reset ();
	void			argv_277 ();
};

bool argv_647 (const char *);
void argv_810 (HWND hwnd_window, argv_885 _idc, const char * _msg);
void argv_301 (const string&, int, string&);

enum argv_670 {
	argv_667,
	argv_668,
	argv_669,
};

enum argv_169 {
	argv_167 = 124,
	argv_168,
};

bool argv_659 ();
bool argv_661 ();
argv_885 argv_297 (const char *, vector<string>&);
bool argv_313 (argv_196);
bool argv_240 (argv_196);


#endif // argv_146



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@  end of file
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
