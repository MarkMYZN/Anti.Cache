#ifndef APP_JUNK_CLEANER_H
#define APP_JUNK_CLEANER_H

#include <iostream>
using namespace std;

class App_Junk_Cleaner
{
	public:
		App_Junk_Cleaner();
	protected:
};

App_Junk_Cleaner::App_Junk_Cleaner()
{
	const char* AppJunkCleaner[] = {
        "del C:\\Windows\\Temp /f /q"
        ,"del C:\\Users\\Miyazono\\AppData\\Local\\D3DSCache /f /q"
        ,"del C:\\Users\\Miyazono\\AppData\\Local\\Microsoft\\Windows\\Explorer /f /q"
    };
    int AppJunkLength = sizeof(AppJunkCleaner) / sizeof(AppJunkCleaner[0]);

    for (int i = 0; i < AppJunkLength; ++i) {
        system(AppJunkCleaner[i]);
        cout << "\nJunk files within %s has been Cleared.\n" << AppJunkCleaner[i];
    };
}

#endif