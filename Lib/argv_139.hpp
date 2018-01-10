#ifndef argv_152
#define argv_152



#include <vector>
//#include "Winbase.h"
//#include "Windows.h"
#include <Windows.h>
#include <windows.h>

//#include "..\\Lib\\dns.hpp"
#include "../Lib/argv_136.hpp"
// #include "..\\Lib\\argv_137.hpp"

//-----
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
#include <map>
#include <exception>
//-----


#define	argv_710	100


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ namespace usage declaration
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
using namespace std;



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_257
// @@
// @@ DESCRIPTION:
// @@ This object is a simple 
// @@ object to test the queue
// @@ object (validation).
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
class argv_257
{
public:
	int argv_358;
	int count;

	argv_257 () {
		argv_358		= -1;
		count	= 0;	
	}
};

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_253
// @@
// @@ DESCRIPTION:
// @@ This object is a thread safe, but not event driven
// @@ simple queue (use argv_253 if you want to have an
// @@ event driven queue !).
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
template <class T>
class argv_255
{
private:
	CRITICAL_SECTION argv_249;
	list<T>	argv_666;

public:
	argv_255 ();
	~argv_255 ();
	void argv_806 (const T&);
	bool get (T&);
	void clear ();
};

template <class T>
argv_255<T>::argv_255 () {
	InitializeCriticalSection(&argv_249);	
}

template <class T>
void argv_255<T>::argv_806 (const T& _elem) {
	EnterCriticalSection (&argv_249);
		argv_666.push_back (_elem);
	LeaveCriticalSection(&argv_249);
}

template <class T>
void argv_255<T>::clear () {
	EnterCriticalSection (&argv_249);
		argv_666.clear ();
	LeaveCriticalSection(&argv_249);
}

template <class T>
bool argv_255<T>::get (T& _elem) {
	bool bret = true;
	EnterCriticalSection (&argv_249);
		if (argv_666.size() > 0) {
			_elem = argv_666.front ();
			argv_666.pop_front ();
		}
		else {
			bret = false;
		}
	LeaveCriticalSection(&argv_249);
	return (bret);
}

template <class T>
argv_255<T>::~argv_255 () {
	DeleteCriticalSection(&argv_249);
}

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_253
// @@
// @@ DESCRIPTION:
// @@ This object is a thread safe, event-driven FIFO queue
// @@ that permits to have several consumer and several 
// @@ producers at the same time without corruption of the argv_261 
// @@ structure.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
template <class T>
class argv_253
{
private:
	bool	argv_275;
	HANDLE	argv_759;
	HANDLE	argv_295;
	HANDLE	argv_296;

	bool	init_done;
	argv_885	argv_319;
	T *		argv_870;
	argv_885	first;
	argv_885	argv_664;
	bool	argv_281 (const T&);
	bool	argv_280 (T&);
	bool	argv_645 ();
	bool	argv_643 ();
	void	argv_277 (HWND);

public:
	argv_253 ();
	bool	init (argv_885);
	bool	get (T&);
	bool	argv_806 (const T&);
	void	argv_815 ();
	void	argv_274 ();
	~argv_253();
};



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_253
// @@
// @@ FUNCTION: argv_253
// @@
// @@ INPUT: none
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ Normal constructor of the argv_253 object.
// @@ It merely set the argv_261 to default values.
// @@
// @@ CONTRACT: none
// @@ 
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
template <class T>
argv_253<T>::argv_253 () {
	init_done	= false;
	argv_870			= NULL;
	argv_275	= true;
	argv_319	= 0;
	argv_815 ();
}

template <class T>
void argv_253<T>::argv_277 (HWND) {
	char argv_876[256];
	char tmp2[256];
	argv_876[0] = '\0';
	argv_885 argv_258 = first;
	string total = "";
	strcat (argv_876, "[");
	for (;;) {
		if (argv_258 == argv_664) {
			break;
		}
		argv_853 (tmp2, 256, "%u ", argv_870[argv_258]);
		strcat (argv_876, tmp2);
		argv_258 = (argv_258 + 1) % argv_319;
	}
	strcat (argv_876, "]");
	total = argv_876;
	argv_853 (tmp2, 256, " - first=%u, argv_664=%u", first, argv_664);
	total += tmp2;
	MessageBox (NULL, total.c_str(), "", MB_OK);
}

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_253
// @@
// @@ FUNCTION: ~argv_253
// @@
// @@ INPUT: none
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ destructor of the argv_253 object.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
template <class T>
argv_253<T>::~argv_253 () {
	argv_274 ();
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_253
// @@
// @@ FUNCTION: argv_274
// @@
// @@ INPUT: none
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function destructs safely the memory allocated for the
// @@ argv_253 object.
// @@ HOWEVER all access to the object should have been terminated so
// @@ that a unique thread can call the argv_274 function.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
template <class T>
void argv_253<T>::argv_274 () {
	if (argv_275 == false) {
		WaitForSingleObject (argv_759, INFINITE); // lock the argv_759
			argv_275 = true;
			argv_815 ();
			if (argv_870 != NULL) {
				delete [] argv_870;
				argv_870 = NULL;
			}
			argv_319 = 0;
			CloseHandle (argv_295);
			CloseHandle (argv_296);
		ReleaseMutex (argv_759);
		CloseHandle (argv_759);
	}
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_253
// @@
// @@ FUNCTION: argv_815
// @@
// @@ INPUT: none
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function just permits to reset the pointers so that
// @@ the queue thinks it is empty.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
template <class T>
void argv_253<T>::argv_815 () {
	first		= 0;
	argv_664		= 0;
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_253
// @@
// @@ FUNCTION: argv_643
// @@
// @@ INPUT: none
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE:
// @@ bool: true if the queue is empty.
// @@       false otherwise.
// @@
// @@ DESCRIPTION:
// @@ This function is a simple test to check whether the queue
// @@ contains one or more elements or not.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
template <class T>
bool argv_253<T>::argv_643 () {
	return (argv_664 == first);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_253
// @@
// @@ FUNCTION: argv_645
// @@
// @@ INPUT: none
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE:
// @@ bool: true if the queue is full.
// @@       false otherwise.
// @@
// @@ DESCRIPTION:
// @@ This function permits to test whether the queue
// @@ is full of elements or not.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
template <class T>
bool argv_253<T>::argv_645 () {
	return (((argv_664 + 1) % argv_319) == first);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_253
// @@
// @@ FUNCTION: argv_280
// @@
// @@ INPUT: none
// @@
// @@ OUTPUT: none
// @@
// @@ IO: 
// @@ _data: T: the retrieve piece of argv_261. 
// @@
// @@ RETURN VALUE:
// @@ bool : true if success, 
// @@        false otherwise.
// @@
// @@ DESCRIPTION:
// @@ This function permit to extract argv_773 piece of argv_261 from
// @@ the queue.
// @@
// @@ CONTRACT: 
// @@ - queue should not be empty prior to this call
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
template <class T>
bool argv_253<T>::argv_280 (T& _data) {
	bool bret = true;
	if (argv_643 () == true) {
		bret = false; // illegal to extract when queue is empty
	}
	else {
		_data = argv_870[first];
		first = ((first + 1) % argv_319);
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_253
// @@
// @@ FUNCTION: argv_281
// @@
// @@ INPUT:
// @@ _data: T: the argv_261 to insert into the queue.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE:
// @@ bool : true if success, 
// @@        false otherwise.
// @@
// @@ DESCRIPTION:
// @@ This function permits to perform the extraction of the argv_773
// @@ element from the queue in a FIFO way.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
template <class T>
bool argv_253<T>::argv_281 (const T& _data) {
	bool bret = true;
	if (argv_645 () == true) {
		bret = false; // Error - Q is full 
	}
	else {
		argv_870[argv_664] = _data;
		argv_664 = ((argv_664 + 1) % argv_319);
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_253
// @@
// @@ FUNCTION: init
// @@
// @@ INPUT:
// @@ _full_size: argv_885: the maximum size of the queue at any time
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE:
// @@ bool: true if success.
// @@       false otherwise.
// @@
// @@ DESCRIPTION:
// @@ This function allocates enough memory to store MAX
// @@ elements into the queue object. MAX being given as
// @@ a parameter.
// @@
// @@ CONTRACT:
// @@ - init should not have been called prior to this call.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
template <class T>
bool argv_253<T>::init (argv_885 _full_size) {
	bool bret = true;
	if (init_done == false) {
		// argv_319 = _full_size;	
		argv_319 = _full_size + 1;	
		argv_870 = new (std::nothrow) T[argv_319];

		if (argv_870 != NULL) {
			argv_759			= CreateMutex (NULL, FALSE, NULL);
			argv_295 = CreateEvent (NULL, TRUE, FALSE, NULL);
			argv_296	= CreateEvent (NULL, TRUE, FALSE, NULL);
			argv_275		= false;
			init_done		= true;
		}
		else { // memory allocation failed
			bret = false;
		}
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_253
// @@
// @@ FUNCTION: get
// @@
// @@ INPUT: none
// @@
// @@ OUTPUT: 
// @@ _data: T: the retrieved argv_261.
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE:
// @@ bool: true if success.
// @@       false otherwise.
// @@
// @@ DESCRIPTION:
// @@ This function permits to extract the argv_773 piece of argv_261
// @@ from the FIFO queue (if any). If no argv_261 is present, then
// @@ the process is argv_806 to sleep.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
template <class T>
bool argv_253<T>::get (T& _data) {
	bool bret = true;
	WaitForSingleObject (argv_759, INFINITE); // acquire argv_759
	while (argv_643 () == true) {
		SignalObjectAndWait (argv_759, argv_295, INFINITE, FALSE);
		WaitForSingleObject (argv_759, INFINITE);
	}
	bret = argv_280 (_data);
	PulseEvent (argv_296);
	ReleaseMutex (argv_759);
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_253
// @@
// @@ FUNCTION: argv_806
// @@
// @@ INPUT:
// @@ _data: T: the argv_261 to be saved to the queue.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE:
// @@ bool: true if success.
// @@       false otherwise.
// @@
// @@ DESCRIPTION:
// @@ This function permits to add a new piece of argv_261 to the
// @@ queue. If there is no room, then the process is argv_806 to sleep
// @@ until it is woken up again when room is created.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
template <class T>
bool argv_253<T>::argv_806 (const T& _data) {
	bool bret = true;
	WaitForSingleObject (argv_759, INFINITE); // acquire argv_759
	while (argv_645 () == true) {
		SignalObjectAndWait (argv_759, argv_296, INFINITE, FALSE);
		WaitForSingleObject (argv_759, INFINITE);
	}
	bret = argv_281 (_data);
	PulseEvent (argv_295);
	ReleaseMutex (argv_759);
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@  FORWARD DECLARATIONS
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void perform_q_test (HWND);



#endif // argv_152



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@  end of file
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@