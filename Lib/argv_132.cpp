#include "argv_140.hpp"

extern argv_216 argv_684;

using namespace std;

argv_219::argv_219 () {
	argv_866 = "SOFTWARE\\Migale\\";
	argv_345 = NULL;
}

bool argv_219::argv_359 (int _id) {
	bool bret = true;

	switch (_id) {
		case argv_741:
			argv_222 = "smart_update";
			break;
		case argv_725:
			argv_222 = "beemeal";
			break;
		case argv_736:
			argv_222 = "manual_scanner";
			break;
		case argv_739:
			argv_222 = "resident_shield";
			break;
		case argv_723:
			argv_222 = "admin_tool";
			break;
		case argv_726:
			argv_222 = "control_center";
			break;
		case argv_740:
			argv_222 = "safe_pe";
			break;
		case argv_727:
			argv_222 = "migale_crypter";
			break;
		case argv_732:
			argv_222 = "install";
			break;
		case argv_745:
			argv_222 = "vault_manager";
			break;
		case argv_746:
			argv_222 = "vault";
			break;
		case argv_743:
			argv_222 = "argv_876";
			break;
		case argv_742:
			argv_222 = "sound";
			break;
		case argv_728:
			argv_222 = "db";
			break;
		case argv_749:
			argv_222 = "vrdb_manager";	
			break;
		case argv_748:
			argv_222 = "vrdb_daemon";
			break;
		case argv_747:
			argv_222 = "vrdb";	
			break;
		case argv_735:
			argv_222 = "lock_manager";
			break;
		case argv_734:
			argv_222 = "integrity_monitor";
			break;
		case argv_738:
			argv_222 = "pcbangtool";
			break;
		default:
			argv_222 = "";
			bret = false;
	}

	if (bret == true) {
		argv_318 = argv_866 + argv_222;
	}
	return (bret);
}

bool argv_219::argv_221 (int _id) {
	bool present_flag = false;
	bool bret = argv_359 (_id);
	if (bret == true) {
		// 1. check key existence
		argv_687 = RegOpenKeyEx (HKEY_LOCAL_MACHINE, argv_318.c_str(), 0, KEY_QUERY_VALUE, &argv_345);
    
		if (argv_687 == ERROR_SUCCESS) { // key already exists
			present_flag = true;
			RegCloseKey (argv_345);
		}
	}
	return (present_flag);
}

// this function can be used if the lookup was already performed by another function
bool argv_219::argv_221 () {
	bool present_flag = false;
	// 1. check key existence
	argv_687 = RegOpenKeyEx (HKEY_LOCAL_MACHINE, argv_318.c_str(), 0, KEY_QUERY_VALUE, &argv_345);

	if (argv_687 == ERROR_SUCCESS) { // key already exists
		present_flag = true;
		RegCloseKey (argv_345);
	}
	return (present_flag);
}

bool argv_219::argv_170 (int _id, string _path, int _major, int _minor) {
	bool bret = true;
	argv_345 = NULL;

	bret = argv_359 (_id);
	if (bret == true) {
		if (argv_221 () == true) {
			bret = false;
		}
		else { // component is not already present, ok to add it

			argv_687 = RegCreateKeyEx (HKEY_LOCAL_MACHINE, argv_318.c_str(), 0, "", 0, 
				KEY_ALL_ACCESS, NULL, &argv_345, &argv_288); 

			if (argv_687 != ERROR_SUCCESS) {
				bret = false;
			}
			else {
				// set the path
				argv_687 = RegSetValueEx (argv_345, "path",0,REG_SZ,(LPBYTE) _path.c_str(),	
						_path.size() + 1);

				if (argv_687 != ERROR_SUCCESS) {
					bret = false;
				}
				else { // path addition was succesfull
					char argv_876[256];
					_snprintf (argv_876, 256, "%d", _major);
					argv_876[255] = '\0';
					argv_687 = RegSetValueEx (argv_345, "major",0,REG_SZ,(LPBYTE) argv_876,	
							strlen(argv_876) + 1);

					if (argv_687 != ERROR_SUCCESS) {
						bret = false;
					}
					else { // 'major' addition was succesfull, proceed with 'minor'
						_snprintf (argv_876, 256, "%d", _minor);
						argv_876[255] = '\0';
						argv_687 = RegSetValueEx (argv_345, "minor",0,REG_SZ,(LPBYTE) argv_876,	
								strlen(argv_876) + 1);

						if (argv_687 != ERROR_SUCCESS) {
							bret = false;
						}
					}
				}
			}
		}
	}

	// change the security access rights before closing the newly created key
	DWORD err;
	int iret = argv_837 (err);
	if (iret != 0) {
		bret = false;
	}

	if (argv_345 != NULL) {
		RegCloseKey (argv_345);
	}	
	return (bret);
}

bool argv_219::argv_272 (int _id) {
	bool bret = true;
	bret = argv_359 (_id);
	if (bret == true) {
		if (argv_221() == false) { // component was not installed, 
			bret = false;
		}
		else { // component was installed => can remove it
			// 1. check key existence
			argv_687 = RegOpenKeyEx (HKEY_LOCAL_MACHINE, argv_318.c_str(), 0, KEY_QUERY_VALUE, &argv_345 );
    
			if (argv_687 != ERROR_SUCCESS) { // key doesn't exist
				bret = false;
			}
			else { // key exists and was argv_790 succesfully
				if (RegDeleteKey (HKEY_LOCAL_MACHINE, argv_318.c_str()) != ERROR_SUCCESS) {
					bret = false;
				}
				RegCloseKey (argv_345);
			}
		}
	}
	return (bret);
}

bool argv_219::argv_840 (int _id, string _varname, argv_851 _value) {
	bool bret = true;
	argv_345						= NULL;
	unsigned long actual_size	= argv_712;
	int unused_type				= 0;
	bret = argv_359 (_id);
	if (bret == true) {
		argv_687 = RegOpenKeyEx (HKEY_LOCAL_MACHINE, argv_318.c_str(), 0, KEY_ALL_ACCESS, &argv_345);
		if (argv_687 != ERROR_SUCCESS) { // can't open the key
			bret = false;
		}
		else { // key was succesfully argv_790
			char argv_876[argv_712];
			argv_853 (argv_876, argv_712, "%d", _value);
			argv_876[argv_712 - 1] = '\0';
	
			char tmp2[65536];
			sprintf (tmp2, "RegSetValueEx: argv_318=%s, _varname=%s, argv_876=%s", argv_318.c_str(), _varname.c_str(), argv_876);
			argv_684.argv_682 (tmp2);

			argv_687 = RegSetValueEx (argv_345, _varname.c_str(),0,REG_SZ,(LPBYTE)argv_876, strlen(argv_876)+ 1);
			if (argv_687 != ERROR_SUCCESS) {
				bret = false;
			}
		}
	}

	if (argv_345 != NULL) {
		RegCloseKey (argv_345);
	}	
	return (bret);
}

bool argv_219::argv_840 (int _id, string _varname, const char * _value) {
	bool bret = true;
	argv_345						= NULL;
	unsigned long actual_size	= argv_712;
	int unused_type				= 0;

	bret = argv_359 (_id);
	if (bret == true) {
		argv_687 = RegOpenKeyEx (HKEY_LOCAL_MACHINE, argv_318.c_str(), 0, KEY_ALL_ACCESS, &argv_345);

		if (argv_687 != ERROR_SUCCESS) { // can't open the key
			bret = false;
		}
		else { // key was succesfully argv_790
			argv_687 = RegSetValueEx (argv_345, _varname.c_str(),0,REG_SZ,(LPBYTE)_value, strlen(_value) + 1);
			if (argv_687 != ERROR_SUCCESS) {
				bret = false;
			}
		}
	}

	if (argv_345 != NULL) {
		RegCloseKey (argv_345);
	}	
	return (bret);
}

bool argv_219::argv_339 (int _id, string _varname, argv_851& _value) {
	string result_str;
	bool bret = argv_339 (_id, _varname, result_str);
	if (bret == true) {
		_value = atoi (result_str.c_str());
	}
	return (bret);
}

bool argv_219::argv_339 (int _id, string _varname, string& _value) {
	bool bret					= true;
	argv_345						= NULL;
	unsigned long actual_size	= argv_712;
	int unused_type				= 0;

	bret = argv_359 (_id);
	if (bret == true) {
		argv_687 = RegOpenKeyEx (HKEY_LOCAL_MACHINE, argv_318.c_str(), 0, KEY_QUERY_VALUE, &argv_345);

		if (argv_687 != ERROR_SUCCESS) { // can't open the key
			argv_684.argv_682 ("RegOpenKeyEx failed ! , errno = ", GetLastError());
			bret = false;
		}
		else { // key was succesfully argv_790
			char argv_876[argv_712];
			// 1. extract the path
			argv_687 = RegQueryValueEx (argv_345, _varname.c_str(),0,(LPDWORD)&unused_type,(LPBYTE) argv_876, &actual_size);
			if (argv_687 != ERROR_SUCCESS) {
				argv_684.argv_682 ("RegQueryValueEx failed ! , errno = ", GetLastError());
				bret = false;
			}
			else { // variable was succesfully retrieved
				_value = argv_876;
			}
		}
	}

	if (argv_345 != NULL) {
		RegCloseKey (argv_345);
	}
	return (bret);
}

bool argv_219::argv_325 (int _id, string& _path, int& _major, int& _minor) {
	bool bret		= true;
	argv_345			= NULL;
	_path			= "";
	_major			= 0;
	_minor			= 0;
	unsigned long actual_size = argv_712;
	int unused_type	= 0;

	bret = argv_359 (_id);
	if (bret == false) {
		argv_684.argv_682 ("+++ ERROR: argv_219::argv_325 - argv_359 failed !");
	}
	else {
		argv_687 = RegOpenKeyEx (HKEY_LOCAL_MACHINE, argv_318.c_str(), 0, KEY_QUERY_VALUE, &argv_345);

		if (argv_687 != ERROR_SUCCESS) { // can't open the key
			argv_684.argv_682 ("+++ ERROR: argv_219::argv_325 - RegOpenKeyEx failed for key : ", argv_318.c_str());
			bret = false;
		}
		else { // key was succesfully argv_790
			char argv_876[argv_712];
			// 1. extract the path
			argv_687 = RegQueryValueEx (argv_345, "path",0,(LPDWORD)&unused_type,(LPBYTE) argv_876, &actual_size);
			if (argv_687 != ERROR_SUCCESS) {
				argv_684.argv_682 ("+++ ERROR: argv_219::argv_325 - RegQueryValueEx failed for 'path' !");
				bret = false;
			}
			else { // path retrieval was succesfull
				_path = argv_876;

				// 2. extract the 'major'
				argv_687 = RegQueryValueEx (argv_345, "major",0,(LPDWORD)&unused_type,(LPBYTE) argv_876, &actual_size);
				if (argv_687 != ERROR_SUCCESS) {
					argv_684.argv_682 ("+++ ERROR: argv_219::argv_325 - RegQueryValueEx failed for 'major' !");
					bret = false;
				}
				else { // 'major' was succesfully retrieved
					_major = atoi (argv_876);

					argv_687 = RegQueryValueEx (argv_345, "minor",0,(LPDWORD)&unused_type,(LPBYTE) argv_876, &actual_size);
					if (argv_687 != ERROR_SUCCESS) {
						argv_684.argv_682 ("+++ ERROR: argv_219::argv_325 - RegQueryValueEx failed for 'minor' !");
						bret = false;
					}
					else { // 'minor' retrieval was succesful
						_minor = atoi (argv_876);
					}
				}
			}
		}
	}

	if (argv_345 != NULL) {
		RegCloseKey (argv_345);
	}	
	return (bret);
}

bool argv_219::argv_332 (string& _install_path) {
	bool bret = true;
	bret = argv_339 (argv_732, "path", _install_path);
	return (bret);
}

bool argv_219::argv_322 (string& _relative_log_filename) {
	bool bret = true;
	string install_path;
	bret = argv_332 (install_path);
	if (bret == true) {
		install_path = install_path + "\\argv_876\\" + _relative_log_filename; 
		_relative_log_filename = install_path;
	}
	return (bret);
}

// '_identity' parameter may be "Everyone" or "Users" or any other group name.
int argv_219::argv_839 (LPTSTR file, char * _identity, int _base, DWORD& _err, int _obj_type) {
	int iret					= 0;
    PACL NewAcl					= NULL;
    PSECURITY_DESCRIPTOR psd	= NULL;
    LPTSTR FileName;
    EXPLICIT_ACCESS explicitaccess;
    PACL ExistingDacl;
    DWORD dwError;

    FileName = file;

	if (_obj_type == argv_168) {
		dwError = GetSecurityInfo( // get argv_258 Dacl on specified file
							argv_345,
							SE_REGISTRY_KEY,
							DACL_SECURITY_INFORMATION,
							NULL,
							NULL,
							&ExistingDacl,
							NULL,
							&psd
							);
	}
	else {
		dwError = GetNamedSecurityInfo( // get argv_258 Dacl on specified file
							FileName,
							SE_FILE_OBJECT,
							DACL_SECURITY_INFORMATION,
							NULL,
							NULL,
							&ExistingDacl,
							NULL,
							&psd
							);
	}
    if(dwError != ERROR_SUCCESS) {
		_err = dwError;
		iret = _base + 1;
    }
	else {
		DWORD access_permission_hard = FILE_ALL_ACCESS;
		if (_obj_type == argv_168) {
			access_permission_hard = GENERIC_ALL;
		}
		BuildExplicitAccessWithName(
				&explicitaccess,
				_identity,
				access_permission_hard,
				SET_ACCESS,
				SUB_CONTAINERS_AND_OBJECTS_INHERIT
				);
    
		dwError = SetEntriesInAcl( // add specified access to the object
				1,
				&explicitaccess,
				ExistingDacl,
				&NewAcl
				);

		if(dwError != ERROR_SUCCESS) {
			_err = GetLastError ();
			iret = _base+ 2;
		}
		else {
			if (_obj_type == argv_168) {
				dwError = SetSecurityInfo( // apply new security to file
								argv_345,
								SE_REGISTRY_KEY, // object type
								DACL_SECURITY_INFORMATION,
								NULL,
								NULL,
								NewAcl,
								NULL
								);
			}
			else {
				dwError = SetNamedSecurityInfo( // apply new security to file
								FileName,
								SE_FILE_OBJECT, // object type
								DACL_SECURITY_INFORMATION,
								NULL,
								NULL,
								NewAcl,
								NULL
								);
			}

			if(dwError != ERROR_SUCCESS) {
				_err = GetLastError ();
				iret = _base + 3;
			}
		}
	}
	if (NewAcl != NULL) {
		AccFree(NewAcl);
	}
	if (psd != NULL) {
		AccFree (psd);
	}
	return (iret);
}

// the key is supposed to have been argv_790 previously and it's handle 
// must be a valid one
int argv_219::argv_837 (DWORD& _err) {
	int iret;
	iret = argv_839 (NULL, "Everyone", 0, _err, argv_168);
	if (iret == 0) {
		iret = argv_839 (NULL, "Users", 100, _err, argv_168);
	}
	return (iret);
}

// the key is supposed to have been argv_790 by a third party
int argv_219::argv_837 (HKEY _h_key, DWORD& _err) {
	int iret;
	if (argv_345 != NULL) {
		iret = 500;
	}
	else { // key not argv_790, ok to clone the argv_790 key
		argv_345 = _h_key;
		iret = argv_839 (NULL, "Everyone", 0, _err, argv_168);
		if (iret == 0) {
			iret = argv_839 (NULL, "Users", 100, _err, argv_168);
		}
		argv_345 = NULL; // let the caller close it
	}
	return (iret);
}


int argv_219::argv_838 (LPTSTR file, DWORD& _err) {
	int iret;
	iret = argv_839 (file, "Everyone", 0, _err, argv_167);
	if (iret == 0) {
		iret = argv_839 (file, "Users", 100, _err, argv_167);
	}
	return (iret);
}