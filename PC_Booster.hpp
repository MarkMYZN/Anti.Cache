#ifndef PC_BOOSTER_H
#define PC_BOOSTER_H

#include <iostream>
using namespace std;

class PC_Booster
{
	public:
		PC_Booster();
	protected:
};

PC_Booster::PC_Booster()
{
    //Boost System Responsiveness
        system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\" /v \"SystemResponsiveness\" /t REG_DWORD /d 1 /f > NUL 2>&1");
        cout<<"\n\"SystemResponsiveness\" Added.\n";
        cout<<"\"SystemResponsiveness\" Enabled.\n";
    //Disable GPU Energy Driver
        system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\GpuEnergyDrv\" /v \"Start\" /t REG_DWORD /d 4 /f > NUL 2>&1");
        cout<<"\"GpuEnergyDrv Start\" Disabled.\n";
    //Disable GPU Power Throttling
        system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Power\\PowerThrottling\" /v \"PowerThrottlingOff\" /t REG_DWORD /d 1 /f > NUL 2>&1");
        cout<<"\"PowerThrottlingOff\" Disabled.\n";
}

#endif