#ifndef SERVICES_DISABLER_H
#define SERVICES_DISABLER_H

#include <iostream>
using namespace std;

class Services_Disabler
{
	public:
		Services_Disabler();
	protected:
};


Services_Disabler::Services_Disabler()
{
	const char* ServicesDisabler[] = {
        "DiagTrack"
        ,"dmwappushservice"
        ,"DialogBlockingService"
        ,"diagnosticshub.standardcollector.service"
        ,"AppVClient"
        ,"MsKeyboardFilter"
        ,"NetTcpPortSharing"
        ,"ssh-agent"
        ,"QWAVE"
        ,"RtkAudioUniversalService"
        ,"RemoteRegistry"
        ,"RetailDemo"
        ,"RemoteAccess"
        ,"UevAgentService"
        ,"WSearch"
        ,"LanmanWorkstation"
        ,"XboxGipSvc"
        ,"XblAuthManager"
        ,"XblGameSave"
        ,"XboxNetApiSvc"
        ,"ZoomCptService"
        ,"GoogleChromeElevationService"
    };
    int ServicesLength = sizeof(ServicesDisabler) / sizeof(ServicesDisabler[0]);

    for (int i = 0; i < ServicesLength; ++i) {
        char command[256];
        char command2[256];
        sprintf(command, "sc config \"%s\" start= disabled", ServicesDisabler[i]);
        system(command);
        sprintf(command, "sc stop \"%s\"", ServicesDisabler[i]);
        system(command2);
        cout << " has been disabled.\n" << ServicesDisabler[i];
    };
}

#endif