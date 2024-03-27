#ifndef PC_HEALTH_CHECKER_H
#define PC_HEALTH_CHECKER_H

#include <iostream>
using namespace std;

class PC_Health_Checker
{
	public:
		PC_Health_Checker();
	protected:
};

PC_Health_Checker::PC_Health_Checker()
{
	const char* DISM_coms[] = {
        "DISM /Online /Cleanup-Image /CheckHealth"
        ,"DISM /Online /Cleanup-Image /ScanHealth"
        ,"DISM /Online /Cleanup-Image /RestoreHealth /Source:repairSource\\install.wim"
    };
    int DISM_Length = sizeof(DISM_coms) / sizeof(DISM_coms[0]);

    for (int i = 0; i < DISM_Length; ++i) {
        system(DISM_coms[i]);
        cout << "\nDISM Commands within %s is done.\n" << DISM_coms[i];
    };
}

#endif