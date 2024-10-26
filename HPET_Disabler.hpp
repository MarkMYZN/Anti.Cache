#ifndef HPET_DISABLER_H
#define HPET_DISABLER_H

#include <iostream>
using namespace std;

class HPET_Disabler
{
	public:
		HPET_Disabler();
	protected:
};

HPET_Disabler::HPET_Disabler()
{
    //Removes User_Platform_Clock
    system("bcdedit /deletevalue useplatformclock > NUL 2>&1");
    cout<<"\"User_Platform_Clock\" Removed." << endl ;

    //Enabling Disable_Dynamic_Tick
    system("bcdedit /set disabledynamictick yes > NUL 2>&1");
    cout<<"\"Disable_Dynamic_Tick\" Set to Enabled." << endl ;

    //Platform_Tick Enabled
    system("bcdedit /set useplatformtick yes > NUL 2>&1");
    cout<<"\"Platform_Tick\" Set to Enabled." << endl ;

    //Hypervisor_Launch_Type Off
    system("bcdedit /set hypervisorlaunchtype off > NUL 2>&1");
    cout<<"\"Hypervisor_Launch_Type\" Set to Off." << endl ;
}


#endif