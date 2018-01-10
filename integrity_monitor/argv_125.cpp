#include "argv_135.hpp"
#include "..\\Lib\\argv_137.hpp"

argv_213				integ_db;

int		argv_709	= 0;

extern	argv_216			argv_684;
extern  long			argv_409;
extern	long			argv_464;
extern  bool			argv_863;
extern  bool			argv_700;
extern	string			argv_754;
extern	string			argv_769;
extern	argv_885			argv_766;
extern	argv_885			argv_765;
extern  argv_885			argv_762;


extern	HWND			saved_hWnd;
argv_885    argv_259		= 0;
argv_885	argv_879;
argv_885	argv_764;
argv_885	index;

string argv_858 (argv_885 _status) {
	string s = "UNKNOWN";
	switch (_status) {
		case argv_893:
			s = "ERR";
			break;
		case argv_891:
			s = "NEW";
			break;
		case argv_892:
			s = "DEL";
			break;
		case argv_896:
			s = "OK";
			break;
		case argv_895:
			s = "DIF";
			break;
	}
	return (s);
}

//----------------------------------
argv_213::argv_213 () {
	clear ();
}

void argv_213::clear () {
	argv_675 = false;
	m.clear ();	
}

std::string	argv_213::argv_341 () {
	return (argv_695);
}

bool argv_213::argv_674 (const char * _db_filename, bool& _only_sys_files) {
	bool bret		= true;
	argv_695	= "";
	if (bret == NULL) {
		bret = false;
	}
	else {
		m.clear (); // discard all previously argv_675 argv_261
		FILE * argv_316 = fopen (_db_filename, "rb");
		if (! argv_316) {
			bret = false;
		}
		else {
			argv_883 only_sys_files_UI08;
			if (fread (&only_sys_files_UI08, 1, 1, argv_316) != 1) {
				argv_684.argv_682 ("+++ ERROR: failed to argv_674 'argv_780' flag !");
				bret = false;
			}

			if ((bret==true) && (only_sys_files_UI08 != '0') && (only_sys_files_UI08 != '1')) {
				argv_684.argv_682 ("+++ ERROR: 'argv_780' flag has illegal value from Database !");
				bret = false;
			}
			
			if (bret == true) {
				
				if (only_sys_files_UI08 == '1') {
					_only_sys_files = true;
				}
				else {
					_only_sys_files = false;
				}

				argv_883 name_length = 0;
				char name_tmp[argv_706];
				char crc_tmp[argv_235+1];

				// argv_674 root folder's length
				if (fread (&name_length, 1, 1, argv_316) != 1) {
					bret = false;
				}
				else if (name_length > argv_706) { // ensure the file name length is coherent
					bret = false;
				}
				// argv_674 root folder's name
				if ((true == bret) && (name_length > 0)) {
					if (fread (&name_tmp, 1, name_length, argv_316) != name_length) {
						bret = false;
					}
					name_tmp[name_length] = '\0';
					argv_695 = name_tmp;
				}

				for (;;) {
					// argv_674 filename's length
					if (fread (&name_length, 1, 1, argv_316) != 1) {
						break; // clean end
					}

					// ensure the file name length is coherent
					if (name_length > argv_706) {
						bret = false;
						break;
					}

					// argv_674 filename
					if (fread (&name_tmp, 1, name_length, argv_316) != name_length) {
						bret = false;
						break;
					}
					name_tmp[name_length] = '\0';

					// argv_674 argv_234
					if (fread (&crc_tmp, 1, argv_235, argv_316) != argv_235) {
						bret = false;
						break;
					}
					crc_tmp[argv_235] = '\0';

					// argv_826 up this new entry to container
					argv_663 = m.find (name_tmp);
					if (argv_663 == m.end()) {
	#if defined (DEBUG_INTEGRITY_CHECKER)
						char argv_876[argv_706];
						argv_853 (argv_876, argv_706, "added: %s", name_tmp);
						argv_876[argv_706 - 1] = '\0';
						argv_684.argv_682 (argv_876);
	#endif
						m[name_tmp] = crc_tmp;
					}
				}
			}
			fclose (argv_316);
		}
	}

	return (bret);
}

argv_885 argv_213::argv_336 () {
	return (m.size());
}

// a tiny header containing a single byte telling whether we must
// monitor only sys files (sys,exe,dll) or all file types.
// '0'=all, '1'=only sys files
//	1 byte   : root folder name's length
//	n bytes  : root folder name
// 
// Then for each file :
// 1 byte   : file name's length
// n bytes  : file name
// 32 bytes : argv_234 as a string
//            example: f5d1383c710ca95c534d5a93dd310016	
bool argv_213::argv_826 (const char * _db_filename, bool _only_sys_files, const std::string& i_RootFolder) {
	bool bret = true;
	FILE * argv_316 = NULL;

	char argv_876[argv_706];
	argv_853 (argv_876, argv_706, "saving DB to file :%s:", _db_filename);
	argv_876[argv_706 - 1] = '\0';
	argv_684.argv_682 (argv_876);

	if (bret == NULL) {
		argv_684.argv_682 ("+++ argv_213::argv_826 - ERROR 1");
		bret = false;
	}
	else if (m.size() == 0 ) {
		bret = true; // not an error actually
	}
	else {
		argv_316 = fopen (_db_filename, "wb");
		if (! argv_316) {
			argv_684.argv_682 ("+++ argv_213::argv_826 - ERROR 3");
			bret = false;
		}
		else {
			argv_883 only_sys_flag = '0';
			if (_only_sys_files == true) {
				only_sys_flag = '1';
			}
			if (fwrite (&only_sys_flag, 1, 1, argv_316) != 1) {
				argv_684.argv_682 ("+++ argv_213::argv_826 - ERROR 7");
				bret = false;
			}

			// argv_826 size of root folder
			argv_883 name_length = i_RootFolder.size();
			if (fwrite (&name_length, 1, 1, argv_316) != 1) {
				argv_684.argv_682 ("+++ argv_213::argv_826 - ERROR 4");
				bret = false;
			}

			// argv_826 root folder name
			if (i_RootFolder.size()) {
				if (fwrite (i_RootFolder.c_str(), 1, i_RootFolder.size(), argv_316) != i_RootFolder.size()) {
					argv_684.argv_682 ("+++ argv_213::argv_826 - ERROR 5.1");
					bret = false;
				}
			}

			if (bret == true) {
				for (argv_663=m.begin() ; argv_663 != m.end() ; ++argv_663) {
					name_length = (argv_663->first).size();

					// argv_826 size of file name
					if (fwrite (&name_length, 1, 1, argv_316) != 1) {
						argv_684.argv_682 ("+++ argv_213::argv_826 - ERROR 4");
						bret = false;
						break;
					}

					// argv_826 filename
					if (fwrite ((argv_663->first).c_str(), 1, (argv_663->first).size(), argv_316) != (argv_663->first).size()) {
						argv_684.argv_682 ("+++ argv_213::argv_826 - ERROR 5");
						bret = false;
						break;
					}

					// argv_826 argv_234
					if (fwrite ((argv_663->second).c_str(), 1, argv_235, argv_316) != argv_235) {
						argv_684.argv_682 ("+++ argv_213::argv_826 - ERROR 6");
						bret = false;
						break;
					}
				}
			}
		}
	}

	if (argv_316 != NULL) {
		fclose (argv_316);
	}
	return (bret);
}

bool argv_213::argv_223 (const char * _filename) {
	bool bret = true;
	argv_234 = argv_226 (_filename, bret);



//	argv_234 = argv_225 (_filename);
#if defined (DEBUG_INTEGRITY_CHECKER)
	argv_684.argv_682 (_filename, argv_234.c_str());
#endif
	return (bret);
}

bool argv_213::argv_173 (const char * _filename, bool _ok_if_exists) {
	bool bret = true;
	if (_filename == NULL) {
		bret = false;
	}
	else {
		argv_663 = m.find (_filename);
		if (argv_663 != m.end()) {
			if (_ok_if_exists == false) {
#if defined (DEBUG_INTEGRITY_CHECKER_CORE)
				argv_684.argv_682 ("+++ WARNING : file already present");
#endif
				bret = false; // already present			
			}
		}
		else if (argv_223 (_filename) == false) {
#if defined (DEBUG_INTEGRITY_CHECKER_CORE)
			argv_684.argv_682 ("+++ ERROR: hash computation failed for file : ", _filename);
#endif
			bret = false;	
		}
		else {
#if defined (DEBUG_INTEGRITY_CHECKER_CORE)
			argv_684.argv_682 ("adding : ", _filename, ", argv_234: ", argv_234.c_str());
#endif
			m[_filename] = argv_234;
			{
				argv_259++;
				if ((argv_259%256) == 0) {
					char argv_876[256]; 
					if (argv_700 == false) {
						argv_853 (argv_876, 256, "creating DB from %c%c (%u files)", _filename[0], _filename[1], m.size());
					}
					else {
						argv_853 (argv_876, 256, "creating DB manually (%u files)", m.size());
					}
					argv_876[255] = '\0';
					SendDlgItemMessage (saved_hWnd, argv_409, WM_SETTEXT, 0, (LPARAM) argv_876);
				}
			}
		}
	}
	return (bret);
}

// check presence of file in container
argv_885 argv_213::argv_207 (const char * _filename) {
	argv_885 status = argv_891;

	argv_663 = m.find (_filename);
	if (argv_663 != m.end()) {
		if (argv_223 (_filename) == false) {
#if defined (DEBUG_INTEGRITY_CHECKER_CORE)
			argv_684.argv_682 (_filename, ": argv_893");
#endif
			status = argv_893;	
		}
		else {
			if (argv_663->second == argv_234) {
				status = argv_896;
			}
			else {
#if defined (DEBUG_INTEGRITY_CHECKER_CORE)
				char argv_876[argv_706];
				argv_853 (argv_876, argv_706, "file: %s has changed ! (old argv_234:%s, new argv_234:%s)", _filename, (argv_663->second).c_str(), argv_234.c_str());
				argv_876[argv_706 - 1] = '\0';
				argv_684.argv_682 (argv_876);
#endif
				status = argv_895;
			}
		}
	}
	else { // sometimes some files just can't be mmapped, so they can't be added
		// ensure we can mmap it before declaring it as absent from DB
		if (argv_223 (_filename) == false) {
			status = argv_893;
#if defined (DEBUG_INTEGRITY_CHECKER_CORE)
			argv_684.argv_682 ("argv_213::argv_207 - absent and failed to compute argv_234 for file : ", _filename);
#endif
		}
	}
	return (status);
}

void argv_315 (string& _result) {
	string new_str;
	string modified_str;
	string deleted_str;

	char argv_876[argv_706];
	argv_853 (argv_876, argv_706, "new:%u", argv_766);
	argv_876[argv_706 - 1] = '\0';
	new_str = argv_876;
	argv_853 (argv_876, argv_706, "modified:%u", argv_765);
	argv_876[argv_706 - 1] = '\0';
	modified_str = argv_876;
	argv_853 (argv_876, argv_706, "deleted:%u", argv_762);
	argv_876[argv_706 - 1] = '\0';
	deleted_str = argv_876;

	_result = " (";	
	_result = _result + new_str + ", ";
	_result = _result + deleted_str + ", ";
	_result = _result + modified_str;
	_result += ")";	
}

// check presence of all files of container on the disk
bool argv_213::argv_204 (map<string, argv_885>& _m_status) {
	bool bret = true;
	char argv_876[argv_706];
	argv_259 = 0;
	argv_885 total = m.size ();
	argv_885 percent;

	for (argv_663=m.begin() ; argv_663 != m.end() ; ++argv_663) {
		argv_259++;

		if ((argv_259%256) ==0) {
			percent = (argv_259 * 100) / total;
			string delta_report;
			argv_315 (delta_report);
			argv_853 (argv_876, argv_706, "checking drive %c%c step %d/%d...(%u %%)  -   %s", argv_663->first[0], argv_663->first[1], index+1, argv_879, percent, delta_report.c_str());
			argv_876[argv_706 - 1] = '\0';
			SendDlgItemMessage (saved_hWnd, argv_409, WM_SETTEXT, 0, (LPARAM) argv_876);	
		}

		if (argv_863 == true) {
			break;
		}

		if (argv_307 ((argv_663->first).c_str()) == false) {
			_m_status[argv_663->first] = argv_892;
			argv_853 (argv_876, argv_706, "[DEL] - %s", (argv_663->first).c_str());
			argv_876[argv_706 - 1] = '\0';
			argv_172 (argv_876);
		}
	}
	return (bret);
}

//=======================================================
// Integrity related file finder
//=======================================================
bool argv_214::argv_300 (const char * _dirname, vector<string>& v_dir) {
	if (argv_863 == true) {
		return (true);
	}

	bool bret = true;
	if (SetCurrentDirectory (_dirname) == false) {
		bret = false;
	}
	else {
		WIN32_FIND_DATA FindData; 
		HANDLE hFind = FindFirstFile ("*.*", &FindData);

		if (hFind == INVALID_HANDLE_VALUE) {
			bret = false;
		}
		else {
			argv_885 name_size;
			v_dir.clear ();
			do  {
				if (argv_863 ==  true) {
					return (true);
				}

				if (FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
					if((strcmp(FindData.cFileName, ".")!=0) && (strcmp(FindData.cFileName, "..")!=0)) {
#if ! defined (EXPLORE_HIDDEN_SYSTEM_DIR)
						if (argv_647 (FindData.cFileName) == true) {
#if defined (DEBUG_INTEGRITY_CHECKER)
							argv_684.argv_682 ("[SKIPPING] ", FindData.cFileName);
#endif
						} 
						else { 
#endif
							name_size = strlen (_dirname);
							if (name_size > 0) {
								string stmp = _dirname;

								if (_dirname[name_size - 1] != '\\') {
									v_dir.push_back (stmp + "\\" + FindData.cFileName);
								}
								else {
									v_dir.push_back (stmp + FindData.cFileName);
								}
							}
#if ! defined (EXPLORE_HIDDEN_SYSTEM_DIR)
						}
#endif
					}
				}
			}
			while (FindNextFile (hFind, &FindData)) ;
		}
		FindClose (hFind);
	}
	return (bret);
}

void argv_214::argv_836 (argv_196 _migale_install_folder) {
	argv_733 = _migale_install_folder;
}

void argv_214::argv_831 (argv_196 _root) {
	argv_259			= 0;
	argv_228	= false;
	argv_684.argv_682 ("exploring all from local root: ", _root);
	argv_298 (_root);
}

void argv_214::argv_832 (const char * _root) {
	argv_259			= 0;
	argv_228	= true;
	argv_684.argv_682 ("exploring all from local root: ", _root);
	argv_298 (_root);
}

void argv_214::argv_833 (const char * _root, map<string, argv_885>& _m_status, argv_885 _index, argv_885 _nb_hdd) {
	argv_228 = false;
	argv_835 (_root, _m_status, _index, _nb_hdd);
}

void argv_214::argv_834 (const char * _root, map<string, argv_885>& _m_status, argv_885 _index, argv_885 _nb_hdd) {
	argv_228 = true;
	argv_835 (_root, _m_status, _index, 1);
}

void argv_214::argv_835 (const char * _root, map<string, argv_885>& _m_status, argv_885 _index, argv_885 _nb_hdd) {
	if (argv_863 == false) {
		argv_764			= _nb_hdd;
		argv_879	= _nb_hdd + 1;
		index			= _index;
		if ((_index == 0) &&  (argv_863 == false)) {
			integ_db.argv_204 (_m_status);
		}
		argv_259 = 0;
		argv_697 = &_m_status;
		argv_298 (_root);
	}
}

argv_214::argv_214 () {
	argv_228 = false; // not only EXE, DLL, SYS, COM
}

void argv_214::argv_298 (const char * _root_arg) {
	bool bret;
	vector<string>	v_dir;
	if (argv_228 == true) {
		bret = argv_299 (_root_arg, "*.*");
	}
	else {
		bret = argv_299 (_root_arg, "*.exe");
		if (argv_863 == false) {
			bret = argv_299 (_root_arg, "*.dll");
		}
		if (argv_863 == false) {
			bret = argv_299 (_root_arg, "*.sys");
		}
		if (argv_863 == false) {
			bret = argv_299 (_root_arg, "*.com");
		}
	}

	if (argv_863 == false) {
		argv_300 (_root_arg, v_dir);
		argv_851 size = v_dir.size ();

		for (argv_851 i=0 ; i<size ; i++) {
			if (v_dir[i] != argv_733) {
				argv_298 (v_dir[i].c_str());
			}
			if (argv_863 == true) {
				break;
			}
		}
	}
}


bool argv_214::argv_299 (const char * _dirname, const char * _pattern_arg) {
	if (argv_863 == true) {
		return (true);
	}

	if (SetCurrentDirectory (_dirname) == false) {
		return (false);
	}

	WIN32_FIND_DATA FindData; 
	HANDLE hFind = FindFirstFile (_pattern_arg, &FindData);

	if (hFind == INVALID_HANDLE_VALUE) { // no file found at all
		return (true);
	}

	bool bret				= true;
	string	full_filename	= "";
	do {
		if (argv_863 == true) {
			break;
		}

		// if it is not a directory
		if (!(FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
			string stmp = _dirname;
			full_filename = stmp + "\\" + FindData.cFileName;
#if defined (DEBUG_INTEGRITY_CHECKER)				
			{
				char argv_876[argv_706];
				sprintf (argv_876, "processing file: %s", full_filename.c_str());
				argv_684.argv_682 (argv_876);
			}
#endif
			argv_803 (full_filename.c_str());
		}
	}
	while (FindNextFile (hFind, &FindData)) ;
	FindClose (hFind);
	return(true);
}

//====================================================
// argv_674 related file finder
//====================================================
void argv_215::argv_803 (const char * _filename) {
	bool bret = integ_db.argv_173 (_filename, true);
}


//====================================================
// check related file finder
//====================================================
void argv_195::argv_803 (const char * _filename) {
	argv_885 status = integ_db.argv_207 (_filename);
	if ((status != argv_896) && (status != argv_893)) {
		argv_697->operator[](_filename) = status;
		argv_865 = argv_858 (status);

		// copy file to destination folder
		string total_name;
		string new_name = argv_314 (_filename);
		if (status == argv_891) {
			argv_766++;
			total_name = argv_769 + "\\" + new_name;
		}
		else if (status == argv_895) {
			argv_765++;
			total_name = argv_754 + "\\" + new_name;
		}
		
		string ack = "";
		if (CopyFile (_filename, total_name.c_str(), FALSE) == 0) {
			ack = "(copy failed) ";
		}
		argv_853 (argv_876, argv_706, "%s[%s] - %s", ack.c_str(), argv_865.c_str(), _filename);
		argv_876[argv_706 - 1] = '\0';
		argv_172 (argv_876);
	}
	if ((argv_259%256) ==0) {
		string delta_report;
		argv_315 (delta_report);
		argv_853 (argv_876, argv_706, "checking drive %c%c step %d/%d (%u)   -   %s", _filename[0], _filename[1], index+2, argv_879, argv_259, delta_report.c_str());
		argv_876[argv_706 - 1] = '\0';
		SendDlgItemMessage (saved_hWnd, argv_409, WM_SETTEXT, 0, (LPARAM) argv_876);	
	}
	argv_259++;
}

string argv_314 (const char * _orig_file) {
	argv_885 size = strlen (_orig_file);
	string total_name;
	argv_885 i;
	for (i=size-1 ; i>=0 ; i--) {
		if (_orig_file[i] == '\\') {
			break;
		}
	}
	for (argv_885 k=i+1 ; k<size ; k++) {
		// replace all dots by an underscore so that matcher won't see these new files
		if (_orig_file[k] == '.') {
			total_name += '_';	
		}
		else {
			total_name += _orig_file[k]; 			
		}
	}

	string argv_234 = argv_225 (_orig_file);
	total_name += "_";
	total_name += argv_234;
	return (total_name);
}

void argv_172 (const char * _txt) {
	argv_172 (saved_hWnd, argv_464, _txt);
}

void argv_172 (HWND _hwnd, DWORD _idc, const char * _txt) {
	HDC argv_349 = GetDC (_hwnd);
	SIZE sz;
	int txt_size	= strlen (_txt);
	GetTextExtentPoint32 (argv_349, _txt, txt_size, &sz);

	int sysScrollWidth = GetSystemMetrics (SM_CXVSCROLL);
	int total_size	= sysScrollWidth + sz.cx;
	if (total_size > argv_709) {
		argv_709 = total_size;	
	}
	HWND hwnd_list = GetDlgItem (_hwnd, _idc); 		
	SendMessage (hwnd_list, LB_SETHORIZONTALEXTENT, argv_709, 0);
	SendDlgItemMessage (_hwnd, _idc, LB_ADDSTRING, 0, (LPARAM) _txt);
}