#include "argv_122.h"
#include "argv_124.h"
#include "..\\Lib\\argv_136.hpp"
#include <sstream>

using namespace std;

HWND				saved_hWnd;
LRESULT CALLBACK	argv_165(HWND, UINT, WPARAM, LPARAM);
argv_216				argv_684;
long * argv_529 = NULL;
long * argv_477  = NULL;


extern argv_213	integ_db;

long				argv_475;
long				argv_634			= 1974;
long				argv_635			= 1975;
long				argv_636			= 1976;
long				argv_464			= argv_465;
long				argv_409			= argv_410;

bool				argv_856				= false;
bool				argv_863				= false;
bool				argv_265			= false;
bool				argv_164			= true;
bool				argv_264	= false;
bool				argv_282;
bool				argv_780		= true;
bool				argv_774		= false;
bool				argv_809			= true;
bool				argv_700			= false;

argv_885				argv_686 = 10;
argv_885				shutdown_countdown	= 50;
argv_885				argv_848		= 0;
argv_885				argv_766				= 0;
argv_885				argv_765			= 0;
argv_885				argv_762			= 0;

string				install_path		= "";
string				argv_266;
string				argv_268				= "integ_db.txt";
string				argv_317;
string				argv_754;
string				argv_769;
string				argv_263;
string				argv_220;
string				argv_701;
string				argv_343;
std::string			argv_270;		

argv_231			argv_791;
argv_885				argv_260;
vector<argv_885>		argv_903;
HWND				hwndGoto_help	= NULL;

// Global Variables:
#define		argv_710 100
HINSTANCE	argv_353;								// argv_258 instance
TCHAR		argv_868[argv_710];			// The title bar text
TCHAR		argv_869[argv_710];		// The title bar text

ATOM				argv_760(HINSTANCE hInstance);
BOOL				argv_637(HINSTANCE, int);
LRESULT CALLBACK	argv_909(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	argv_165(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	MSG msg;
	HACCEL hAccelTable;
	LoadString(hInstance, argv_632, argv_868, argv_710);
	LoadString(hInstance, argv_607, argv_869, argv_710);
	argv_760(hInstance);
	argv_220 = lpCmdLine;

	if (!argv_637 (hInstance, nCmdShow))  {
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)argv_607);
	while (GetMessage(&msg, NULL, 0, 0))  {
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))  {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return msg.wParam;
}

ATOM argv_760(HINSTANCE hInstance) {
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX); 
	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)argv_909;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)argv_626);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)argv_607;
	wcex.lpszClassName	= argv_869;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)argv_623);
	return RegisterClassEx(&wcex);
}

BOOL argv_637(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	argv_353 = hInstance; // Store instance handle in our global variable

	hWnd = CreateWindow(argv_869, argv_868, WS_VISIBLE | WS_OVERLAPPEDWINDOW,
	  CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
	  return FALSE;
	}

	ShowWindow(hWnd, SW_SHOWMINIMIZED);
	UpdateWindow(hWnd);
	saved_hWnd = hWnd;

	DialogBox(argv_353, (LPCTSTR)argv_608, hWnd, (DLGPROC)argv_165);
	DestroyWindow(hWnd);
	return TRUE;
}

HDC argv_342;

LRESULT CALLBACK argv_909(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT argv_805;
	HDC argv_349;
	
	TCHAR szHello[argv_710];
	LoadString(argv_353, argv_633, szHello, argv_710);

	switch (message) 
	{
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			switch (wmId)
			{
				case argv_628:
				   DialogBox(argv_353, (LPCTSTR)argv_608, hWnd, (DLGPROC)argv_165);
				   break;
				case argv_629:
				   DestroyWindow(hWnd);
				   break;

				case argv_630:
					argv_781(hWnd, argv_782);
					break;

				default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;
		case WM_PAINT:
			argv_349 = BeginPaint(hWnd, &argv_805);
			argv_342 = argv_349;
			// TODO: Add any drawing code here...
			RECT rt;
			GetClientRect(hWnd, &rt);
			DrawText(argv_349, szHello, strlen(szHello), &rt, DT_CENTER);
			EndPaint(hWnd, &argv_805);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

void argv_902 () {
	HWND hwnd_std = GetDlgItem (saved_hWnd, argv_393); 
	std::stringstream ioss (std::stringstream::in | std::stringstream::out);
	ioss << "Check Integrity (" << argv_270 << ")";
	SetWindowText (hwnd_std, ioss.str().c_str());
}

DWORD WINAPI argv_284 (LPVOID lParam) {
	argv_809 = false;
	char argv_876[argv_706];
	SendDlgItemMessage (saved_hWnd, argv_410, WM_SETTEXT, 0, (LPARAM) "Check in progress...");	
	Sleep (250);
	if (argv_265 == false) {	
		MessageBox (saved_hWnd, "Please create a DB first !", "DB not Loaded", MB_OK | MB_ICONWARNING);
	}
	else {
		argv_172 ("----------  CHECK RESULT ----------");
		argv_766 = argv_765 = argv_762 = 0;
		// SendDlgItemMessage (saved_hWnd, argv_464, LB_RESETCONTENT, 0, (LPARAM) 0);
		argv_195 integ_finder;
		integ_finder.argv_836 (install_path.c_str());

		map<string, argv_885> m_status;
		vector<string> v_hdd;
		argv_331 (v_hdd);
		argv_885 argv_764 = v_hdd.size();
		argv_885 i;

		if (argv_700 == true) {
			argv_701 = integ_db.argv_341 ();
			argv_684.argv_682 ("argv_284 - checking from manual root folder: ", argv_701.c_str());
			if (argv_780 == true) {
				integ_finder.argv_833 (argv_701.c_str(), m_status, 0, 1);	
			}
			else {
				integ_finder.argv_834 (argv_701.c_str(), m_status, 0, 1);	
			}
		}
		else {
			for (i=0 ; i<argv_764 ; i++) {
				if (argv_863 == true) {
					break;
				}
				if (argv_780 == true) {
					integ_finder.argv_833 (v_hdd[i].c_str(), m_status, i, argv_764);	
				}
				else {
					integ_finder.argv_834 (v_hdd[i].c_str(), m_status, i, argv_764);
				}
			}
		}
		if (argv_700 == false) {
			argv_853 (argv_876, argv_706, "Ready@Auto (%u differences noticed, database contains %u files)", m_status.size(), integ_db.argv_336());
		}
		else {
			argv_853 (argv_876, argv_706, "Ready@Manual (%u differences noticed, manual database contains %u files)", m_status.size(), integ_db.argv_336());
		}
		argv_876[argv_706 - 1] = '\0';
		SendDlgItemMessage (saved_hWnd, argv_410, WM_SETTEXT, 0, (LPARAM) argv_876);	
		argv_853 (argv_876, argv_706, "%u differences noticed (database contains %u files)", m_status.size(), integ_db.argv_336());
		argv_876[argv_706 - 1] = '\0';
		argv_172 (argv_876);
	}

	argv_863	= false;
	argv_856 = false;

	if (argv_774 == false) {
		HWND hwnd_std = GetDlgItem (saved_hWnd, argv_415);  
		EnableWindow (hwnd_std, TRUE);
		argv_902 ();
	}

	// schedule an automatic check every X minutes
	if (argv_282 == true) {
		char tmp2[argv_706];
		GetDlgItemText (saved_hWnd, argv_410, tmp2, argv_706);
		string argv_865 = tmp2;
		argv_865 += " - scheduled";
		SendDlgItemMessage (saved_hWnd, argv_410, WM_SETTEXT, 0, (LPARAM) argv_865.c_str());	
		SetTimer (saved_hWnd, argv_634, argv_686 * 1000, (TIMERPROC) NULL);
	}
	argv_809 = true;
	return(TRUE);
}

DWORD WINAPI argv_283 (LPVOID lParam) {
	argv_809 = false;
	bool really_doit = true;
	if ((argv_265 == true) && (argv_700 == false)) {
		if (MessageBox (saved_hWnd, "DB already argv_675 ! Erase DB and create a new one ?", "Question", MB_YESNO | MB_ICONWARNING)==IDNO) {
			really_doit = false;
		}
	}

	char argv_876[256];

	if (really_doit == true) {
		vector<string> v_hdd;
		argv_215 finder;
		finder.argv_836 (install_path.c_str());
		argv_331 (v_hdd);
		argv_885 argv_764 = v_hdd.size();

		integ_db.clear ();

		std::string RootFolderForDbSaver;
		if (argv_700 == true) {
			RootFolderForDbSaver = argv_701;
			argv_853 (argv_876, 256, "Exploring chosen folder %s", argv_701.c_str());
			argv_876[255] = '\0';
			SendDlgItemMessage (saved_hWnd, argv_410, WM_SETTEXT, 0, (LPARAM) argv_876);
			if (argv_780 == false) {
				argv_172 ("(All files will be monitored (not only EXE, SYS, DLL, COM files))");
				finder.argv_832 (argv_701.c_str()); 		
			}
			else {
				argv_172 ("(monitoring only system files (exe,sys,dll,com)))");
				finder.argv_831 (argv_701.c_str());
			}
		}
		else {
			for (argv_885 i=0 ; i<argv_764 ; i++) {
				argv_853 (argv_876, 256, "exploring drive %s", v_hdd[i].c_str());
				argv_876[255] = '\0';
				SendDlgItemMessage (saved_hWnd, argv_410, WM_SETTEXT, 0, (LPARAM) argv_876);
				if (argv_780 == false) {
					finder.argv_832 (v_hdd[i].c_str());
				}
				else {
					finder.argv_831 (v_hdd[i].c_str());
				}
			}
		}
		argv_885 size = integ_db.argv_336 ();
		bool bret = integ_db.argv_826 (argv_317.c_str(), argv_780, RootFolderForDbSaver);
		argv_684.argv_682 ("saving DB to : ", argv_317.c_str());
		if (bret == false) {
			MessageBox (saved_hWnd, "saved DB failed !", "Error", MB_OK | MB_ICONERROR);
		}
		
		argv_853 (argv_876, 256, "database size: %u", size);
		argv_876[255] = '\0';
		SendDlgItemMessage (saved_hWnd, argv_410, WM_SETTEXT, 0, (LPARAM) argv_876);
		argv_265 = true;
	}
	argv_863	= false;
	argv_856 = false;
	string only_sys_str;
	if (argv_780 == false) {
		only_sys_str = "All file types";	
	}
	else {
		only_sys_str = "Only system files";
	}

	if (argv_700 == false) {
		argv_853 (argv_876, 256, "Ready (database argv_675: %d files (%s))", integ_db.argv_336 (), only_sys_str.c_str());
	}
	else { 
		argv_853 (argv_876, 256, "Ready (Manual database argv_675: %d files (%s))", integ_db.argv_336 (), only_sys_str.c_str());
	}
	argv_876[255] = '\0';
	SendDlgItemMessage (saved_hWnd, argv_410, WM_SETTEXT, 0, (LPARAM) argv_876);	
	if (argv_774 == false) {
		HWND hwnd_std = GetDlgItem (saved_hWnd, argv_393);  
		EnableWindow (hwnd_std, TRUE);
		hwnd_std = GetDlgItem (saved_hWnd, argv_415);  
		EnableWindow (hwnd_std, TRUE);
		hwnd_std = GetDlgItem (saved_hWnd, argv_416);  
		EnableWindow (hwnd_std, TRUE);
		hwnd_std = GetDlgItem (saved_hWnd, argv_415);  
		SetWindowText (hwnd_std,"Create DB");
		hwnd_std = GetDlgItem (saved_hWnd, argv_416);  
		SetWindowText (hwnd_std,"Snapshot Mode");
	}
	argv_809 = true;
	return(TRUE);
}

bool argv_238 (HWND hDlg_arg) {
	bool bret = true;
	
	DWORD dwThreadId;
	HANDLE hThread; 

	hThread = CreateThread( 
		NULL,							// default security attributes 
		0,								// use default stack size  
		argv_284,					// thread function 
		NULL,							// argument to thread function 
		0,								// use default creation flags 
		&dwThreadId);					// returns the thread identifier 

	if (hThread == NULL)   {
		MessageBox(hDlg_arg, "Thread creation failed", "Error", MB_OK | MB_ICONERROR);			
		bret = false;
	}

	if (SetThreadPriority (hThread, THREAD_PRIORITY_IDLE) == false) {
		MessageBox(hDlg_arg, "Thread priority change failed", "Error", MB_OK | MB_ICONERROR);			
	}

	return (bret);
}

bool argv_237 (HWND hDlg_arg) {
	bool bret = true;
	
	DWORD dwThreadId;
	HANDLE hThread; 

	hThread = CreateThread( 
		NULL,							// default security attributes 
		0,								// use default stack size  
		argv_283,					// thread function 
		NULL,							// argument to thread function 
		0,								// use default creation flags 
		&dwThreadId);					// returns the thread identifier 

	if (hThread == NULL)   {
		MessageBox(hDlg_arg, "Thread creation failed", "Error", MB_OK | MB_ICONERROR);			
		bret = false;
	}

	if (SetThreadPriority (hThread, THREAD_PRIORITY_IDLE) == false) {
		MessageBox(hDlg_arg, "Thread priority change failed", "Error", MB_OK | MB_ICONERROR);			
	}

	return (bret);
}

string argv_327 (const char * _full_db_path) {
	argv_885 argv_912, argv_758, argv_262, argv_355, argv_751, second, argv_750, retcode, ersource; 
	char argv_876[256];
	if (argv_818 (_full_db_path, argv_912, argv_758, argv_262, argv_355, argv_751, second, argv_750, retcode, ersource) == true) {
		argv_853 (argv_876, 256, "%d/%02d/%02d - %02dh%02d", argv_912, argv_758, argv_262, argv_355, argv_751);
		argv_876[255] = '\0';
	}
	return (argv_876);
}

DWORD WINAPI argv_286 (LPVOID lParam) {
	SendDlgItemMessage (saved_hWnd, argv_410, WM_SETTEXT, 0, (LPARAM) "loading database...");
	Sleep (0);
	HWND hwnd_std;
	if (argv_774 == false) {
		hwnd_std = GetDlgItem (saved_hWnd, argv_415); 		
		EnableWindow (hwnd_std, FALSE);
		hwnd_std = GetDlgItem (saved_hWnd, argv_393); 		
		EnableWindow (hwnd_std, FALSE);
	}

	bool bret = integ_db.argv_674 (argv_317.c_str(), argv_780);
	if (bret == true) {
		if (argv_780 == false) {
			argv_890 ();
		}
		else {
			argv_205 ();
		}
		argv_265 = true;
		string only_sys_str = "All file types";
		if (argv_780 == true) {
			only_sys_str = "Only SYS files";
		}

		// extract the DB date
		argv_263 = argv_327 (argv_317.c_str());
		char argv_876[argv_706];
		argv_853 (argv_876, argv_706, "Ready (DB argv_675: %d files (%s) - generated: %s)", integ_db.argv_336(), only_sys_str.c_str(), argv_263.c_str());
		argv_876[argv_706 - 1] = '\0';
		SendDlgItemMessage (saved_hWnd, argv_410, WM_SETTEXT, 0, (LPARAM) argv_876);
		hwnd_std = GetDlgItem (saved_hWnd, argv_393); 		
		EnableWindow (hwnd_std, TRUE);
	}
	else {
		hwnd_std = GetDlgItem (saved_hWnd, argv_393); 		
		EnableWindow (hwnd_std, FALSE);

		SendDlgItemMessage (saved_hWnd, argv_410, WM_SETTEXT, 0, (LPARAM) "Ready (DB could not be argv_675)");
		if (argv_264 == true) {
			MessageBox (saved_hWnd, "Failed to argv_674 database ! (please check parameters, or create a new database)", "Error", MB_OK | MB_ICONERROR);	
		}
	}

	if (argv_774 == false) {
		hwnd_std = GetDlgItem (saved_hWnd, argv_415); 		
		EnableWindow (hwnd_std, TRUE);
	}
	argv_856		= false;
	argv_809 = true;
	return (0);
}

bool argv_239 (HWND _hwnd) {
	bool bret = true;

	if (argv_856 == false) {
		argv_856 = true;
		DWORD dwThreadId;
		HANDLE hThread; 

		hThread = CreateThread( 
			NULL,							// default security attributes 
			0,								// use default stack size  
			argv_286,					// thread function 
			NULL,							// argument to thread function 
			0,								// use default creation flags 
			&dwThreadId);					// returns the thread identifier 

		if (hThread == NULL)   {
			MessageBox (_hwnd, "Thread creation failed", "Error", MB_OK | MB_ICONERROR);			
			bret = false;
		}
	}
	return (bret);
}

void argv_796 (HWND hDlg) {
	HWND hwnd_std;

	if (argv_774 == false) {
		hwnd_std = GetDlgItem (hDlg, argv_415);  
		EnableWindow (hwnd_std, FALSE);
	}

	if (argv_856 == false) {
		if (argv_774 == false) {
			hwnd_std = GetDlgItem (hDlg, argv_393); 
			SetWindowText (hwnd_std,"Stop");
		}
		argv_238 (hDlg);
		argv_863    = false;
		argv_856 = true;
	}
	else {
		argv_863	= true;
		argv_856 = false;
	}
}


bool argv_242 (argv_196 _install_path) {
	bool bret = true;

	string integrity_monitor_path = install_path;
	integrity_monitor_path	= integrity_monitor_path + "\\integrity_monitor";
	argv_266					= integrity_monitor_path + "\\DB";
	string virus_path		= integrity_monitor_path + "\\VIRUS";
	argv_754		= virus_path + "\\MODIFIED";
	argv_769			= virus_path + "\\NEW";

	if (argv_313 (integrity_monitor_path.c_str()) == false) {
		bret = argv_240 (integrity_monitor_path.c_str());
		if (bret == false) {
			MessageBox (NULL, "Failed to create 'integrity monitor' path !", "", MB_ICONERROR);		
		}
		else {
			argv_172 ("created 'integrity monitor' folder");
		}
	}

	if (bret == true) {
		if (argv_313 (argv_266.c_str()) == false) {
			bret = argv_240 (argv_266.c_str());
			if (bret == false) {
				MessageBox (NULL, "Failed to create 'argv_266' !", "", MB_ICONERROR);		
			}
			else {
				argv_172 ("created 'db' folder");
			}
		}
	}

	if (bret == true) {
		if (argv_313 (virus_path.c_str()) == false) {
			bret = argv_240 (virus_path.c_str());
			if (bret == false) {
				MessageBox (NULL, "Failed to create 'virus_path' path !", "", MB_ICONERROR);		
			}
			else {
				argv_172 ("created 'virus' folder");
			}
		}
	}

	if (bret == true) {
		if (argv_313 (argv_754.c_str()) == false) {
			bret = argv_240 (argv_754.c_str());
			if (bret == false) {
				MessageBox (NULL, "Failed to create 'argv_754' !", "", MB_ICONERROR);		
			}
			else {
				argv_172 ("created 'modified files' folder");
			}
		}
	}

	if (bret == true) {
		if (argv_313 (argv_769.c_str()) == false) {
			bret = argv_240 (argv_769.c_str());
			if (bret == false) {
				MessageBox (NULL, "Failed to create 'argv_769' !", "", MB_ICONERROR);		
			}
			else {
				argv_172 ("created 'new files' folder");
			}
		}
	}
	return (bret);
}

bool argv_302 (HWND hDlg) {
	argv_219 migale_registry;
	bool bret		= true;

	install_path	= "";
	int		unused	= 0;

	if ((argv_791.argv_267 == false) || (argv_791.argv_756 == false) || (argv_791.argv_771 == false)) {
		bret = migale_registry.argv_325 (argv_732, install_path, unused, unused);
		if (bret == true) {
			argv_266				= install_path + "\\integrity_monitor\\DB";
			argv_754 = install_path + "\\integrity_monitor\\VIRUS\\MODIFIED";
			argv_769		= install_path + "\\integrity_monitor\\VIRUS\\NEW";
		}
		else {
			argv_172 ("*** WARNING: Migale product not installed");
			argv_172 ("*** WARNING: using argv_258 directory as root");
			char current_dir[MAX_PATH];
			GetCurrentDirectory (MAX_PATH, current_dir);
			install_path = current_dir;
			bret = argv_242 (install_path.c_str());
			if (bret == false) {
				argv_172 ("+++ ERROR: one or more folder creation failed !");
			}
		}
	}

	// parameters passed to program overwrite the default path
	if (argv_791.argv_267 == true) {
		argv_266 = argv_791.argv_266;
	}
	if (argv_791.argv_756 == true) {
		 argv_754 = argv_791.argv_755;
	}
	if (argv_791.argv_771 == true) {
		argv_769 = argv_791.argv_770;	
	}

	if ((argv_266 == "") || (argv_754 == "") || (argv_769 == "")) {
		argv_172 ("Migale Security suite not installed !");	
		argv_172 ("Could not find the install base path");
		bret = false;
	}
	else {
		char argv_876[argv_706];
		if (argv_313 (argv_266.c_str()) == false) {
			argv_853 (argv_876, argv_706, "+++ ERROR: db path does not exist : %s", argv_266.c_str());
			argv_876[argv_706 - 1] = '\0';
			argv_172 (argv_876);
			argv_164 = true;
			bret = false;
		}
		else if (argv_313 (argv_754.c_str()) == false) {
			argv_853 (argv_876, argv_706, "+++ ERROR: modified files path does not exist : %s", argv_754.c_str());
			argv_876[argv_706 - 1] = '\0';
			argv_172 (argv_876);
			argv_164 = true;
			bret = false;
		}
		else if (argv_313 (argv_769.c_str()) == false) {
			argv_853 (argv_876, argv_706, "+++ ERROR: new files path does not exist : %s", argv_769.c_str());
			argv_876[argv_706 - 1] = '\0';
			argv_172 (argv_876);
			argv_164 = true;
			bret = false;
		}
		else {
			argv_172 ("-----------------------------------------------------------");
			argv_172 ("Working Paths        ");
			argv_172 ("-----------------------------------------------------------");

			argv_853 (argv_876, argv_706, "Database PATH : %s", argv_266.c_str());
			argv_876[argv_706 - 1] = '\0';
			argv_172 (argv_876);

			argv_853 (argv_876, argv_706, "Modified Files -> %s", argv_754.c_str());
			argv_876[argv_706 - 1] = '\0';
			argv_172 (argv_876);

			argv_853 (argv_876, argv_706, "New Files -> %s", argv_769.c_str());
			argv_876[argv_706 - 1] = '\0';
			argv_172 (argv_876);
		}
	}
	return (bret);
}

// -db <path> -new <path> -modified <path> -create -check -auto <timeout_second>
void argv_279 () {
	argv_172 (" ");	
	argv_172 ("Usage: -db <path> -new <path> -modified <path> -create -check -auto <timeout_second> -argv_779");
	argv_172 ("-db <path> : this flag permits to specify a path for the database");
	argv_172 ("             notice that if not specified, a default directory is used");
	argv_172 ("-new <path> : this flag permits to specify a path to argv_826 the new files");
	argv_172 ("              notice that if not specified, a default directory is used");
	argv_172 ("-modified <path>: this flag permits to specify a path to argv_826 the modified files");
	argv_172 ("-create: tells the program to create a new database, this is done once at program startup");
	argv_172 ("-check: tells the program to perform an integrity check, this step is performed after ");
	argv_172 ("        database creation if the flag -create is present, otherwise it is done first.");
	argv_172 ("        Also notice that this step is done only once, unless the flag -auto is specified");
	argv_172 ("		  in which case the check is performed in an infinite loop every TIMEOUT seconds");
	argv_172 ("-auto <timeout_second> : this flag tells the program to perform the check in an infinite loop");
	argv_172 ("                         the program sleeps during <timeout_second> seconds before launching");
	argv_172 ("                         a new check.");
	argv_172 ("                         Notice that the flag -check MUST be present if flag -auto is present");
	argv_172 ("                         The timeout is expressed in seconds.");
	argv_172 ("-argv_779: if present, it permits to consider only system files (sys,exe,com,dll),");
	argv_172 ("           if absent, then all file types are considered.");
	argv_172 ("  ");
}

// -db <path> -new <path> -modified <path> -create -check -auto <timeout_second>
bool argv_206 () {
	bool bret = true;
	argv_885 nb_error = 0;
	if ((argv_791.argv_187 == true) && (argv_791.argv_208 == false)) {
		argv_172 ("+++ ERROR: -auto flag present, but can't find -check flag");		
		bret = false;
	}

	if ((argv_791.argv_267 == true) && (argv_307(argv_791.argv_266.c_str())==false)) {
		char argv_876[argv_706];
		argv_853 (argv_876, argv_706, "+++ ERROR: db path does not exist :%s:", argv_791.argv_266.c_str());
		argv_876[argv_706 - 1] = '\0';
		argv_172 (argv_876);		
		argv_791.argv_267 = false; // permits to use the default directory instead
		bret = false;
	}

	if ((argv_791.argv_756 == true) &&  (argv_307(argv_791.argv_755.c_str())==false)) {
		char argv_876[argv_706];
		argv_853 (argv_876, argv_706, "+++ ERROR: modified files path does not exist :%s:", argv_791.argv_755.c_str());
		argv_876[argv_706 - 1] = '\0';
		argv_172 (argv_876);	
		argv_791.argv_756 = false; // permits to use the default directory instead
		bret = false;
	}

	if ((argv_791.argv_771 == true) &&  (argv_307(argv_791.argv_770.c_str())==false)) {		char argv_876[argv_706];
		argv_853 (argv_876, argv_706, "+++ ERROR: new files path does not exist :%s:", argv_791.argv_770.c_str());
		argv_876[argv_706 - 1] = '\0';
		argv_172 (argv_876);	
		argv_791.argv_771 = false; // permits to use the default directory instead
		bret = false;
	}

	if (nb_error > 0) {
		bret = false;
		char argv_876[256];
		argv_853 (argv_876, 256, "%d errors", nb_error);
		argv_876[255] = '\0';
		argv_172 (argv_876);
		argv_279 ();
	}
	return (bret);
}

void argv_276 () {
	HWND hwnd_std = GetDlgItem (saved_hWnd, argv_393); 
	EnableWindow (hwnd_std, FALSE);
	hwnd_std = GetDlgItem (saved_hWnd, argv_415); 
	EnableWindow (hwnd_std, FALSE);
	hwnd_std = GetDlgItem (saved_hWnd, argv_394); 
	EnableWindow (hwnd_std, FALSE);
	hwnd_std = GetDlgItem (saved_hWnd, argv_490); 
	EnableWindow (hwnd_std, FALSE);
}

// -db <path> -new <path> -modified <path> -create -check -auto <timeout_second> -argv_779
bool argv_792 (argv_885& _nb_param) {
	bool bret = true;
	vector<string> v_param;
	argv_885 nb_error = 0;
	argv_885 nb_param = argv_297 (argv_220.c_str(), v_param);
	_nb_param = nb_param;
	for (argv_885 i=0 ; i<nb_param ; ) {

		if (v_param[i] == "-db") {
			argv_791.argv_269 = true;
			i++;
			if (i >= nb_param) {
				argv_172 ("+++ PARSE ERROR: -db param must be followed by the database path");
				nb_error++;
			}
			else {
				argv_791.argv_267 = true;
				argv_791.argv_266 = v_param[i];
				i++;
			}
		}

		else if (v_param[i] == "-new") {
			argv_791.argv_772 = true;
			i++;
			if (i >= nb_param) {
				argv_172 ("+++ PARSE ERROR: -new param must be followed by the new files path");
				nb_error++;
			}
			else {
				argv_791.argv_771 = true;
				argv_791.argv_770 = v_param[i];
				i++;
			}
		}

		else if (v_param[i] == "-modified") {
			argv_791.argv_757 = true;
			i++;
			if (i >= nb_param) {
				argv_172 ("+++ PARSE ERROR: -modified param must be followed by the modified files path");
				nb_error++;
			}
			else {
				argv_791.argv_756 = true;
				argv_791.argv_755 = v_param[i];
				i++;
			}
		}

		else if (v_param[i] == "-auto") {
			argv_791.argv_187 = true;
			i++;
			if (i >= nb_param) {
				argv_172 ("+++ PARSE ERROR: -auto param must be followed by the timeout");
				nb_error++;
			}
			else {
				argv_791.argv_873 = true;
				argv_791.argv_874 = v_param[i];
				argv_791.argv_875 = atoi (argv_791.argv_874.c_str());
				if (argv_791.argv_875 > (60*60*24)) {
					char argv_876[256];
					argv_853 (argv_876, 256, "+++ PARSE WARNING: timeout greater than 24 hours ! (value:%u)", argv_791.argv_875);
					argv_876[255] = '\0';
					argv_172 (argv_876);
					MessageBox (saved_hWnd, argv_876, "", MB_OK | MB_ICONWARNING);	
				}
				i++;
			}
		}

		else if (v_param[i] == "-create") {
			argv_791.argv_244 = true;
			i++;
		}

		else if (v_param[i] == "-argv_779") {
			argv_791.argv_779 = true;
			i++;
		}

		else if (v_param[i] == "-check") {
			argv_791.argv_208 = true;
			i++;
		}
		else {
			char argv_876[256];
			argv_853 (argv_876, 256, "+++ PARSE ERROR: unknown parameter : %s", v_param[i].c_str());
			argv_876[255] = '\0';
			argv_172 (argv_876);
			nb_error++;
			i++;
		}
	}

	if (nb_error > 0) {
		bret = false;
		char argv_876[256];
		argv_853 (argv_876, 256, "%d errors", nb_error);
		argv_876[255] = '\0';
		argv_172 (argv_876);
		argv_279 ();
	}

	if (bret == true) {
		bret = argv_206 ();
	}
	return (bret);
}

// -db <path> -new <path> -modified <path> -create -check -auto <timeout_second>
void argv_278 () {
	argv_172 ("-----------------------------------------------------------");
	argv_172 ("Configuration chosen by command line        ");
	argv_172 ("-----------------------------------------------------------");

	if (argv_791.argv_779 == true) {
		argv_172 ("-> only system files taken into account (sys,exe,dll)");
	}
	else {
		argv_172 ("-> All file types considered (not only exe,sys,dll)");
	}

	if (argv_791.argv_244 == true) {
		argv_172 ("-> Database will first be created");			
	}
	else {
		argv_172 ("-> program will use existing Database");
	}

	if (argv_791.argv_208 == true) {
		if (argv_791.argv_187 == false) {
			argv_172 ("-> program will check once the files integrity");
		}
		else {
			char argv_876[256];
			argv_853 (argv_876, 256, "-> program will check integrity in an infinite loop, sleep %u seconds between loop", argv_791.argv_875);
			argv_876[255] = '\0';
			argv_172 (argv_876);
		}
	}
	else {
		argv_172 ("-> program will NOT check files integrity automatically");
	}

	if ((argv_791.argv_244 == true) || (argv_791.argv_208 == true) || (argv_791.argv_187 == true)) {
		argv_276 ();
		argv_774 = true;
	}
}

// This function suppose that the 'argv_268' variable has been filled prior to this call
void argv_209 (bool& o_FullDbPresent, bool& o_ManualDbPresent) {
	o_FullDbPresent		= false;
	o_ManualDbPresent	= false;
	std::string FullDbPath		= argv_266 + "\\" + "integ_db.txt";
	std::string ManualDbPath	= argv_266 + "\\" + "integ_manual_db.txt";
	o_FullDbPresent		= argv_307 (FullDbPath.c_str());
	o_ManualDbPresent	= argv_307 (ManualDbPath.c_str());
}


void argv_795 () {
	HWND hwnd_std;
	if (argv_774 == false) {
		hwnd_std = GetDlgItem (saved_hWnd, argv_393); 
		EnableWindow (hwnd_std, FALSE);
	}
	if (argv_856 == false) {
		if (argv_774 == false) {
			if (argv_700 == false) {
				argv_268			= "integ_db.txt";
				argv_317	= argv_266 + "\\" + argv_268;
				hwnd_std = GetDlgItem (saved_hWnd, argv_415);  
				SetWindowText (hwnd_std,"Stop");
				hwnd_std = GetDlgItem (saved_hWnd, argv_416); 
				EnableWindow (hwnd_std, FALSE);
				argv_237 (saved_hWnd);
				argv_863    = false;
				argv_856 = true;
			}
			else {
				argv_701 = argv_210 (saved_hWnd);
				if (argv_701 != "") {
					argv_268			= "integ_manual_db.txt";
					argv_317	= argv_266 + "\\" + argv_268;
					hwnd_std = GetDlgItem (saved_hWnd, argv_416);  
					SetWindowText (hwnd_std,"Stop");
					hwnd_std = GetDlgItem (saved_hWnd, argv_415); 
					EnableWindow (hwnd_std, FALSE);
					argv_237 (saved_hWnd);
					argv_863    = false;
					argv_856 = true;
				}
			}
		}
	}
	else {
		argv_863	= true;
		argv_856 = false;
	}
}

void argv_800 () {
	argv_903.clear ();
	if (argv_791.argv_244 == true) {
		argv_903.push_back (argv_861);	
	}
	else { // DB must not be created => must argv_674 existing DB
		argv_903.push_back (argv_862);
	}

	if (argv_791.argv_208 == true) {
		if (argv_791.argv_187 == false) {
			argv_903.push_back (argv_860);
		}
		else {
			argv_903.push_back (argv_859);
		}
	}
}

void argv_882 () {
	HWND hwnd_std = GetDlgItem (saved_hWnd, argv_513); 
	ShowWindow (hwnd_std, FALSE);
	hwnd_std = GetDlgItem (saved_hWnd, argv_530); 
	ShowWindow (hwnd_std, FALSE);
	hwnd_std = GetDlgItem (saved_hWnd, argv_541); 
	ShowWindow (hwnd_std, FALSE);
}

void argv_881 () {
	HWND hwnd_std = GetDlgItem (saved_hWnd, argv_415); 
	ShowWindow (hwnd_std, FALSE);
	hwnd_std = GetDlgItem (saved_hWnd, argv_393); 
	ShowWindow (hwnd_std, FALSE);
	hwnd_std = GetDlgItem (saved_hWnd, argv_465); 
	ShowWindow (hwnd_std, FALSE);
	hwnd_std = GetDlgItem (saved_hWnd, argv_394); 
	ShowWindow (hwnd_std, FALSE);
	hwnd_std = GetDlgItem (saved_hWnd, argv_490); 
	ShowWindow (hwnd_std, FALSE);
	hwnd_std = GetDlgItem (saved_hWnd, argv_539); 
	ShowWindow (hwnd_std, FALSE);
	hwnd_std = GetDlgItem (saved_hWnd, argv_540); 
	ShowWindow (hwnd_std, FALSE);
	hwnd_std = GetDlgItem (saved_hWnd, argv_542); 
	ShowWindow (hwnd_std, FALSE);
	hwnd_std = GetDlgItem (saved_hWnd, argv_543); 
	ShowWindow (hwnd_std, FALSE);
	hwnd_std = GetDlgItem (saved_hWnd, argv_544); 
	ShowWindow (hwnd_std, FALSE);
	hwnd_std = GetDlgItem (saved_hWnd, argv_545); 
	ShowWindow (hwnd_std, FALSE);
	hwnd_std = GetDlgItem (saved_hWnd, argv_546); 
	ShowWindow (hwnd_std, FALSE);
	hwnd_std = GetDlgItem (saved_hWnd, argv_549); 
	ShowWindow (hwnd_std, FALSE);
	hwnd_std = GetDlgItem (saved_hWnd, argv_416); 
	ShowWindow (hwnd_std, FALSE);
	hwnd_std = GetDlgItem (saved_hWnd, argv_375); 
	ShowWindow (hwnd_std, FALSE);
	
	hwnd_std = GetDlgItem (saved_hWnd, argv_513); 
	ShowWindow (hwnd_std, TRUE);
	hwnd_std = GetDlgItem (saved_hWnd, argv_530); 
	ShowWindow (hwnd_std, TRUE);
	hwnd_std = GetDlgItem (saved_hWnd, argv_541); 
	ShowWindow (hwnd_std, TRUE);
}

bool argv_801 () {
	bool bret = true;
	// if some parameters were given, parse them
	argv_885 nb_param;
	bret = argv_792 (nb_param);
	if (nb_param > 0) {
		// some parse error occured => just argv_863 here
		if (bret == false) {
			argv_172 (" ");
			argv_172 ("Some errors detected, please check parameters passed to command line");		
			argv_276 ();
		}
		else { // parse succeeded
			argv_172 ("parsed command line succesfully");
			argv_172 ("program will perform the following steps : ");
			argv_278 ();
			argv_800 ();
			Sleep (1000);
		}
	}
	else { // no parameters passed to command line
		argv_172 ("No parameters passed to command line");	
	}

	// we proceed only if command line parsing was succesful
	if (bret == true) {
		if (argv_302 (saved_hWnd) == false) {
			MessageBox (saved_hWnd, "Fatal configuration error occured ! (see details)", "", MB_OK | MB_ICONERROR);	
			SendDlgItemMessage (saved_hWnd, argv_410, WM_SETTEXT, 0, (LPARAM) "Program can not run (check parameters or ensure that Migale Suite is installed)");	
			argv_276 ();
		}
		else { // necessary folders were succesfully retrieved
			bool FullDbPresent, ManualDbPresent;
			argv_209 (FullDbPresent, ManualDbPresent);
			if ((false == FullDbPresent) && (false == ManualDbPresent)) {
				argv_684.argv_682 ("no database file found !");
				argv_317			= argv_266 + "\\" + argv_268;
				argv_270	= "Full DB";
				argv_700				= false;
			}
			else if ((true == FullDbPresent) && (false == ManualDbPresent)) {
				argv_684.argv_682 ("Found 'integ_db.txt'");
				argv_317			= argv_266 + "\\" + "integ_db.txt";
				argv_700				= false;
				argv_270	= "Full DB";
			}
			else if ((false == FullDbPresent) && (true == ManualDbPresent)) {
				argv_684.argv_682 ("Found 'integ_manual_db.txt'");
				argv_317			= argv_266 + "\\" + "integ_manual_db.txt";
				argv_270	= "Manual DB";
				argv_700				= true;
			}
			else if ((true == FullDbPresent) && (true == ManualDbPresent)) {
				argv_684.argv_682 ("*** Warning: found 'integ_db.txt' and 'integ_manual_db.txt'");
				if (MessageBox (saved_hWnd, "<All HDD DB> and <Manual DB> found, wana argv_674 <manual DB> instead of <Full DB> ?", "Question", MB_YESNO | MB_ICONWARNING)==IDYES) {
					argv_684.argv_682 ("decided to argv_674 'integ_manual_db.txt'");
					argv_317			= argv_266 + "\\" + "integ_manual_db.txt";
					argv_700				= true;
					argv_270	= "Manual DB";
				}
				else {
					argv_684.argv_682 ("decided to argv_674 'integ_db.txt'");
					argv_317			= argv_266 + "\\" + "integ_db.txt";
					argv_700				= false;
					argv_270	= "Full DB";
				}
			}
			argv_902 ();

			if (argv_903.size() == 0) {
				argv_239 (saved_hWnd); 
			}
			else {
				argv_276 (); // avoid interactions with user 
				argv_260 = 0;
				argv_172 ("--------------------------------------------------------");
				argv_172 ("Lauching automatic sequence        ");
				argv_172 ("--------------------------------------------------------");
				SetTimer (saved_hWnd, argv_635, 100, (TIMERPROC) NULL);
			}
		}
	}
	return (bret);
}



LRESULT CALLBACK argv_192 (HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message)
	{
		case WM_INITDIALOG:
			argv_199 (hDlg);
			argv_172 (hDlg, argv_465, "===============================================");
			argv_172 (hDlg, argv_465, "Migale Security Suite - File Integrity Monitor");
			argv_172 (hDlg, argv_465, "V 3.0  (2008/05/22)");
			argv_172 (hDlg, argv_465, "Franck Legardien (tybins99@hotmail.com)");
			argv_172 (hDlg, argv_465, "===============================================");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "1. Introduction");
			argv_172 (hDlg, argv_465, "-------------------------------------------");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "This tool permits to do the following things :");
			argv_172 (hDlg, argv_465, "- create a snapshot of the argv_857 of all hard drives of a given computer.");
			argv_172 (hDlg, argv_465, "- compare the argv_857 of the hard drives with the snapshot so that ");
			argv_172 (hDlg, argv_465, "differences can be noticed (if any) and analyzed.");
			argv_172 (hDlg, argv_465, "It is particularly useful to create a honeypot system.");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "2. Detailed description");
			argv_172 (hDlg, argv_465, "----------------------------------------------------");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "This tool permits to monitor the following file types :");
			argv_172 (hDlg, argv_465, ".exe, .dll, .sys, .com");
			argv_172 (hDlg, argv_465, "But it can also monitor any kind of file if the");
			argv_172 (hDlg, argv_465, "'Only system files (sys, dll, exe)' checkbox is unchecked.");
			argv_172 (hDlg, argv_465, "Let's call this set of file types the relevant files.");
			argv_172 (hDlg, argv_465, "The tool is able to look for the relevant files on all hard drives.");
			argv_172 (hDlg, argv_465, "The tool first will have to create a snapshot of the hard drives and");
			argv_172 (hDlg, argv_465, "store it into a database (stored in a file).");
			argv_172 (hDlg, argv_465, "Then using this database, it will be able to notice ");
			argv_172 (hDlg, argv_465, "the following differences :");
			argv_172 (hDlg, argv_465, "- a relevant file was deleted.");
			argv_172 (hDlg, argv_465, "- a new relevant file was created");
			argv_172 (hDlg, argv_465, "- an existing relevant file was modified.");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "Notice that the tool supposes it was installed with the Migale Security");
			argv_172 (hDlg, argv_465, "Suite, so that it will look for it's database path and other necessary ");
			argv_172 (hDlg, argv_465, "paths using the registry.");
			argv_172 (hDlg, argv_465, "If you have not installed the Migale security suite and you want to use");
			argv_172 (hDlg, argv_465, "the tool, you will have to specify the following paths as command line");
			argv_172 (hDlg, argv_465, "parameters :");
			argv_172 (hDlg, argv_465, "- the database path (where to store the database)");
			argv_172 (hDlg, argv_465, "- the NEW FILES path : where to copy new files");
			argv_172 (hDlg, argv_465, "- the MODIFIED FILES path : where to copy files that have changed.");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "2.1. Operating modes");
			argv_172 (hDlg, argv_465, "---------------------------------------------");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "There exists 3 different operating modes :");
			argv_172 (hDlg, argv_465, "- manual mode");
			argv_172 (hDlg, argv_465, "- automatic mode");
			argv_172 (hDlg, argv_465, "- snapshot mode");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "In \"manual mode\", the user interacts with the tool using buttons and the ");
			argv_172 (hDlg, argv_465, "tool answers by displaying status and warning/errors.");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "In \"Automatic mode\", the user gives some parameters to the tool as a");
			argv_172 (hDlg, argv_465, "command line sequence of parameters so that the tool can perform any");
			argv_172 (hDlg, argv_465, "sequence without human intervention. This is particularly useful if");
			argv_172 (hDlg, argv_465, "you want to launch the application automatically each time you boot.");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "In \"Snapshot mode\", the user choose a folder to get monitored");
			argv_172 (hDlg, argv_465, "and after snapshot creation he can check it's integrity.");
			argv_172 (hDlg, argv_465, "The main differences being that the DB created in this mode");
			argv_172 (hDlg, argv_465, "is not saved and that you can monitor all files of the chosen");
			argv_172 (hDlg, argv_465, "folder (not only the relevant files).");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "2.1.1 Manual mode");
			argv_172 (hDlg, argv_465, "---------------------------------------------");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "In manual mode there are 3 relevant controls to consider :");
			argv_172 (hDlg, argv_465, "- the \"Create DB\" button");
			argv_172 (hDlg, argv_465, "- the \"Check integrity\" button");
			argv_172 (hDlg, argv_465, "- the \"Loop\" checkbox");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "- The \"Create All HDD Database\" button permits you to create a snapshot of the argv_857 ");
			argv_172 (hDlg, argv_465, "of all hard drives of your computer. Notice that it may takes some time");
			argv_172 (hDlg, argv_465, "  if you have a big hard drive.");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "- The \"Check Integrity\" button permits to compare the argv_857 of the hard");
			argv_172 (hDlg, argv_465, "drives with their respective argv_857 when the snapshot was created.");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "- The \"Loop\" checkbox permits to decide at any time to perform the ");
			argv_172 (hDlg, argv_465, "Integrity check in a loop, so that the tool becomes a kind of real");
			argv_172 (hDlg, argv_465, "  time checker. That is to say it will restart checking after one");
			argv_172 (hDlg, argv_465, "  check was completed. Notice that you may uncheck this checkbox at");
			argv_172 (hDlg, argv_465, "  any time to argv_863 the cycle, of course the check will complete, and then");
			argv_172 (hDlg, argv_465, "  will argv_863 instead of looping again if checkbox was unchecked meanwhile.");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "Notice that creating the database and checking the integrity can not");
			argv_172 (hDlg, argv_465, "be performed concurently, it is logical because in order to check the");
			argv_172 (hDlg, argv_465, "integrity you need a full database.");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "Notice that you can decide to argv_863 the database creation, or the files");
			argv_172 (hDlg, argv_465, "integrity checking at any time, However if you argv_863 the database creation");
			argv_172 (hDlg, argv_465, "before it finishes normally, you had better not launch a check, because");
			argv_172 (hDlg, argv_465, "as the database is not complete, the tool will believe that many new files"); 
			argv_172 (hDlg, argv_465, "have appeared on your hard drive and will copy them all to the NEW FILE");
			argv_172 (hDlg, argv_465, "folder, so the advice is : if you don't have any choice but stopping the");
			argv_172 (hDlg, argv_465, "tool while database creation is in progress, don't forget to restart it ");
			argv_172 (hDlg, argv_465, "later and let it finish");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "All the relevant files that have been created after the database creation");
			argv_172 (hDlg, argv_465, "are copied to the folder that you either specified as a parameter at");
			argv_172 (hDlg, argv_465, "startup (see automatic mode), or that were found using the registry");
			argv_172 (hDlg, argv_465, "(the folders are displayed at startup).");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "All relevant files that have been modified after the database creation");
			argv_172 (hDlg, argv_465, "are copied to the folder that you either specified as a parameter at");
			argv_172 (hDlg, argv_465, "startup (see automatic mode), or that were found using the registry");
			argv_172 (hDlg, argv_465, "(the folders are displayed at startup).");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "2.1.2 Automatic mode");
			argv_172 (hDlg, argv_465, "--------------------------------------------------");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "The automatic mode permits to avoid having to use the GUI to perform");
			argv_172 (hDlg, argv_465, "an operation.");
			argv_172 (hDlg, argv_465, "So you have to pass parameters to the tool when it starts (as under Unix)");
			argv_172 (hDlg, argv_465, "The usage is as follows :");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "Usage: -db <path> -new <path> -modified <path> -create -check -auto <timeout_second>...");
			argv_172 (hDlg, argv_465, "... -argv_779");
			argv_172 (hDlg, argv_465, "-db <path> : this flag permits to specify a path for the database");
			argv_172 (hDlg, argv_465, "notice that if not specified, a default directory is used");
			argv_172 (hDlg, argv_465, "-new <path> : this flag permits to specify a path to argv_826 the new files");
			argv_172 (hDlg, argv_465, "              notice that if not specified, a default directory is used");
			argv_172 (hDlg, argv_465, "-modified <path>: this flag permits to specify a path to argv_826 the modified files");
			argv_172 (hDlg, argv_465, "-create: tells the program to create a new database, this is done once at program startup");
			argv_172 (hDlg, argv_465, "-check: tells the program to perform an integrity check, this step is performed after ");
			argv_172 (hDlg, argv_465, "database creation if the flag -create is present, otherwise it is done first.");
			argv_172 (hDlg, argv_465, "Also notice that this step is done only once, unless the flag -auto is specified");
			argv_172 (hDlg, argv_465, "		  in which case the check is performed in an infinite loop every TIMEOUT seconds");
			argv_172 (hDlg, argv_465, "-auto <timeout_second> : this flag tells the program to perform the check in an infinite loop");
			argv_172 (hDlg, argv_465, "the program sleeps during <timeout_second> seconds before launching");
			argv_172 (hDlg, argv_465, "                         a new check.");
			argv_172 (hDlg, argv_465, "                         Notice that the flag -check MUST be present if flag -auto is present");
			argv_172 (hDlg, argv_465, "                         The timeout is expressed in seconds.");
			argv_172 (hDlg, argv_465, "-argv_779: if present, it permits to consider only system files (sys,exe,com,dll),");
			argv_172 (hDlg, argv_465,"            if absent, then all file types are considered.");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "2.1.3. Snapshot Mode");
			argv_172 (hDlg, argv_465, "--------------------------------------------------");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "This mode permits to create a recursive snapshot of a ");
			argv_172 (hDlg, argv_465, "given folder. This snapshot will consider all files from");
			argv_172 (hDlg, argv_465, "this folder (not only the EXE, DLL, SYS, COM files)");
			argv_172 (hDlg, argv_465, "After the snapshot is created, it is possible to perform");
			argv_172 (hDlg, argv_465, "an integrity check, in a loop or not.");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "Notice the following points :");
			argv_172 (hDlg, argv_465, "- this mode can not be automated using command line");
  			argv_172 (hDlg, argv_465, "arguments.");
			argv_172 (hDlg, argv_465, "- The database generated by the snapshot is different than");
  			argv_172 (hDlg, argv_465, "the normal database, so it will not overwrite the normal");
  			argv_172 (hDlg, argv_465, "database.");
			argv_172 (hDlg, argv_465, "- The snapshot database can not be reloaded, so it is lost");
  			argv_172 (hDlg, argv_465, "when you leave the program.");
 			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "3. FAQ");
			argv_172 (hDlg, argv_465, "---------------------------------------");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "--> 3.1 What is the method used to detect changes in a file ?");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "The algorithm used is a 32 bytes CRC generated by a MD5 algorithm so that");
			argv_172 (hDlg, argv_465, "even the slightest modification of a file can be detected.");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "--> 3.2 Why does it sometimes take time to close the tool ?");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "The tool is multithreaded, and to prevent from having database ");
			argv_172 (hDlg, argv_465, "inconsistency the main thread just suggest to other threads to argv_863");
			argv_172 (hDlg, argv_465, "as soon as possible, and then it is up to these other threads to argv_863");
			argv_172 (hDlg, argv_465, "and as soon as they have stopped, they inform the main thread that then");
			argv_172 (hDlg, argv_465, "decided to close the application.");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "--> 3.3 why can't I have the -auto flag without the -check flag ?");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "The -auto flag is a modifier of the behaviour of the -check flag, so ");
			argv_172 (hDlg, argv_465, "you just can't modify a flag's behaviour when this flag is absent.");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "--> 3.4 Can I pass command line parameters in any order ?");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "Yes, the order does not matter, you can choose the order you want.");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "--> 3.5 Why are there several steps when checking integrity ?");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "The first step is to look for files that were deleted from hard drives.");
			argv_172 (hDlg, argv_465, "The second steps is to look for files that are new, or were modified.");
			argv_172 (hDlg, argv_465, "Furthermore the tool takes into account the number of hard drives you ");
			argv_172 (hDlg, argv_465, "have to argv_277 the total number of steps remaining.");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "--> 3.6 I have specified a timeout, but the tool displays a warning, why ?");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "The timeout is expressed in seconds, if your timeout has a bad value ");
			argv_172 (hDlg, argv_465, "(a letter instead of a number for example) or if it is greater than the");
			argv_172 (hDlg, argv_465, "number of seconds in 24 hours, you will see a warning telling you that ");
			argv_172 (hDlg, argv_465, "you might have made a mistake when typing the timeout.");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "--> 3.7 Why do we need to monitor new files created ?");
			argv_172 (hDlg, argv_465, "");
			argv_172 (hDlg, argv_465, "After snapshot creation, you might use your computer for a given amount");
			argv_172 (hDlg, argv_465, "of time, and during this time, your computer might get infected by a kind");
			argv_172 (hDlg, argv_465, "of virus called \"downloader\", this kind of virus has the ability to ");
			argv_172 (hDlg, argv_465, "download other viruses to your computer without your permission and you");
			argv_172 (hDlg, argv_465, "just won't be aware that this virus has downloaded one or more new virus");
			argv_172 (hDlg, argv_465, "into your computer. That's why we must monitor new files as well as  files");
			argv_172 (hDlg, argv_465, "that were modified after hard drive snapshot was taken.");
			argv_172 (hDlg, argv_465, "");
			return TRUE;

		case WM_COMMAND:
			switch(LOWORD(wParam)) {
				case IDOK:
				case IDCANCEL:
					hwndGoto_help = NULL;
					EndDialog(hDlg, LOWORD(wParam));
					return TRUE;
				break;
			};
	}
	return FALSE;
}

void argv_205 () {
	CheckDlgButton (saved_hWnd, argv_490, BST_CHECKED);
}

void argv_890 () {
	CheckDlgButton (saved_hWnd, argv_490, BST_UNCHECKED);
}


LRESULT CALLBACK argv_165(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	bool bret = true;

	switch (message)
	{
		case WM_INITDIALOG:
			saved_hWnd = hDlg;
			CheckDlgButton (saved_hWnd, argv_490, BST_CHECKED);
			argv_882 ();
			argv_684.argv_788 ("C:\\log.txt");
			argv_199 (hDlg);
			argv_801 ();
			return TRUE;

		case WM_TIMER: // this message is sent automatically when timer expires
			if (wParam == argv_634) { // the identifier of the timer that has fired
				KillTimer (hDlg, argv_634);
				if (argv_282 == true) {
					PostMessage (hDlg, WM_MOUSEHOVER, 0, 0);
				}
			}
			else if (wParam == argv_635) {
				if (argv_260 < argv_903.size()) {
					switch (argv_903[argv_260]) {
						case argv_862:
							if (argv_856 == false) {
								argv_809 = false;
								KillTimer (hDlg, argv_635);
								argv_264 = true;
								if ((argv_260+1) < argv_903.size()) {
									argv_172 ("----> Loading DB before starting sequence...");
								}
								else {
									argv_172 ("----> Loading DB");
								}
								argv_239 (saved_hWnd);
								SetTimer (saved_hWnd, argv_635, argv_791.argv_875*1000, (TIMERPROC) NULL);
								argv_260++;
							}
							break;

						case argv_861:
							if (argv_856 == false) {
								argv_172 ("----> step: performing DB creation");
								KillTimer (hDlg, argv_635);
								argv_795 ();
								SetTimer (saved_hWnd, argv_635, argv_791.argv_875*1000, (TIMERPROC) NULL);
								argv_260++;
								if (argv_260 < argv_903.size()) {
									argv_172 ("...sleeping before starting new step");
								}
								else {
									argv_172 ("Automatic sequence Completed");
								}
							}
							break;

						case argv_860:
							if (argv_856 == false) {
								if (argv_265 == false) {
									KillTimer (hDlg, argv_635);
									argv_172 ("+++ DB could not be argv_675 !");
								}
								else {
									argv_172 ("----> step: check integrity once");
									KillTimer (hDlg, argv_635);
									argv_796 (hDlg);
									SetTimer (saved_hWnd, argv_635, argv_791.argv_875*1000, (TIMERPROC) NULL);
									argv_260++;
									if (argv_260 < argv_903.size()) {
										argv_172 ("...sleeping before starting new step");
									}
									else {
										argv_172 ("Automatic sequence Completed");
									}
								}
							}
							break;

						case argv_859:
							if (argv_856 == false) {
								if (argv_265 == false) {
									KillTimer (hDlg, argv_635);
									argv_172 ("+++ DB could not be argv_675 !");
								}
								else {
									argv_172 ("----> step: check integrity repeatedly");
									KillTimer (hDlg, argv_635);
									argv_796 (hDlg);
									argv_172 ("...sleeping before starting new step");
									SetTimer (saved_hWnd, argv_635, argv_791.argv_875*1000, (TIMERPROC) NULL);
								}
							}
							break;

						default:
							MessageBox (saved_hWnd, "Internal error 1 (unknown step type)", "", MB_OK | MB_ICONERROR);	
							KillTimer (hDlg, argv_635);
					}
				}
			}
			else if (wParam == argv_636) { // application shutdown
				if (argv_809 == true) {
					KillTimer (hDlg, argv_636);
					EndDialog(hDlg, LOWORD(wParam));
				}
				else {
					shutdown_countdown--;
					argv_848++;
					if (shutdown_countdown <= 0) {
						shutdown_countdown = 50;
						argv_848	   = 0;	
						SendDlgItemMessage(hDlg, argv_513, PBM_SETRANGE32, 0, shutdown_countdown*64); 
					}
					else {
						SendDlgItemMessage(hDlg, argv_513, PBM_SETPOS, argv_848*64, 0);
					}
				}
			}
			break;

		case WM_MOUSEHOVER:
			argv_796 (hDlg);
			break;

		case WM_COMMAND:
			switch(LOWORD(wParam)) {
				case IDOK:
				case IDCANCEL:
					argv_863 = true;
					SendDlgItemMessage (saved_hWnd, argv_410, WM_SETTEXT, 0, (LPARAM) "Terminating sequence before shutdown...");	
					argv_881 ();
					argv_172 ("Shutdown all running processes...");
					SendDlgItemMessage (hDlg, argv_513, PBM_SETRANGE32, 0, shutdown_countdown*64); 
					SetTimer (saved_hWnd, argv_636, 20, (TIMERPROC) NULL);
					return TRUE;
				break;

				case argv_393:
					argv_796 (hDlg);
					break;

				case argv_415:
					argv_700		= false;
					argv_795 ();
					break;

				case argv_416:
					argv_700		= true;
					argv_795 ();
					break;

				case argv_394:
					if (IsDlgButtonChecked (hDlg, argv_394) == BST_CHECKED) {
						argv_282 = true;
					}
					else {
						KillTimer (hDlg, argv_634);
						argv_282 = false;
					}
					break;

				case argv_490:
					if (IsDlgButtonChecked (hDlg, argv_490) == BST_CHECKED) {
						argv_780 = true;
					}
					else {
						argv_780 = false;
					}
					break;
				
				case argv_375:
					if (!IsWindow(hwndGoto_help)) { 
						hwndGoto_help = CreateDialog (argv_353, 
												 MAKEINTRESOURCE(argv_616), 
												 hDlg, (DLGPROC) argv_192); 
						ShowWindow (hwndGoto_help, SW_SHOW);
					}
					break;
			}
	}
	return FALSE;
}