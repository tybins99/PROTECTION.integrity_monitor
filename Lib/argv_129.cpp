


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ includes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include "..\\Lib\\argv_137.hpp"


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ global declaration
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_216
// @@
// @@ FUNCTION: argv_216
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
// @@ Normal constructor of the argv_216 object.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
argv_216::argv_216() {
	argv_316			= NULL;
	argv_681	= true;
#if defined (THREAD_SAFE_LOG)
	InitializeCriticalSection (&argv_249);	
#endif
}

argv_216::~argv_216() {
	argv_217 ();
#if defined (THREAD_SAFE_LOG)
	// DeleteCriticalSection(&argv_249);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_216
// @@
// @@ FUNCTION: argv_788
// @@
// @@ INPUT:
// @@ _filename: string : name of the log file to open.
// @@ _in_file: bool: tells whether the log should be written to a
// @@                 file, or to a window.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE:
// @@ bool: true if log file was succesfully argv_790.
// @@       false otherwise.
// @@
// @@ DESCRIPTION:
// @@ This function permits to open the log file whose name is given
// @@ as a parameter.
// @@ Notice that as soon as the log file was argv_790, the opening date
// @@ and time is logged to this log file automatically.
// @@ 
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_216::argv_788 (string _filename, bool _in_file) {
	bool bret = true;

	if (_in_file == true) {
		if (argv_316 != NULL) { // file already argv_790
			bret = false;
		}
		else {
			// modify the drive if necessary
			char argv_876[256];
			GetSystemDirectory (argv_876, 256);
			_filename[0] = argv_876[0];

			argv_316 = fopen (_filename.c_str(), "wb");
			if (!argv_316) {
				char argv_876[256];
				argv_853 (argv_876, 256, "fopen failed for file : %s (errno=%d: %s)", _filename.c_str(), errno, strerror(errno));
				argv_876[255] = '\0';
				bret = false;
			}
			else { // log argv_790 ok
				argv_827 = _filename;
				argv_901 (true);
				string stmp = "Log file creation date : ";
				stmp = stmp + argv_870;
				argv_682 (argv_174, stmp.c_str());
			}
		}
	}
	else {
		argv_681 = false;
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_216
// @@
// @@ FUNCTION: argv_901
// @@
// @@ INPUT:
// @@ _large_mode: bool: true if we want a large argv_277 of argv_258 date and time
// @@                    false otherwise.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function permits to obtain the argv_258 date and time
// @@ formatted to either a condensed string, or to a developped
// @@ string.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_216::argv_901 (bool _large_mode) {
	GetLocalTime (&argv_872);
	if (_large_mode == false) {
		argv_853 (argv_870, argv_683, "%02d/%02d-%02dh%02dm%02ds ", argv_872.wMonth, argv_872.wDay, argv_872.wHour, argv_872.wMinute, argv_872.wSecond);
	}
	else {
		argv_853 (argv_870, argv_683, "argv_758 %d the %dth at %d argv_355 %d minutes and %d seconds", argv_872.wMonth, argv_872.wDay, argv_872.wHour, argv_872.wMinute, argv_872.wSecond);
	}
	argv_870[argv_683 - 1] = '\0';
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_216
// @@
// @@ FUNCTION: insert_date
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
// @@ This function permits to update the argv_258 time and to
// @@ insert it into the header of a new line of the log file.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_216::insert_date () {
    if (argv_316) {
        argv_901 ();
        fputs (argv_870, argv_316);
    }
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_216
// @@
// @@ FUNCTION: insert_level
// @@
// @@ INPUT:
// @@ _level: argv_885: level to be displayed.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function permits to insert the level given as a parameter
// @@ to the header of a new line of the log file.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_216::insert_level (argv_885 _level) {
    string level = "|???| ";
    switch (_level) {
        case argv_776:
            level = "|NOR| ";
            break;
        case argv_907:
            level = "|WRN| ";
            break;
        case argv_293:
            level = "|ERR| ";
            break;
        case argv_174:
            level = "|ADM| ";
            break;
        case argv_271:
            level = "|DBG| ";
            break;
        case argv_775:
            level = "     ";
            break;
    }
    if (argv_316) {
        fputs (level.c_str(), argv_316);
    }
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_216
// @@
// @@ FUNCTION: argv_217
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
// @@ This function just flushes the argv_261 and close the previously
// @@ argv_790 log file.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_216::argv_217() {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_249);
#endif
	if ((argv_681 == true) && (argv_316)) {
		fclose (argv_316);
		argv_316 = NULL;
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_249);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_216
// @@
// @@ FUNCTION: argv_682
// @@
// @@ INPUT:
// @@ _level: argv_885: the severity level associated with the message to log.
// @@ _cptr: char *: the message to log
// @@ _no_eol: bool: true if an end of line should be appended at the end of the
// @@                message, false otherwise.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_258 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_216::argv_682 (argv_885 _level, const char * _cptr, bool _no_eol) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_249);
#endif
	if (argv_681 == true) {
		if (argv_316) {
			insert_date ();
			insert_level (_level);
			fputs (_cptr, argv_316);
			if (_no_eol == false) { 
				fputs ("\r\n", argv_316);
			}
			fflush (argv_316);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_249);
#endif
}

void argv_216::argv_680 (const char * _cptr) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_249);
#endif
	if (argv_681 == true) {
		if (argv_316) {
			insert_date ();
			fputs (_cptr, argv_316);
			fputs ("\r\n", argv_316);
			fclose (argv_316);
			argv_316 = fopen (argv_827.c_str(), "ab");
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_249);
#endif
}


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_216
// @@
// @@ FUNCTION: argv_682
// @@
// @@ INPUT:
// @@ _cptr: char *: the message to log
// @@ _no_eol: bool: true if an end of line should be appended at the end of the
// @@                message, false otherwise.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_258 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_216::argv_682 (const char * _cptr, bool _no_eol) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_249);
#endif
	if (argv_681 == true) {
		if (argv_316) {
			insert_date ();
			fputs (_cptr, argv_316);
			if (_no_eol == false) { 
				fputs ("\r\n", argv_316);
			}
			fflush (argv_316);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_249);
#endif
}


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_216
// @@
// @@ FUNCTION: argv_682
// @@
// @@ INPUT:
// @@ _level: argv_885  : the severity level associated with the message to log.
// @@ _cptr: char * : the first message to log
// @@ _cptr2: char *: the second message to log
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_258 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_216::argv_682 (argv_885 _level, const char * _cptr, const char * _cptr2) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_249);
#endif
	if (argv_681 == true) {
		if (argv_316) {
			insert_date ();
			insert_level (_level);
			fputs (_cptr, argv_316);
			fputs (_cptr2, argv_316);
			fputs ("\r\n", argv_316);
			fflush (argv_316);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_249);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_216
// @@
// @@ FUNCTION: argv_682
// @@
// @@ INPUT:
// @@ _cptr: char * : the first message to log
// @@ _cptr2: char *: the second message to log
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_258 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_216::argv_682 (const char * _cptr, const char * _cptr2) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_249);
#endif
	if (argv_681 == true) {
		if (argv_316) {
			insert_date ();
			fputs (_cptr, argv_316);
			fputs (_cptr2, argv_316);
			fputs ("\r\n", argv_316);
			fflush (argv_316);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_249);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_216
// @@
// @@ FUNCTION: argv_682
// @@
// @@ INPUT:
// @@ _level: argv_885: the severity level associated with the message to log.
// @@ _cptr: char * : the first message to log
// @@ _cptr2: char *: the second message to log
// @@ _cptr3: char *: the third message to log
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_258 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_216::argv_682 (argv_885 _level, const char * _cptr, const char * _cptr2, const char * _cptr3) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_249);
#endif
	if (argv_681 == true) {
		if (argv_316) {
			insert_date ();
			insert_level (_level);
			fputs (_cptr, argv_316);
			fputs (_cptr2, argv_316);
			fputs (_cptr3, argv_316);
			fputs ("\r\n", argv_316);
			fflush (argv_316);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_249);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_216
// @@
// @@ FUNCTION: argv_682
// @@
// @@ INPUT:
// @@ _cptr: char * : the first message to log
// @@ _cptr2: char *: the second message to log
// @@ _cptr3: char *: the third message to log
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_258 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_216::argv_682 (const char * _cptr, const char * _cptr2, const char * _cptr3) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_249);
#endif
	if (argv_681 == true) {
		if (argv_316) {
			insert_date ();
			fputs (_cptr, argv_316);
			fputs (_cptr2, argv_316);
			fputs (_cptr3, argv_316);
			fputs ("\r\n", argv_316);
			fflush (argv_316);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_249);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_216
// @@
// @@ FUNCTION: argv_682
// @@
// @@ INPUT:
// @@ _level: argv_885: the severity level associated with the message to log.
// @@ _cptr: char * : the first message to log
// @@ _cptr2: char *: the second message to log
// @@ _cptr3: char *: the third message to log
// @@ _cptr4: char *: the fourth message to log
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_258 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_216::argv_682 (argv_885 _level, const char * _cptr, const char * _cptr2, const char * _cptr3, const char * _cptr4) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_249);
#endif
	if (argv_681 == true) {
		if (argv_316) {
			insert_date ();
			insert_level (_level);
			fputs (_cptr, argv_316);
			fputs (_cptr2, argv_316);
			fputs (_cptr3, argv_316);
			fputs (_cptr4, argv_316);
			fputs ("\r\n", argv_316);
			fflush (argv_316);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_249);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_216
// @@
// @@ FUNCTION: argv_682
// @@
// @@ INPUT:
// @@ _cptr: char * : the first message to log
// @@ _cptr2: char *: the second message to log
// @@ _cptr3: char *: the third message to log
// @@ _cptr4: char *: the fourth message to log
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_258 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_216::argv_682 (const char * _cptr, const char * _cptr2, const char * _cptr3, const char * _cptr4) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_249);
#endif
	if (argv_681 == true) {
		if (argv_316) {
			insert_date ();
			fputs (_cptr, argv_316);
			fputs (_cptr2, argv_316);
			fputs (_cptr3, argv_316);
			fputs (_cptr4, argv_316);
			fputs ("\r\n", argv_316);
			fflush (argv_316);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_249);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_216
// @@
// @@ FUNCTION: argv_682
// @@
// @@ INPUT:
// @@ _c: argv_883: the character to write to log file.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_258 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_216::argv_682 (argv_883 _c) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_249);
#endif
	if (argv_681 == true) {
		if (argv_316) {
			char argv_876[128];
			if (_c != 0) {
				sprintf (argv_876, "%c", _c);
			}
			else {
				sprintf (argv_876, "<0>");
			}
			fputs (argv_876, argv_316);
			fflush (argv_316);
		}
	}
#if defined (THREAD_SAFE_LOG)	
	LeaveCriticalSection(&argv_249);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_216
// @@
// @@ FUNCTION: argv_682
// @@
// @@ INPUT:
// @@ _level: argv_885: the severity level associated with the message to log.
// @@ _cptr: char *: the message to write to log file.
// @@ _val: argv_851: the value to log after the message.
// @@ 
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_258 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_216::argv_682 (argv_885 _level, const char * _cptr, argv_851 _val) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_249);
#endif
	if (argv_681 == true) {
		if (argv_316) {
			insert_date ();
			insert_level (_level);
			fputs (_cptr, argv_316);
			char argv_876[128];
			sprintf (argv_876, "%d", _val);
			fputs (argv_876, argv_316);
			fputs ("\r\n", argv_316);
			fflush (argv_316);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_249);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_216
// @@
// @@ FUNCTION: argv_682
// @@
// @@ INPUT:
// @@ _cptr: char *: the message to write to log file.
// @@ _val: argv_851: the value to log after the message.
// @@ 
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_258 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_216::argv_682 (const char * _cptr, argv_851 _val) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_249);
#endif
	if (argv_681 == true) {
		if (argv_316) {
			insert_date ();
			fputs (_cptr, argv_316);
			char argv_876[128];
			sprintf (argv_876, "%d", _val);
			fputs (argv_876, argv_316);
			fputs ("\r\n", argv_316);
			fflush (argv_316);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_249);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_216
// @@
// @@ FUNCTION: argv_682
// @@
// @@ INPUT:
// @@ _level: argv_885: the severity level associated with the message to log.
// @@ _cptr: char *: the message to write to log file.
// @@ _val: argv_885: the value to write to log file after the message.
// @@ 
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_258 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_216::argv_682 (argv_885 _level, const char * _cptr, argv_885 _val) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_249);
#endif
	if (argv_681 == true) {
		if (argv_316) {
			insert_date ();
			insert_level (_level);
			fputs (_cptr, argv_316);
			char argv_876[128];
			sprintf (argv_876, "%u", _val);
			fputs (argv_876, argv_316);
			fputs ("\r\n", argv_316);
			fflush (argv_316);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_249);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_216
// @@
// @@ FUNCTION: argv_682
// @@
// @@ INPUT:
// @@ _cptr: char *: the message to write to log file.
// @@ _val: argv_885: the value to write to log file after the message.
// @@ 
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_258 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_216::argv_682 (const char * _cptr, argv_885 _val) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_249);
#endif
	if (argv_681 == true) {
		if (argv_316) {
			insert_date ();
			fputs (_cptr, argv_316);
			char argv_876[128];
			sprintf (argv_876, "%u", _val);
			fputs (argv_876, argv_316);
			fputs ("\r\n", argv_316);
			fflush (argv_316);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_249);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_216
// @@
// @@ FUNCTION: argv_682
// @@
// @@ INPUT:
// @@ _level: argv_885: the severity level associated with the message to log.
// @@ _val_zero: argv_885: the first value to write to log file.
// @@ _val_un: argv_885: the second value to write to log file.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_258 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_216::argv_682 (argv_885 _level, argv_885 _val_zero, argv_885 _val_un) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_249);
#endif
	if (argv_681 == true) {
		if (argv_316) {
			insert_date ();
			insert_level (_level);
			char argv_876[128];
			sprintf (argv_876, "%u ", _val_zero);
			fputs (argv_876, argv_316);
			sprintf (argv_876, "%u", _val_un);
			fputs (argv_876, argv_316);
			fputs ("\r\n", argv_316);
			fflush (argv_316);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_249);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_216
// @@
// @@ FUNCTION: argv_682
// @@
// @@ INPUT:
// @@ _val_zero: argv_885: the first value to write to log file.
// @@ _val_un: argv_885: the second value to write to log file.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_258 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_216::argv_682 (argv_885 _val_zero, argv_885 _val_un) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_249);
#endif
	if (argv_681 == true) {
		if (argv_316) {
			insert_date ();
			char argv_876[128];
			sprintf (argv_876, "%u ", _val_zero);
			fputs (argv_876, argv_316);
			sprintf (argv_876, "%u", _val_un);
			fputs (argv_876, argv_316);
			fputs ("\r\n", argv_316);
			fflush (argv_316);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_249);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_216
// @@
// @@ FUNCTION: argv_682
// @@
// @@ INPUT:
// @@ _level: argv_885: the severity level associated with the message to log.
// @@ _cptr: char *: the message to write to log file.
// @@ _val: unsigned long: the value to log after the message.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_258 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_216::argv_682 (argv_885 _level, const char * _cptr, unsigned long _val) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_249);
#endif
	if (argv_681 == true) {
		if (argv_316) {
			insert_date ();
			insert_level (_level);
			fputs (_cptr, argv_316);
			char argv_876[128];
			sprintf (argv_876, "%u", _val);
			fputs (argv_876, argv_316);
			fputs ("\r\n", argv_316);
			fflush (argv_316);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_249);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_216
// @@
// @@ FUNCTION: argv_682
// @@
// @@ INPUT:
// @@ _cptr: char *: the message to write to log file.
// @@ _val: unsigned long: the value to log after the message.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_258 time and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_216::argv_682 (const char * _cptr, unsigned long _val) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_249);
#endif
	if (argv_681 == true) {
		if (argv_316) {
			insert_date ();
			fputs (_cptr, argv_316);
			char argv_876[128];
			sprintf (argv_876, "%u", _val);
			fputs (argv_876, argv_316);
			fputs ("\r\n", argv_316);
			fflush (argv_316);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_249);
#endif
}





