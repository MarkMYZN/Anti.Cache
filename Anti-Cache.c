#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    
    /*
        I created this software with the idea of helping people with slow computers.
        
            If ran, it will optimize, clean, refresh, and repair missing or corrupted files
        in your computer.
        
        Make sure to run it as Administrator, And please proceed with caution.
    */

    system("echo Created By MarkMYZN");
    system("echo off");

    system("wmic.exe /Namespace:\\\root\\default Path SystemRestore Call CreateRestorePoint "Latest Restore-Point", 100, 7");

    system("powercfg -duplicatescheme e9a42b02-d5df-448d-aa00-03f14749eb61"); 
    // doesnt do anything more than add an additional power "ultimare" power feature

    // ==========|| Disables Some apps from Starting in Logon ||==========
    system("reg add HKLM\\SOFTWARE\\Microsoft\\Active Setup\\Installed Components /v Google Chrome /t REG_SZ /d "" /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\Active Setup\\Installed Components /v Microsoft Edge /t REG_SZ /d "" /f");
    system("reg add HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /v Steam /t REG_SZ /d "" /f");
    system("reg add HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /v MicrosoftEdgeAutoLaunch_F0F41C1CE79B46820675944F246DE300 /t REG_SZ /d "" /f");
    system("reg add HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /v Discord /t REG_SZ /d "" /f");

    // ==========|| Disable HPET ||==========
    system("bcdedit /deletevalue useplatformclock");
    system("bcdedit /set disabledynamictick yes");
    system("bcdedit /set useplatformtick yes");

    // ==========|| System Junk Cleanup ||==========
    system("del %%temp%% /f /s /q");
    system("del %%Windir%%\\Temp /f /s /q");
    system("del C:\\WINDOWS\\Prefetch  /f /s /q");
    system("RD /S /Q C:\\$Recycle.Bin");
    system("RunDll32.exe InetCpl.cpl,ClearMyTracksByProcess 8");
    system("RD /S /Q C:\\Users\\YourUsername\\AppData\\Local\\Microsoft\\Windows\\Explorer");
    system("net stop wuauserv");
    system("RD /S /Q C:\\Windows\\SoftwareDistribution");
    system("net start wuauserv");

    // ==========|| Application Junk Cleanup ||==========
    system("del C:\\Windows\\Temp /f /q");
    system("del C:\\Users\\Miyazono\\AppData\\Local\\D3DSCache /f /q");
    system("del C:\\Users\\Miyazono\\AppData\\Local\\Microsoft\\Windows\\Explorer /f /q");

    // ==========|| AMD Optimizer (CPU and GPU) ||========== (this interacts with the registry editor.)

    //AMD CPU Priority - High
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"GPU Priority\" /t REG_DWORD /d 8 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Priority\" /t REG_DWORD /d 6 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Scheduling Category\" /t REG_SZ /d \"High\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"SFIO Priority\" /t REG_SZ /d \"High\" /f");

    //AMD GPU Priority - High
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"GPU Priority\" /t REG_DWORD /d 8 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Priority\" /t REG_DWORD /d 6 /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Scheduling Category\" /t REG_SZ /d \"High\" /f");
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"SFIO Priority\" /t REG_SZ /d \"High\" /f");

    //Boost System Responsiveness
    system("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\" /v \"SystemResponsiveness\" /t REG_DWORD /d 1 /f");

    //Disable GPU Energy Driver
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\GpuEnergyDrv\" /v \"Start\" /t REG_DWORD /d 4 /f");

    //Disable GPU Power Throttling
    system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Power\\PowerThrottling\" /v \"PowerThrottlingOff\" /t REG_DWORD /d 1 /f");


    // ==========|| IP Flushing and Renewal ||==========
    system("ipconfig /flushdns");
    system("ipconfig /registerdns");
    system("ipconfig /release");
    system("ipconfig /renew");
    system("nbtstat -R");
    system("nbtstat -RR");
    system("netsh int reset all");
    system("netsh int ip reset");
    system("netsh winsock reset");

    // ==========|| PC Checkhealth and ScanNow ||==========
    system("sfc /scannow");
    system("DISM /Online /Cleanup-Image /CheckHealth");
    system("DISM /Online /Cleanup-Image /ScanHealth");
    system("DISM /Online /Cleanup-Image /RestoreHealth /Source:repairSource\\install.wim");

    // PC Shutdown
    system("shutdown -s -t 0");

    // PC Restart (change if needed)
    // system("shutdown -r -t 0");


    //                    ==========|| Other commands: ||==========
    /*
    ==========|| These are some commands that didnt go with the main code. ||==========

    //ipconfig /flushdns
    //ipconfig /registerdns
    //ipconfig /release
    //ipconfig /renew
    //nbtstat -R 
    //nbtstat -RR
    //netsh int reset all
    //netsh int ip reset
    //netsh winsock reset
    //sfc /scannow
    //DISM /Online /Cleanup-Image /CheckHealth
    //DISM /Online /Cleanup-Image /ScanHealth
    //DISM /Online /Cleanup-Image /RestoreHealth /Source:repairSource\install.wim
    
    // ==========|| App Cache Deletion ||==========
    system("del C:\\Users\\Miyazono\\AppData\\Roaming\\discord\\Cache /q");
    system("del C:\\Users\\Miyazono\\AppData\\Local\\Steam\\htmlcache\\GPUCache /q");
    system("del C:\\Users\\Miyazono\\AppData\\Local\\Steam\\htmlcache\\Cache /q");
    system("del C:\\Windows\\Prefetch /f /q");
    */

return 0;
}
