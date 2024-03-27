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
	const char* HPET_Disabler[] = {
        "bcdedit /deletevalue useplatformclock"
        ,"bcdedit /set disabledynamictick yes"
        ,"bcdedit /set useplatformtick yes"
        ,"bcdedit /set hypervisorlaunchtype off"
    };
    int HPET_Length = sizeof(HPET_Disabler) / sizeof(HPET_Disabler[0]);

    for (int i = 0; i < HPET_Length; ++i) {
        system(HPET_Disabler[i]);
        cout << "\nThe processes within %s has been Cleared.\n" << HPET_Disabler[i];
    };
}

#endif