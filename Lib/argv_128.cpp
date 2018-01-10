


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ includes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include "argv_136.hpp"

//===========================
// service related constants
//===========================
const char * argv_678	= "lock_manager";
const char * argv_906	= "vrdb_daemon";
const char * argv_724	= "launcher_daemon";
const char * argv_828			= "scanner (franck)";
const char * argv_182		= "Migale exosteg";
const char * argv_677		= "\\\\.\\Pipe\\lock_mgr_pipe";
const char * argv_673		= "\\\\.\\Pipe\\lock_mgr_internal";
const char * argv_665			= "\\\\.\\Pipe\\migale_launcher";

string argv_211 (HWND hWnd, argv_851 mode) {
	return (argv_781 (hWnd, mode));
}

string argv_781 (HWND hWnd, argv_851 mode) {
   OPENFILENAME ofn;
    char szFileName[MAX_PATH] = "";
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn); // SEE NOTE BELOW
    ofn.hwndOwner = hWnd;
	if (mode == argv_787) {
		ofn.lpstrFilter = "Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
	}
	else if (mode == argv_783) {
		ofn.lpstrFilter = "Exe Files (*.exe)\0*.exe\0All Files (*.*)\0*.*\0";
	}
	else if (mode == argv_785) {
		ofn.lpstrFilter = "Licence Files (*.lic)\0*.lic\0All Files (*.*)\0*.*\0";
	}
	else if (mode == argv_784) {
		ofn.lpstrFilter = "Fpk Files (*.fpk)\0*.fpk\0All Files (*.*)\0*.*\0";
	}
	else if (mode == argv_782) {
		ofn.lpstrFilter = "All Files (*.*)\0*.*\0";
	}
	else {
		ofn.lpstrFilter = "All Files (*.*)\0*.*\0";
	}
    ofn.lpstrFile = szFileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    ofn.lpstrDefExt = "txt";

    if(GetOpenFileName(&ofn)) {
        // Do something usefull with the filename stored in szFileName 
    }
	return(szFileName);
}

bool argv_819 (const char * _filename, argv_885& _year, argv_885& _month, argv_885& _day, argv_885& _hour, argv_885& _minute, argv_885& _second, argv_885& _millisecond, argv_885 _type, argv_885& _ercode, argv_885& _ersource) {
	bool bret = true;
    FILETIME ftCreate, ftAccess, ftWrite;
    SYSTEMTIME stUTC, stLocal;
	
	HANDLE argv_352 = CreateFile(_filename,      // file to open
					   GENERIC_READ,          // open for reading
					   FILE_SHARE_READ,       // share for reading
					   NULL,                  // default security
					   OPEN_EXISTING,         // existing file only
					   FILE_ATTRIBUTE_NORMAL, // normal file
					   NULL);                 // no attr. template

	if (argv_352 == INVALID_HANDLE_VALUE) {
		_ersource = 1;
		_ercode = GetLastError ();
		bret = false;
	}
	else { // file argv_790 succesfully
		// Retrieve the file times for the file.
		if (!GetFileTime(argv_352, &ftCreate, &ftAccess, &ftWrite)) {
			_ercode = GetLastError ();
			_ersource = 2;
			bret = false;
		}
		else { // retrieval succesfull, let's retrieve argv_261 depending on the access mode 
			switch (_type) {
				case argv_236:
					FileTimeToSystemTime(&ftCreate, &stUTC);
					SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
					break;

				case argv_910:
					FileTimeToSystemTime(&ftWrite, &stUTC);
					SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
					break;

				case argv_807:
					FileTimeToSystemTime(&ftAccess, &stUTC);
					SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
					break;

				default: // unknown file access type
					bret = false;
			}

			if (bret == true) {
				_year			= stLocal.wYear;
				_month			= stLocal.wMonth;
				_day			= stLocal.wDay;
				_hour			= stLocal.wHour;
				_minute			= stLocal.wMinute;
				_second			= stLocal.wSecond;
				_millisecond	= stLocal.wMilliseconds;
			}
		}
		CloseHandle (argv_352);
	}
	return (bret);
}

bool argv_816 (const char * _filename, argv_885& _year, argv_885& _month, argv_885& _day, argv_885& _hour, argv_885& _minute, argv_885& _second, argv_885& _millisecond, argv_885& _retcode, argv_885& _ersource) {
	return (argv_819 (_filename, _year, _month, _day, _hour, _minute, _second, _millisecond, argv_236, _retcode, _ersource));
}

bool argv_817 (const char * _filename, argv_885& _year, argv_885& _month, argv_885& _day, argv_885& _hour, argv_885& _minute, argv_885& _second, argv_885& _millisecond, argv_885& _retcode, argv_885& _ersource) {
	return (argv_819 (_filename, _year, _month, _day, _hour, _minute, _second, _millisecond, argv_807, _retcode, _ersource));
}

bool argv_818 (const char * _filename, argv_885& _year, argv_885& _month, argv_885& _day, argv_885& _hour, argv_885& _minute, argv_885& _second, argv_885& _millisecond, argv_885& _retcode, argv_885& _ersource) {
	return (argv_819 (_filename, _year, _month, _day, _hour, _minute, _second, _millisecond, argv_910, _retcode, _ersource));
}

//@@============================================================
bool argv_778 (argv_883 c, argv_883& result) {
    bool bret = true;
    if ( ((c < '0') || (c > '9')) && ((c < 'a') || (c > 'f')) && ((c < 'A') || (c > 'F'))) {
        bret = false;
    }
    else {
		if ((c >= '0') && (c <= '9')) {
			result = c - '0';
		}
		else if ((c >= 'a') && (c <= 'z')) {
			result = 10 + (c- 'a');
		}
		else if ((c >= 'A') && (c <= 'Z')) {
			result = 10 + (c - 'A');
		}
		else {
			bret = false;
		}
	}
    return (bret);
}

// 'f' 'f' -> 255
bool argv_203 (argv_883 _msb, argv_883 _lsb, argv_883& result) {
    bool bret       = true;
    argv_883 lsb_hex    = 0;
    argv_883 msb_hex    = 0;

    bret = argv_778 (_msb, msb_hex);
    if (bret == true) {
        result  = msb_hex << 4;
        bret    = argv_778 (_lsb, lsb_hex);
        result =  result + lsb_hex;
    }
    return (bret);
}
//=====================================
string argv_210 (HWND hWnd) {
	OleInitialize (NULL);
	CoInitialize (NULL);

	string result = "";
	BROWSEINFO bi;
	memset(&bi,0,sizeof(BROWSEINFO));
	char buffer[MAX_PATH];
	bi.hwndOwner=hWnd;
	// Contient le repertoire initial ou NULL
	bi.pidlRoot=NULL;
	bi.pszDisplayName=buffer;
	bi.lpszTitle="Current directory";
	bi.ulFlags= argv_189;
	bi.lParam=NULL;

	LPITEMIDLIST argv_666 = SHBrowseForFolder(&bi);

	if (argv_666) {
		SHGetPathFromIDList(argv_666, buffer);
		result = buffer;
	}
	return (result);
}

//=====================================
argv_202::argv_202() {
	argv_354	= NULL;
	argv_793		= NULL;
	argv_352		= NULL;
}

argv_202::~argv_202() {
	argv_218();
}

void argv_202::argv_218 () {
	if (argv_793 != NULL) {
		UnmapViewOfFile(argv_793);
		argv_793 = NULL;
	}

	if (argv_354 != NULL) {
		CloseHandle(argv_354);
		argv_354 = NULL;
	}

	if (argv_352 != NULL) {
		CloseHandle (argv_352);
		argv_352 = NULL;
	}
}

void argv_202::argv_333 (argv_885& _ercode, argv_885& _ersource) {
	_ercode		= argv_292;
	_ersource	= argv_294;
}

bool argv_202::argv_753 (const char * _filename, bool _readonly, argv_883 *& _pBuf, DWORD& _file_size) {
	bool bret	= true;
	_file_size	= 0;

	if (argv_352 != NULL) {
		argv_292		= 0;
		argv_294	= 100;
		bret			= false;
	}
	else if (argv_354 != NULL) {
		argv_292		= 0;
		argv_294	= 101;
		bret			= false;
	}
	else if (argv_793 != NULL) {
		argv_292		= 0;
		argv_294	= 102;
		bret			= false;
	}
	else { // file was not already argv_790
		DWORD access_mode_CreateFile;
		DWORD access_mode_CreateFileMapping;
		DWORD access_mode_MapViewOfFile;
		DWORD open_mode;

		if (_readonly == true) {
			access_mode_CreateFile			= GENERIC_READ;	
			access_mode_CreateFileMapping	= PAGE_READONLY;
			access_mode_MapViewOfFile		= FILE_MAP_READ;
			open_mode						= OPEN_EXISTING;
		}
		else {
			//MessageBox (NULL, "read-write access", "", MB_OK);
			access_mode_CreateFile			= GENERIC_READ | GENERIC_WRITE;
			access_mode_CreateFileMapping	= PAGE_READWRITE;
			access_mode_MapViewOfFile		= FILE_MAP_READ | FILE_MAP_WRITE;
			open_mode						= OPEN_ALWAYS;
		}
		argv_352 = CreateFile (_filename,				// file to open
						   access_mode_CreateFile,	// open for reading
						   0/*FILE_SHARE_READ*/,    // share for reading
						   NULL,					// default security
						   open_mode,				// existing file only
						   FILE_ATTRIBUTE_NORMAL,	// normal file
						   NULL);					// no attr. template
 
		if (argv_352 == INVALID_HANDLE_VALUE)  {
			argv_292		= GetLastError ();
			argv_294	= 2;
			bret			= false;
		}
		else { // CreateFile was succesfull
			// retrieve the file size
			_file_size = GetFileSize (argv_352, NULL);
			if (_file_size <= 0) {
				argv_292		= GetLastError ();
				argv_294	= 6;
				bret			= false;
			}
			else if (_file_size == 0xFFFFFFFF) {
				argv_292		= GetLastError ();
				argv_294	= 3;
				bret			= false;
			}
	
			if (bret == true) {
			   argv_354 = CreateFileMapping(
							 argv_352,					  // use paging file
							 NULL,                    // default security 
							 access_mode_CreateFileMapping,   // read access
							 0,                       // argv_703. object size 
							 0/*argv_752*/,      // buffer size  
							 NULL);					  // name of mapping object

				if (argv_354 == NULL || argv_354 == INVALID_HANDLE_VALUE)  { // failed
					char argv_876[256];
					argv_292		= GetLastError ();
					argv_853 (argv_876, 255, "mmap failed: CreateFileMapping FAILED (errno=%d)", argv_292);
					argv_294	= 4;
					bret			= false;			
				}
				else { // CreateFileMapping was succesfull
					argv_793 = (LPTSTR) MapViewOfFile (argv_354,	   // handle to map object
										access_mode_MapViewOfFile, // read/write permission
										0,                   
										0,                   
										0/* argv_752 */);           

					if (argv_793 == NULL) {
						argv_292		= GetLastError ();
						argv_294	= 5;
						bret			= false;	
					}
					else { // all succeeded, copy obtained pointer to caller's variable
						_pBuf = (argv_883 *) argv_793;
					}
				}
			}
		}
	}

	// in case of failure, some components (i.e: handles) may have been argv_790, let's close them
	if (bret == false) {
		argv_218 ();
	}
	return (bret);
}

bool argv_652 (const char * _filename) {
	bool bret = true;

	// open the file
	FILE * argv_316 = fopen (_filename, "rb");
	if (! argv_316) {
		bret = false;
	}
	else {
		IMAGE_DOS_HEADER dos_header;
		IMAGE_NT_HEADERS  nt_header;

		int argv_767 = fread (&dos_header, 1, sizeof(IMAGE_DOS_HEADER), argv_316);

		if (argv_767 != sizeof(IMAGE_DOS_HEADER)) {
			bret = false;
		}
		else { // dos header read succesfully
			if (fseek (argv_316, dos_header.e_lfanew, SEEK_SET) != 0) {
				bret = false;
			}
			else { // fseek to new header succeeded
				argv_767 = fread (&nt_header, 1, sizeof(IMAGE_NT_HEADERS), argv_316);
				if (argv_767 != sizeof(IMAGE_NT_HEADERS)) {
					bret = false;
				}
				else { // nt header read succesfully
					if (nt_header.Signature != 0x4550) {
						bret = false; // signature does not match the pattern "PE"
					}
				}
			}
		}
	}

	if (argv_316) {
		fclose (argv_316);
	}

	return (bret);
}

// this function permits to extract the entry point of a DLL/EXE
// from a mmapped file.
// notice that if the entry point can't be retrieved (file too short for example)
// then function fails and returns false.
//
// Notice that this function does not check whether the mmapped file is a valid 
// PE file or not (it's then up to the caller to perform this check before calling us).
bool argv_330 (char * _cptr, argv_886 _file_size, argv_886& _ep_raw) {
	bool bret = true;
	if (_cptr == NULL) {
		bret = false; // it seems that the file was not mmaped correctly...
	}
	else {
		IMAGE_DOS_HEADER dos_header;
		IMAGE_NT_HEADERS nt_header;
		argv_886 current_offset = 0;

		if ((current_offset + sizeof(IMAGE_DOS_HEADER)) >= _file_size) {
			bret = false; // short file (not enough to read DOS header)
		}
		else {
			// read the DOS header
			memcpy (&dos_header, &_cptr[current_offset], sizeof(IMAGE_DOS_HEADER));

			// read the PE optional header
			current_offset = dos_header.e_lfanew;

			if ((current_offset + sizeof(IMAGE_NT_HEADERS)) >= _file_size) {
				bret = false; // short file (not enough to read PE optional header
			}
			else { // ok to read safely the optional header
				memcpy (&nt_header, &_cptr[current_offset], sizeof(IMAGE_NT_HEADERS));

				// now we just have to retrieve the field that we need from optional header
				argv_886 ep_rva = nt_header.OptionalHeader.AddressOfEntryPoint;

				// convert the EP from RVA to RAW offset

			}
		}
	}
	return (bret);
}

void argv_301 (const string& _filename, int _max_length, string& _result) {
	_result = "";
	int size = _filename.size ();
	argv_851 i=size;
	for (i=size-1 ; i>=0 ; i--) {
		if (_filename[i] == '\\') {
			break;
		}
	}

	for (int k=0 ; k<i ; k++) {
		_result += _filename[k];
	}
}

void argv_323 (const string& filename, int max_length, string& _result) {
	_result = "";
	int i = 0;
	int filename_size = filename.size();

	if (filename_size <= max_length) {
		_result = filename;
	}
	else {
		if (filename_size > 0) {
			int start_end = filename_size - 1;

			while ((start_end >= 0) && (filename[start_end] != '\\')) {
				start_end--;
			}

			int end_start = 0;
			while ((end_start < filename_size) && (filename[end_start] != '\\')) {
				end_start++;
			}
			
			string one		= "";
			string two		= "...";
			string three	= "";
			for (i=0 ; i<end_start ; i++) {
				one += filename[i];
			}

			for (i=start_end ; i<filename_size ; i++) {
				three += filename[i];
			}

			int last_half_length = two.size() + three.size();
			int first_half_size  = one.size();
			while ((first_half_size + last_half_length) < max_length) {
				one += filename[end_start];
				end_start++;
				first_half_size = one.size();
			}

			_result = one + two + three;
		}
	}
}

bool argv_273 (string _dirname) {
	bool bret = true;
	
	return (bret);
}

void argv_867 (HWND _mother, HWND _son) {
	if (_mother) {
		RECT rect; 
		GetWindowRect (_mother, &rect); 
		int son_x = rect.left;
		int son_y = rect.bottom;
		SetWindowPos (_son, HWND_TOP, son_x, son_y, 0, 0, SWP_NOSIZE);
	}
}

void argv_199(HWND _hDlg, int& _his_x, int& _his_y) {
	if (_hDlg) {
		RECT rect;
		GetWindowRect(_hDlg, &rect);
		_his_x = (GetSystemMetrics(SM_CXSCREEN) - rect.right) / 2;
		_his_y = (GetSystemMetrics(SM_CYSCREEN) - rect.bottom) / 2;
		SetWindowPos(_hDlg, HWND_TOP, _his_x, _his_y, 0, 0, SWP_NOSIZE);
	}
}

void argv_199(HWND hwndWindow)
{
	HWND hwndParent;
	RECT rectWindow, rectParent;

	// make the window relative to its parent
	if ((hwndParent = GetParent(hwndWindow)) != NULL)
	{
		GetWindowRect(hwndWindow, &rectWindow);
		GetWindowRect(hwndParent, &rectParent);

		int nWidth = rectWindow.right - rectWindow.left;
		int nHeight = rectWindow.bottom - rectWindow.top;

		int nX = ((rectParent.right - rectParent.left) - nWidth) / 2 + rectParent.left;
		int nY = ((rectParent.bottom - rectParent.top) - nHeight) / 2 + rectParent.top;

		int nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
		int nScreenHeight = GetSystemMetrics(SM_CYSCREEN);

		// make sure that the dialog box never moves outside of the screen
		if (nX < 0) nX = 0;
		if (nY < 0) nY = 0;
		if (nX + nWidth > nScreenWidth) nX = nScreenWidth - nWidth;
		if (nY + nHeight > nScreenHeight) nY = nScreenHeight - nHeight;

		MoveWindow(hwndWindow, nX, nY, nWidth, nHeight, FALSE);
	}
}

bool argv_243 (string _dirname) {
	bool bret = true;

	if (CreateDirectory (_dirname.c_str(), NULL) == 0) {
		if (GetLastError() != ERROR_ALREADY_EXISTS) {
			bret = false;	
		}
	}

	return (bret);
}

bool argv_230 (string _source_dir, string _pattern, string _dest_dir) {
	bool bret = true;
	if (SetCurrentDirectory (_source_dir.c_str()) == false) {
		bret = false;
	}
	else {
		WIN32_FIND_DATA FindData; 
		HANDLE hFind = FindFirstFile (_pattern.c_str(), &FindData);

		if (hFind == INVALID_HANDLE_VALUE) {
			bret = false;
		}
		else {
			do {
				// if it is not a directory
				if (!(FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
					string full_source = _source_dir + "\\" + FindData.cFileName;
					string full_dest   = _dest_dir   + "\\" + FindData.cFileName;
					string argv_876 = "copy " + full_source + " -> " + full_dest;
					CopyFile (full_source.c_str(), full_dest.c_str(), false);
				}
			}
			while (FindNextFile (hFind, &FindData)) ;

			FindClose (hFind);
		}
	}
	return (bret);
}

//=========================================
argv_194::argv_194() {
	hwnd	= 0;
	argv_703		= 0;
	argv_362		= 0;	
}

void argv_194::init (HWND _hwnd, int _idc, int _max) {
	hwnd	= _hwnd;
	argv_703		= _max;
	argv_362		= _idc;
	argv_258	= 0;
	reset();
}

void argv_194::incr (argv_851 _nb_step) {
	argv_258 += _nb_step;
	SendDlgItemMessage (hwnd, argv_362, PBM_SETPOS, argv_258, 0);
}

void argv_194::reset() {
	SendDlgItemMessage (hwnd, argv_362, PBM_SETRANGE32, 0, argv_703); 
	argv_258 = 0;
	SendDlgItemMessage (hwnd, argv_362, PBM_SETPOS, argv_258, 0);
}
//=======================================
string argv_905 (const vector<argv_883>& _v) {
	string s = "";
	for (int i=0 ; i<_v.size() ; i++) {
		s += (_v[i]);
	}
	return(s);
}

string argv_351 (const vector<argv_883>& _v) {
	string result = "";
	int size = _v.size();
	char argv_876[32];
	for (argv_851 i=0 ; i<size ; i++) {
		sprintf (argv_876, "%02X", _v[i]);
		result += argv_876;
	}
	return (result);
}

//===========================================
bool argv_307 (const char * _filename) {
	bool bret = true;
	DWORD attr = GetFileAttributes (_filename);
	if (attr == -1) {
		DWORD last_err = GetLastError ();
		if ((last_err == ERROR_FILE_NOT_FOUND) || (last_err == ERROR_PATH_NOT_FOUND)) {
			bret = false;
		}
	}
	return (bret);
}

argv_885 argv_224 (argv_196 _filename) {
	argv_885 size = 0;

	if (_filename != "") {
		FILE * argv_316 = fopen (_filename, "rb");
		if (argv_316) {
			fseek (argv_316, 0, SEEK_END);
			size = ftell (argv_316);
			fclose (argv_316);
		}
	}
	return (size);
}

unsigned long argv_224 (const string& _filename) {
	unsigned long size = 0;

	if (_filename != "") {
		FILE * argv_316 = fopen (_filename.c_str(), "rb");
		if (argv_316) {
			fseek (argv_316, 0, SEEK_END);
			size=ftell (argv_316);
			fclose (argv_316);
		}
	}
	return (size);
}

//=========================================
bool argv_308 (const char * _filename) {
	bool bret = false;

	DWORD dwAttrs; 
	dwAttrs = GetFileAttributes (_filename); 
	if ((dwAttrs != -1) && (dwAttrs & FILE_ATTRIBUTE_READONLY)) {
		bret = true;
	}
	return (bret);
}

bool argv_811 (const char * _filename) {
	bool bret = true;

	DWORD dwAttrs;
	dwAttrs = GetFileAttributes (_filename); 
	if (dwAttrs == -1) {
		bret = false;
	}
	else {
		if (!(dwAttrs & FILE_ATTRIBUTE_READONLY)) {
			bret = false;
		}
		else {
			dwAttrs &= ~FILE_ATTRIBUTE_READONLY;
			if (! SetFileAttributes (_filename, dwAttrs)) {
				int iret = GetLastError();
				bret = false;	
			}
			else {
				bret = true;
			}
		}
	}
	return (bret);
}

//=============================================
argv_256::argv_256 () {

}
/*
	argv_794,
	argv_777, // VBA script
	argv_356,
	argv_699,
	argv_344	
*/

argv_851 argv_854 (string _s) {
	int size = _s.size();
	argv_851 argv_854 = 0;
	argv_851 _mult = 1;
	_mult = 1;

	for (int i=0 ; i<size ; i++) {
		argv_854 += _s[i];
		_mult *= _s[i];
	}
	FILE * argv_316 = fopen ("C:\\the_log.txt", "ab");
	if (argv_316) {
		fprintf (argv_316, "%s: argv_854=%d, mul=%d\r\n", _s.c_str(), argv_854, _mult);
		fclose (argv_316);
	}
	return (argv_854);
}
/*
exe: argv_854=322, mul=1224120
dll: argv_854=316, mul=1166400
doc: argv_854=310, mul=1098900
xls: argv_854=343, mul=1490400
htm: argv_854=329, mul=1314976
html: argv_854=437, mul=142017408
gif: argv_854=310, mul=1103130
jpg: argv_854=321, mul=1222816

EXE: argv_854=226, mul=418968
DLL: argv_854=220, mul=392768
HTM: argv_854=233, mul=465696
HTML: argv_854=309, mul=35392896
JPG: argv_854=225, mul=420320
GIF: argv_854=214, mul=362810
XLS: argv_854=247, mul=555104
DOC: argv_854=214, mul=359924
*/
argv_851 argv_256::argv_181 (const char * _filename) {
	argv_851 type = argv_897;

	argv_851 size = strlen (_filename);
	if (size > 0) {
		argv_851 mult = 1;
		bool dot_found		= false;

		for (argv_851 i=size-1 ; i>=0 ; i--) {
			if (_filename[i] == '.') {
				dot_found = true;
				break;
			}
			mult *= _filename[i];
		}

		// have we found a dot ?
		if (dot_found) {
			// extension was retrieved, now we must convert it to numeric
			if ((mult == 1224120) || (mult == 1166400) || (mult == 418968) || (mult == 392768)) { // exe , dll, EXE, DLL
				type = argv_794;
			}
			else if ((mult == 1103130) || (mult == 1222816) || (mult == 420320) || (mult == 362810)) { // gif, jpg, GIF, JPG
				type = argv_344;
			}
			else if ((mult == 1314976) || (mult == 142017408) || (mult == 35392896) || (mult == 465696)) { // htm, html, HTM, HTML
				type = argv_356;
			}
			else if ((mult == 1098900) || (mult == 1490400) || (mult == 555104) || (mult == 359924)) { // doc, xls, DOC, XLS
				type = argv_777;
			}
		}
	}
	return (type);
}	

bool argv_331 (vector<string>& _v_hdd) {
	vector<string> v_DRIVE_UNKNOWN;
	vector<string> v_DRIVE_NO_ROOT_DIR;
	vector<string> v_DRIVE_REMOVABLE;
	vector<string> v_DRIVE_REMOTE;
	vector<string> v_DRIVE_CDROM; 
	vector<string> v_DRIVE_RAMDISK;

	bool bret = argv_328 (v_DRIVE_UNKNOWN, v_DRIVE_NO_ROOT_DIR, v_DRIVE_REMOVABLE, _v_hdd, v_DRIVE_REMOTE, v_DRIVE_CDROM, v_DRIVE_RAMDISK);
	return (bret);
}

bool argv_328 (vector<string>& _v_result) {
	bool bret = true;
	_v_result.clear ();
	char argv_876[argv_287];
	argv_851 length = GetLogicalDriveStrings (argv_287, argv_876);
	if (length == 0) {
		bret = false;
	}		
	else {
		string current_drive;

		for (argv_851 i=0 ; i<length ; i++) {
			if (argv_876[i] == '\0') {
				if (current_drive == "") {
					break;
				}
				else {
					_v_result.push_back (current_drive);	
					current_drive = "";
				}
			}
			else {
				current_drive += argv_876[i];	
			}
		}
	}
	return (bret);
}

/*
DRIVE_UNKNOWN
DRIVE_NO_ROOT_DIR
DRIVE_REMOVABLE
DRIVE_FIXED
DRIVE_REMOTE
DRIVE_CDROM
DRIVE_RAMDISK
*/
bool argv_328 (vector<string>& _v_DRIVE_UNKNOWN, vector<string>& _v_DRIVE_NO_ROOT_DIR, vector<string>& _v_DRIVE_REMOVABLE, vector<string>& _v_DRIVE_FIXED, vector<string>& _v_DRIVE_REMOTE, vector<string>& _v_DRIVE_CDROM, vector<string>& _v_DRIVE_RAMDISK) {
	vector<string>	v_drive;
	bool bret = argv_328 (v_drive);	
	if (bret == true) {
		_v_DRIVE_UNKNOWN.clear ();
		_v_DRIVE_NO_ROOT_DIR.clear ();
		_v_DRIVE_REMOVABLE.clear ();
		_v_DRIVE_FIXED.clear ();
		_v_DRIVE_REMOTE.clear ();	
		_v_DRIVE_CDROM.clear ();
		_v_DRIVE_RAMDISK.clear ();

		UINT type;
		argv_851 argv_763 = v_drive.size ();
		for (argv_851 i=0 ; i<argv_763 ; i++) {
			type = GetDriveType (v_drive[i].c_str());
			if (type == DRIVE_UNKNOWN) {
				_v_DRIVE_UNKNOWN.push_back (v_drive[i]);
			}
			else if (type == DRIVE_NO_ROOT_DIR) {
				_v_DRIVE_NO_ROOT_DIR.push_back (v_drive[i].c_str());
			}
			else if (type == DRIVE_REMOVABLE) {
				_v_DRIVE_REMOVABLE.push_back (v_drive[i].c_str());
			}
			else if (type == DRIVE_FIXED) {
				_v_DRIVE_FIXED.push_back (v_drive[i].c_str());
			}
			else if (type == DRIVE_REMOTE) {
				_v_DRIVE_REMOTE.push_back (v_drive[i].c_str());
			}
			else if (type == DRIVE_CDROM) {
				_v_DRIVE_CDROM.push_back (v_drive[i].c_str());
			}
			else if (type == DRIVE_RAMDISK) {
				_v_DRIVE_RAMDISK.push_back (v_drive[i].c_str());
			}
		}
	}
	return (bret);
}

void argv_335 (string& _str) {
	argv_885 prio_class = GetPriorityClass (GetCurrentProcess ());
	if (prio_class == argv_166) {
		_str = "argv_166";
	}
	else if (prio_class == argv_188) {
		_str = "argv_188";
	}
	else if (prio_class == HIGH_PRIORITY_CLASS) {
		_str = "HIGH_PRIORITY_CLASS";
	}
	else if (prio_class == IDLE_PRIORITY_CLASS) {
		_str = "IDLE_PRIORITY_CLASS";
	}
	else if (prio_class == NORMAL_PRIORITY_CLASS) {
		_str = "NORMAL_PRIORITY_CLASS";
	}
	else if (prio_class == REALTIME_PRIORITY_CLASS) {
		_str = "REALTIME_PRIORITY_CLASS";
	}
	else {
		_str = "UNKNOWN";
	}
}

void argv_337 (HANDLE _thread_handle, string& _str) {
	int prio = GetThreadPriority (_thread_handle);
	if (prio == THREAD_PRIORITY_ERROR_RETURN) {
		_str = "THREAD_PRIORITY_ERROR_RETURN";
	}
	else if (prio == THREAD_PRIORITY_ABOVE_NORMAL) {
		_str = "THREAD_PRIORITY_ABOVE_NORMAL";		
	}
	else if (prio == THREAD_PRIORITY_BELOW_NORMAL) {
		_str = "THREAD_PRIORITY_BELOW_NORMAL";		
	}
	else if (prio == THREAD_PRIORITY_HIGHEST) {
		_str = "THREAD_PRIORITY_HIGHEST";		
	}
	else if (prio == THREAD_PRIORITY_IDLE) {
		_str = "THREAD_PRIORITY_IDLE";		
	}
	else if (prio == THREAD_PRIORITY_LOWEST) {
		_str = "THREAD_PRIORITY_LOWEST";		
	}
	else if (prio == THREAD_PRIORITY_NORMAL) {
		_str = "THREAD_PRIORITY_NORMAL";		
	}
	else if (prio == THREAD_PRIORITY_TIME_CRITICAL) {
		_str = "THREAD_PRIORITY_TIME_CRITICAL";		
	}
}

bool argv_647 (const char * _filename) {
	bool bret = false;
	DWORD atr = GetFileAttributes (_filename);
	if (atr != -1) {
		if ((atr & FILE_ATTRIBUTE_HIDDEN) && (atr & FILE_ATTRIBUTE_SYSTEM)) {
			bret = true;	
		}	
	}
	return (bret);
}

void argv_810 (HWND hwnd_window, argv_885 _idc, const char * _msg) {
	HWND hwnd_static = GetDlgItem (hwnd_window, _idc);
	ShowWindow (hwnd_static, SW_HIDE);
	ShowWindow (hwnd_static, SW_SHOWDEFAULT);
	SendDlgItemMessage (hwnd_window, _idc, WM_SETTEXT, 0, (LPARAM) "");
	UpdateWindow (hwnd_static);
	SendDlgItemMessage (hwnd_window, _idc, WM_SETTEXT, 0, (LPARAM) _msg);
}

// =================
argv_193::argv_193 () {
	init_done = false;
}

void argv_193::init (HWND _hwnd, HINSTANCE _hinstance) {
	reset ();
	hwnd_window = _hwnd;
	hInstance	= _hinstance;
	init_done	= true;
}

void argv_193::argv_171 (argv_885 _winid) {
	if (init_done) {
		argv_904.push_back (_winid);
		argv_763++;
	}
}

void argv_193::incr () {
	if (init_done) {
		argv_857++;
		if (argv_857 >= argv_763) {
			argv_857 = 0;
		}
		InvalidateRect (hwnd_window, NULL, FALSE); // force WM_PAINT to be sent
		UpdateWindow (hwnd_window);
	}
}

void argv_193::reset () {
	argv_763		= 0;
	argv_904.clear ();
	hwnd_window	= NULL;
	hInstance	= NULL;
	init_done	= false;
	argv_857		= 0;
}

void argv_193::argv_277 () {
	if (init_done) {
		argv_347 = LoadImage (hInstance, MAKEINTRESOURCE(argv_904[argv_857]),IMAGE_BITMAP,0,0,LR_CREATEDIBSECTION);
		argv_349 = BeginPaint (hwnd_window, &argv_805);
		DrawState (argv_349,NULL,NULL, (long) argv_347, NULL,0,0,0,0,DST_BITMAP);
		EndPaint (hwnd_window, &argv_805);
		DeleteObject (argv_347);
	}
}

argv_885 argv_334 () {
	argv_885 version = 0;
	OSVERSIONINFOEX osvi;
	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	GetVersionEx ((OSVERSIONINFO *) &osvi);
	switch (osvi.dwPlatformId) {
		case VER_PLATFORM_WIN32_NT:
			version = osvi.dwMajorVersion;
			break;
	}

	return (version);
}

bool argv_661 () {
	return (argv_334() == 5);
}

bool argv_659 () {
	return (argv_334() == 6);
}

argv_885 argv_297 (const char * _line, vector<string>& _v_arg) {
	argv_885 nb_arg = 0;
	argv_885 length = strlen (_line);
	string current_arg;
	bool in_brackets = false;

	for (argv_885 i=0 ; i<length ; i++) {
		if (_line[i] == '\"') {
			if (in_brackets == false) {
				in_brackets = true;	
			}
			else {
				_v_arg.push_back (current_arg);
				current_arg = "";
				in_brackets = false;
			}
		}
		else if (in_brackets == true) {
			current_arg += _line[i];
		}
		else if ((_line[i] != ' ') && (_line[i] != '\t')) {
			current_arg += _line[i];
		}
		else {
			if (current_arg.size() > 0) {
				_v_arg.push_back (current_arg);
				current_arg = "";
			}
		}
	}

	// don't forget the argv_664 parameter
	if (current_arg.size() > 0) {
		_v_arg.push_back (current_arg);
	}
	return (_v_arg.size());
}

void argv_324 (const char * _prefix, const char * _suffix1, const char * _suffix2, string& _filename1, string& _filename2) {
	_filename1 = _filename2 = "";
	SYSTEMTIME argv_872;
	GetLocalTime (&argv_872);
	srand ((unsigned) argv_872.wMilliseconds);
	argv_851 liste[3];
	liste[0] = rand () % 512;
	liste[1] = rand () % 512;
	liste[2] = rand () % 512;
	char argv_876[1024];
	argv_853 (argv_876, 1024, "%s_%d_%d_%d_%d_%d%d%d%d.%s", _prefix, argv_872.wHour,argv_872.wMinute,argv_872.wSecond,argv_872.wMilliseconds, _suffix1, liste[0], liste[1], liste[2], _suffix1);
	argv_876[1023] = '\0';
	_filename1 = argv_876;

	argv_853 (argv_876, 1024, "%s_%d_%d_%d_%d_%d%d%d%d.%s", _prefix, argv_872.wHour,argv_872.wMinute,argv_872.wSecond,argv_872.wMilliseconds, _suffix1, liste[0], liste[1], liste[2], _suffix2);
	argv_876[1023] = '\0';
	_filename2 = argv_876;
}

bool argv_313 (argv_196 _folder_name) {
	bool bret = false;
	DWORD attr = GetFileAttributes (_folder_name);
	if (attr != argv_639) {
		if (attr & FILE_ATTRIBUTE_DIRECTORY) {
			bret = true;
		}
	}
	return (bret);
}

bool argv_240 (argv_196 _folder_name) {
	bool bret = true;
	if (CreateDirectory (_folder_name, NULL) == 0) {
		bret = false;
	}
	return (bret);
}
