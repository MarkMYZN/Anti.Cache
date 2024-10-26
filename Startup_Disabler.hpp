#ifndef Startup_Disabler_H
#define Startup_Disabler_H

#include <iostream>
using namespace std;

class Startup_Disabler
{
	public:
		Startup_Disabler();
	protected:
};

Startup_Disabler::Startup_Disabler()
{
	system("reg delete \"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Run\" /v GoogleChrome /f > NUL 2>&1");
    cout<<"\n\"GoogleChrome\" Startup destroyed.\n";

	system("reg delete \"HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Run\" /v MicrosoftEdgeAutoLaunch_DD0E59116D9ED8726152BF61FB289B8B /f > NUL 2>&1");
    cout<<"\n\"MicrosoftEdgeAutoLaunch_DD0E59116D9ED8726152BF61FB289B8B\" Startup destroyed.\n";

    system("reg delete HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /v MicrosoftEdgeAutoLaunch_F0F41C1CE79B46820675944F246DE300 /f > NUL 2>&1");
    cout<<"\n\"MicrosoftEdgeAutoLaunch_F0F41C1CE79B46820675944F246DE300\" Startup destroyed.\n";

    system("reg delete HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /v OneDrive /f > NUL 2>&1");
    cout<<"\n\"OneDrive\" Startup destroyed.\n";
    
    system("reg delete HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /v Discord /f > NUL 2>&1");
    cout<<"\n\"Discord\" Startup destroyed.\n";
    
    system("reg delete HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /v Spotify /f > NUL 2>&1");
    cout<<"\n\"Spotify\" Startup destroyed.\n";

    system("reg delete HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /v Steam /f > NUL 2>&1");
    cout<<"\n\"Steam Startup destroyed.\n";
}

#endif



