/*
	RunExe
	 © ultrashot 2011-2013
*/
#include "stdafx.h"
#include "..\..\common\Process.hpp"

int _tmain(int argc, _TCHAR* argv[])
{
    if (argc > 1)
    {
	    if (wcslen(argv[1]) && GetFileAttributes(argv[1]) != INVALID_FILE_ATTRIBUTES)
	    {
		    wchar_t fileName[MAX_PATH];
		    wcscpy_s(fileName, MAX_PATH, argv[1]);
            if (wchar_t *c = wcsrchr(fileName, L'.'))
                *c = L'\0';
		    wcscat_s(fileName, MAX_PATH, L".exe");

		    if (GetFileAttributes(fileName) != INVALID_FILE_ATTRIBUTES)
		    {
			    SetFileAttributes(fileName, FILE_ATTRIBUTE_NORMAL);
			    DeleteFileW(fileName);
		    }
		    if (MoveFile(argv[1], fileName) == TRUE)
		    {
			    if (GetFileAttributes(fileName) != INVALID_FILE_ATTRIBUTES)
			    {
				    Diagnostics::Process::Start(fileName, NULL, NULL, true);
			    }
		    }
	    }
    }
	return 0;
}

