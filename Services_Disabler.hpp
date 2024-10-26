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
    system("sc config DiagTrack start= disabled > NUL 2>&1");
    cout<< "\nDiagTrack Disabled.\n";

    system("sc config dmwappushservice start= disabled > NUL 2>&1");
    cout<< "dmwappushservice Disabled.\n";

    system("sc config DialogBlockingService start= disabled > NUL 2>&1");
    cout<< "DialogBlockingService Disabled.\n";

    system("sc config diagnosticshub.standardcollector.service start= disabled > NUL 2>&1");
    cout<< "diagnosticshub.standardcollector.service Disabled.\n";

    system("sc config AppVClient start= disabled > NUL 2>&1");
    cout<< "AppVClient Disabled.\n";

    system("sc config MsKeyboardFilter start= disabled > NUL 2>&1");
    cout<< "MsKeyboardFilter Disabled.\n";

    system("sc config NetTcpPortSharing start= disabled > NUL 2>&1");
    cout<< "NetTcpPortSharing Disabled.\n";

    system("sc config ssh-agent start= disabled > NUL 2>&1");
    cout<< "ssh-agent Disabled.\n";

    system("sc config QWAVE start= disabled > NUL 2>&1");
    cout<< "QWAVE Disabled.\n";

    system("sc config RtkAudioUniversalService start= disabled > NUL 2>&1");
    cout<< "RtkAudioUniversalService Disabled.\n";

    system("sc config RemoteRegistry start= disabled > NUL 2>&1");
    cout<< "RemoteRegistry Disabled.\n";

    system("sc config RetailDemo start= disabled > NUL 2>&1");
    cout<< "RetailDemo Disabled.\n";

    system("sc config RemoteAccess start= disabled > NUL 2>&1");
    cout<< "RemoteAccess Disabled.\n";

    system("sc config UevAgentService start= disabled > NUL 2>&1");
    cout<< "UevAgentService Disabled.\n";

    system("sc config WSearch start= disabled > NUL 2>&1");
    cout<< "WSearch Disabled.\n";

    system("sc config LanmanWorkstation start= disabled > NUL 2>&1");
    cout<< "LanmanWorkstation Disabled.\n";

    system("sc config XboxGipSvc start= disabled > NUL 2>&1");
    cout<< "XboxGipSvc Disabled.\n";

    system("sc config XblAuthManager start= disabled > NUL 2>&1");
    cout<< "XblAuthManager Disabled.\n";

    system("sc config XblGameSave start= disabled > NUL 2>&1");
    cout<< "XblGameSave Disabled.\n";

    system("sc config XboxNetApiSvc start= disabled > NUL 2>&1");
    cout<< "XboxNetApiSvc Disabled.\n";

    system("sc config ZoomCptService start= disabled > NUL 2>&1");
    cout<< "ZoomCptService Disabled.\n";

    system("sc config GoogleChromeElevationService start= disabled > NUL 2>&1");
    cout<< "GoogleChromeElevationService Disabled.\n";
}

#endif





