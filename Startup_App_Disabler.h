#ifndef STARTUP_APP_DISABLER_H
#define STARTUP_APP_DISABLER_H

#include <iostream>
using namespace std;

class Startup_App_Disabler
{
	public:
		Startup_App_Disabler();
	protected:
};

Startup_App_Disabler::Startup_App_Disabler()
{
	const char* StartupDisabler[] = {
        "reg add HKLM\\SOFTWARE\\Microsoft\\Active Setup\\Installed Components /v Google Chrome /t REG_SZ /d \"\" /f"
        ,"reg add HKLM\\SOFTWARE\\Microsoft\\Active Setup\\Installed Components /v Microsoft Edge /t REG_SZ /d \"\" /f"
        ,"reg add HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /v Steam /t REG_SZ /d \"\" /f"
        ,"reg add HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /v MicrosoftEdgeAutoLaunch_F0F41C1CE79B46820675944F246DE300 /t REG_SZ /d \"\" /f"
        ,"reg add HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /v Discord /t REG_SZ /d \"\" /f"
    };
    int StartupLength = sizeof(StartupDisabler) / sizeof(StartupDisabler[0]);
    
    for (int i = 0; i < StartupLength; ++i) {
        system(StartupDisabler[i]);
        cout << "\nAll startups within %s has been Cleared.\n" << StartupDisabler[i];
    }
}

#endif