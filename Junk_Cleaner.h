#ifndef JUNK_CLEANER_H
#define JUNK_CLEANER_H

#include <iostream>
using namespace std;

class Junk_Cleaner
{
	public:
		Junk_Cleaner();
	protected:
};

Junk_Cleaner::Junk_Cleaner()
{
	const char* SysJunkCleaner[] = {
        "del %%temp%% /f /s /q"
        ,"del %%Windir%%\\Temp /f /s /q"
        ,"del C:\\WINDOWS\\Prefetch  /f /s /q"
        ,"RD /S /Q C:\\$Recycle.Bin"
        ,"RunDll32.exe InetCpl.cpl,ClearMyTracksByProcess 8"
        ,"RD /S /Q C:\\Users\\YourUsername\\AppData\\Local\\Microsoft\\Windows\\Explorer"
        ,"net stop wuauserv"
        ,"RD /S /Q C:\\Windows\\SoftwareDistribution"
        ,"net start wuauserv"
    };
    int SysJunkLength = sizeof(SysJunkCleaner) / sizeof(SysJunkCleaner[0]);

    for (int i = 0; i < SysJunkLength; ++i) {
        system(SysJunkCleaner[i]);
        cout << "\nJunk files within %s has been Cleared.\n" << SysJunkCleaner[i];
    };
}

#endif