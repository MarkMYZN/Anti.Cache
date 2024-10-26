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
    system("DISM /Online /Cleanup-Image /CheckHealth > NUL 2>&1");
    system("DISM /Online /Cleanup-Image /ScanHealth > NUL 2>&1");
    system("DISM /Online /Cleanup-Image /RestoreHealth /Source:repairSource\\install.wim > NUL 2>&1");
}

#endif