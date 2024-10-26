#ifndef Cache_Clean_hpp
#define Cache_Clean_hpp

#include <iostream>
using namespace std;

class Cache_Clean
{
	public:
		Cache_Clean();
	protected:
};

Cache_Clean::Cache_Clean()
{
    system("rd /s /q %temp% > NUL 2>&1");
    cout<< "Temp Folder Cleared.\n";

    system("del /f /s /q %windir%\\Temp > NUL 2>&1");
    cout<< "Windows Temp Folder Cleared.\n";

    system("del /f /s /q C:\\WINDOWS\\Prefetch > NUL 2>&1");
    cout<< "Prefetch Files Cleared.\n";

    system("rd /s /q C:\\$Recycle.Bin> NUL 2>&1");
    cout<< "Recycle Bin Cleared.\n";

    system("RunDll32.exe InetCpl.cpl,ClearMyTracksByProcess 8 > NUL 2>&1");
    cout<< "Internet Explorer Caches Cleared.\n";

    system("rd /s /q \"C:\\Users\\%USERNAME%\\AppData\\Local\\Microsoft\\Windows\\Explorer\" > NUL 2>&1");
    cout<< "Explorer Data Cleared.\n";
    
    system("net stop wuauserv > NUL 2>&1");
    cout<< "Windows Update service Stopped.\n";
    
    system("rd /s /q C:\\Windows\\SoftwareDistribution > NUL 2>&1");
    cout<< "SoftwareDistribution folder Cleared.\n";

    system("net start wuauserv > NUL 2>&1");
    cout<< "Windows Update service Started.\n";
    
    system("del /f /s /q C:\\Users\\%USERNAME%\\AppData\\Local\\Roblox\\logs > NUL 2>&1");
    cout<< "Roblox Logs Cleared.\n";
    
    system("del /f /s /q C:\\Users\\%USERNAME%\\AppData\\Local\\Roblox\\Versions > NUL 2>&1");
    cout<< "Roblox Version Logs Cleared.\n";

    system("del /f /s /q C:\\Users\\%USERNAME%\\AppData\\Local\\Riot Games > NUL 2>&1");
    cout<< "Riot Games Cache Logs Cleared.\n";

    system("del /f /s /q C:\\Users\\%USERNAME%\\AppData\\Local\\CapCut\\User Data\\Cache > NUL 2>&1");
    cout<< "Capcut Cache Logs Cleared.\n";

    


}

#endif