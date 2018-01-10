#ifndef argv_153
#define argv_153



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ includes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include "..\\Lib\\argv_136.hpp"



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ constants
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#define	argv_710	100



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ namespace usage declaration
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
using namespace std;

template <class T>
class argv_248
{
	bool	init_done;
	argv_885	argv_319;
	T *		argv_870;
	argv_885	argv_258;

public:
	argv_248 ();
	bool	argv_645 (); 
	bool	argv_643 (); 
	bool	init (argv_885);
	bool	top (T&);
	bool	argv_338 (T&);
	void	pop ();
	bool	push (const T&);
	argv_885	size ();
	~argv_248();
};

template <class T>
argv_248<T>::argv_248 () {
	init_done	= false;
	argv_870			= NULL;
	argv_319	= 0;
	argv_258		= 0;
}

template <class T>
argv_248<T>::~argv_248 () {
	if (argv_870 != NULL) {
		delete [] argv_870;
		argv_870			= NULL;
		init_done	= false;
	}
}

template <class T>
argv_885 argv_248<T>::size () {
	return (argv_258);
}

template <class T>
bool argv_248<T>::init (argv_885 _full_size) {
	bool bret = true;
	argv_319 = _full_size;
	argv_870 = new (std::nothrow) T[argv_319];
	if (argv_870 != NULL) {
		init_done = true;
	}
	else {
		bret = false;
	}
	return (bret);
}

template <class T>
bool argv_248<T>::argv_338 (T& _elem) {
	bool bret = true;
	if ((init_done == true) && (argv_258 > 0)) {
		_elem = argv_870[argv_258 - 1];
		argv_258--;
	}
	return (bret);
}

template <class T>
bool argv_248<T>::top (T& _elem) {
	bool bret = true;
	if ((init_done == true) && (argv_258 > 0)) {
		_elem = argv_870[argv_258 - 1];
	}
	return (bret);
}

template <class T>
void argv_248<T>::pop () {
	if (argv_258 > 0) {
		argv_258--; 
	}
}

template <class T>
bool argv_248<T>::push (const T& _elem) {
	bool bret = false;
	if ((init_done == true) && (argv_258 < argv_319)) {
		argv_870[argv_258] = _elem;
		argv_258++;
		bret = true;
	}
	return (bret);
}

template <class T>
bool argv_248<T>::argv_645 () {
	return (argv_258 == argv_319);
}

template <class T>
bool argv_248<T>::argv_643 () {
	return (argv_258 == 0);
}

/////////////////////////////////////////////
template <class T>
class argv_245
{
public:
	T argv_290;
	argv_245 * argv_802;
	argv_245 * argv_773;

	argv_245 () {
		argv_802 = argv_773 = NULL;
	}
};

/////////////////////////////////////////////
template <class T>
class argv_246
{
private:
	argv_248<argv_245<T> *>	argv_824;
	argv_245<T> *				argv_350;
	argv_245<T> *				argv_871;

public:
	argv_246 ();
	~argv_246 ();

	bool						init (argv_885);
	void						push_back (const T&);
	void						push_front (const T&);
	void						pop_back (T&);
	void						pop_front (T&);
	bool						argv_645 ();
	bool						argv_643 ();
	void						argv_277 ();
};


template <class T>
argv_246<T>::argv_246 () {
	argv_350 = argv_871 = NULL;
}

template <class T>
argv_246<T>::~argv_246 () {
	argv_245<T> * cell_ptr;
	while (argv_824.argv_643 () == false) {
		argv_824.argv_338 (cell_ptr);
		delete cell_ptr;
	}
}

template <class T>
void argv_246<T>::argv_277 () {
	char argv_876[256];
	char tmp2[256];
	argv_876[0] = '\0';
	argv_245<T> * cell_ptr = argv_350;
	if (cell_ptr == NULL) {
		strcat (argv_876, "(neel)");	
	}
	else {
		argv_853 (tmp2, 256, "[%u] ", cell_ptr->argv_290);
		tmp2[256 - 1] = '\0';
		strcat (argv_876, tmp2);
		while (cell_ptr != NULL) {
			cell_ptr = cell_ptr->argv_802;		
			if (cell_ptr != NULL) {
				argv_853 (tmp2, 256, "%u ", cell_ptr->argv_290);
				tmp2[256 - 1] = '\0';
				strcat (argv_876, tmp2);
			}
		}
	}
	MessageBox (NULL, argv_876, "", MB_OK);
}

template <class T>
bool argv_246<T>::init (argv_885 _full_size) {
	bool bret = true;
	bret = argv_824.init (_full_size);	
	if (bret == true) {
		argv_245<T> * cell_ptr;
		for (argv_885 i=0 ; i<_full_size ; i++) {
			cell_ptr = new (std::nothrow) argv_245<T>;
			if (cell_ptr == NULL) {
				bret = false;
				break;
			}
			argv_824.push (cell_ptr);
		}
	}
	return (bret);
}

template <class T>
void argv_246<T>::push_back (const T& _elem) {
	if (argv_824.argv_643 () == false) {
		argv_245<T> * cell_ptr;
		argv_824.argv_338 (cell_ptr);

		cell_ptr->argv_290 = _elem; // copy the element into the cell
		if ((argv_350 == NULL) && (argv_871 == NULL)) { // queue empty for now
			argv_350 = argv_871 = cell_ptr;	
		}
		else { // queue contains one or more elements
			cell_ptr->argv_773 = argv_871;
			argv_871->argv_802     = cell_ptr; 
			argv_871		   = cell_ptr;
		}
	}
}

template <class T>
void argv_246<T>::push_front (const T& _elem) {
	if (argv_824.argv_643 () == false) {
		argv_245<T> * cell_ptr;
		argv_824.argv_338 (cell_ptr);

		cell_ptr->argv_290 = _elem; // copy the element into the cell
		if ((argv_350 == NULL) && (argv_871 == NULL)) { // queue empty for now
			argv_350 = argv_871 = cell_ptr;	
		}
		else { // queue contains one or more elements
			cell_ptr->argv_802 = argv_350;
			argv_350->argv_773     = cell_ptr;
			argv_350		   = cell_ptr;
		}
	}
}

template <class T>
void argv_246<T>::pop_back (T& _elem) {
	if ((argv_350 != NULL) && (argv_871 != NULL)) {
		if (argv_350 == argv_871) { // contains only one element
			_elem = argv_871->argv_290;
			argv_824.push (argv_871);
			argv_350 = argv_871 = NULL;
		}
		else { // contains 2 or more elements
			argv_245<T> * cell_ptr = argv_871;
			(argv_871->argv_773)->argv_802 = NULL;
			argv_871 = argv_871->argv_773;
			_elem = cell_ptr->argv_290;
			argv_824.push (cell_ptr);
		}
	}
}

template <class T>
void argv_246<T>::pop_front (T& _elem) {
	if ((argv_350 != NULL) && (argv_871 != NULL)) {
		if (argv_350 == argv_871) {
			_elem = argv_350->argv_290;
			argv_824.push (argv_350);
			argv_350 = argv_871 = NULL;
		}
		else {
			argv_245<T> * cell_ptr = argv_350;
			(argv_350->argv_802)->argv_773 = NULL;
			argv_350 = argv_350->argv_802;
			_elem = cell_ptr->argv_290;
			argv_824.push (cell_ptr);
		}
	}
}

template <class T>
bool argv_246<T>::argv_645 () {
	return (argv_824.argv_643 ());
}

template <class T>
bool argv_246<T>::argv_643 () {
	return (argv_824.argv_645 ());
}


///////////////////////////////////////////////////////
template <class T>
class argv_247
{
private:
	bool					init_done;
	HANDLE					argv_759;
	HANDLE					argv_295;
	HANDLE					argv_296;
	argv_246<T>			argv_823;
	bool					argv_645 (); // not thread safe !!!!
	bool					argv_643 (); // not thread safe !!!!

public:
	argv_247 ();
	~argv_247 ();
	bool					init (argv_885);
	void					push_back (const T&);
	void					push_front (const T&);
	void					pop_back (T&);
	void					pop_front (T&);
};

template <class T>
argv_247<T>::argv_247 () {
	init_done	= false;
}

template <class T>
argv_247<T>::~argv_247 () {
	WaitForSingleObject (argv_759, INFINITE); // lock the argv_759
		CloseHandle (argv_295);
		CloseHandle (argv_296);
	ReleaseMutex (argv_759);
	CloseHandle (argv_759);
}

template <class T>
bool argv_247<T>::init (argv_885 _full_size) {
	bool bret = argv_823.init (_full_size);
	argv_759			= CreateMutex (NULL, FALSE, NULL);
	argv_295 = CreateEvent (NULL, TRUE, FALSE, NULL);
	argv_296	= CreateEvent (NULL, TRUE, FALSE, NULL);
	return (bret);
}

template <class T>
void argv_247<T>::push_back (const T& _data) {
	WaitForSingleObject (argv_759, INFINITE); // acquire argv_759
	while (argv_645 () == true) {
		SignalObjectAndWait (argv_759, argv_296, INFINITE, FALSE);
		WaitForSingleObject (argv_759, INFINITE);
	}
	argv_823.push_back (_data);	
	PulseEvent (argv_295);
	ReleaseMutex (argv_759);
}

template <class T>
void argv_247<T>::push_front (const T& _data) {
	WaitForSingleObject (argv_759, INFINITE); // acquire argv_759
	while (argv_645 () == true) {
		SignalObjectAndWait (argv_759, argv_296, INFINITE, FALSE);
		WaitForSingleObject (argv_759, INFINITE);
	}
	argv_823.push_front (_data);	
	PulseEvent (argv_295);
	ReleaseMutex (argv_759);
}

template <class T>
void argv_247<T>::pop_back (T& _data) {
	WaitForSingleObject (argv_759, INFINITE); // acquire argv_759
	while (argv_643 () == true) {
		SignalObjectAndWait (argv_759, argv_295, INFINITE, FALSE);
		WaitForSingleObject (argv_759, INFINITE);
	}
	argv_823.pop_back (_data);
	PulseEvent (argv_296);
	ReleaseMutex (argv_759);
}

template <class T>
void argv_247<T>::pop_front (T& _data) {
	WaitForSingleObject (argv_759, INFINITE); // acquire argv_759
	while (argv_643 () == true) {
		SignalObjectAndWait (argv_759, argv_295, INFINITE, FALSE);
		WaitForSingleObject (argv_759, INFINITE);
	}
	argv_823.pop_front (_data);
	PulseEvent (argv_296);
	ReleaseMutex (argv_759);
}

template <class T>
bool argv_247<T>::argv_645 () {
	return (argv_823.argv_645 ());
}

template <class T>
bool argv_247<T>::argv_643 () {
	return (argv_823.argv_643 ());
}
#endif // argv_153



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@  end of file
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@