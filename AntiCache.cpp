#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

    // C:\WINDOWS\system32\svchost.exe



    //I created this software with the idea of helping people with slow computers.
        
    //If ran, it will optimize, clean, refresh, and repair missing or corrupted files
    //in your computer.
        
    //Make sure to run it as Administrator, And please proceed with caution. 
    

int main(){
    system("echo Created By MarkMYZN");
    printf("The code will execute shortly.\n");
    printf("Do not exit the console.");
    system("echo off");

    FILE *fp;
    fp = fopen("log.txt", "w");
    if (fp == NULL) {
        perror("Error opening log file");
        return 1;
    }

// Redirect stdout and stderr to the log file
    if (freopen("log.txt", "w", stdout) == NULL) {
        perror("Error redirecting stdout to log file");
        return 1;
    }
    if (freopen("log.txt", "w", stderr) == NULL) {
        perror("Error redirecting stderr to log file");
        return 1;
    }

// ==========|| Creates a Restore Point ||==========
    system("wmic.exe /Namespace:\\\root\\default Path SystemRestore Call CreateRestorePoint \"Latest Restore-Point\", 100, 7");

// ==========|| Disables Some Services from Starting in Logon ||==========
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
        ,"Steam Client Service"
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
        printf("\n%s Has been disabled.\n", ServicesDisabler[i]);
    };

// ==========|| Disables Some apps from Starting in Logon ||==========  
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
        printf("\nAll startups within %s has been Cleared.\n", StartupDisabler[i]);
    }


// ==========|| Disable HPET ||==========
    const char* HPET_Disabler[] = {
        "bcdedit /deletevalue useplatformclock"
        ,"bcdedit /set disabledynamictick yes"
        ,"bcdedit /set useplatformtick yes"
    };
    int HPET_Length = sizeof(HPET_Disabler) / sizeof(HPET_Disabler[0]);

    for (int i = 0; i < HPET_Length; ++i) {
        system(HPET_Disabler[i]);
        printf("\nThe processes within %s has been Cleared.\n", HPET_Disabler[i]);
    };

// ==========|| System Junk Cleanup ||==========
    const char* SysJunkCleaner[] = {
        "del %%temp%% /f /s /q"
        ,"del %%Windir%%\\Temp /f /s /q"
        ,"del C:\\WINDOWS\\Prefetch  /f /s /q"
        ,"RD /S /Q C:\\$Recycle.Bin"
        ,"RunDll32.exe InetCpl.cpl,ClearMyTracksByProcess 8"
        ,"RD /S /Q C:\\Users\\YourUsername\\AppData\\Local\\Microsoft\\Windows\\Explorer"
        ,"net stop wuauserv"
        ,"RD /S /Q C:\\Windows\\SoftwareDistribution"
        ,"net start wuauserv"
    };
    int SysJunkLength = sizeof(SysJunkCleaner) / sizeof(SysJunkCleaner[0]);

    for (int i = 0; i < SysJunkLength; ++i) {
        system(SysJunkCleaner[i]);
        printf("\nJunk files within %s has been Cleared.\n", SysJunkCleaner[i]);
        printf("\nDont Worry about the \"Access-Denied\" within the outputs. its trying to repeat the process again.\n");
    };

// ==========|| Application Junk Cleanup ||==========
    const char* AppJunkCleaner[] = {
        "del C:\\Windows\\Temp /f /q"
        ,"del C:\\Users\\Miyazono\\AppData\\Local\\D3DSCache /f /q"
        ,"del C:\\Users\\Miyazono\\AppData\\Local\\Microsoft\\Windows\\Explorer /f /q"
    };
    int AppJunkLength = sizeof(AppJunkCleaner) / sizeof(AppJunkCleaner[0]);

    for (int i = 0; i < AppJunkLength; ++i) {
        system(AppJunkCleaner[i]);
        printf("\nJunk files within %s has been Cleared.\n", AppJunkCleaner[i]);
    };



// ==========|| AMD Optimizer (CPU and GPU) ||========== (this interacts with the registry editor.)
    const char* AMD_Optimizer[] = {

    //AMD CPU Priority - High
        "reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"GPU Priority\" /t REG_DWORD /d 8 /f"
        ,"reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Priority\" /t REG_DWORD /d 6 /f"
        ,"reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Scheduling Category\" /t REG_SZ /d \"High\" /f"
        ,"reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"SFIO Priority\" /t REG_SZ /d \"High\" /f"
    //AMD GPU Priority - High
        ,"reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"GPU Priority\" /t REG_DWORD /d 8 /f"
        ,"reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Priority\" /t REG_DWORD /d 6 /f"
        ,"reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"Scheduling Category\" /t REG_SZ /d \"High\" /f"
        ,"reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\\Tasks\\Games\" /v \"SFIO Priority\" /t REG_SZ /d \"High\" /f"
    //Boost System Responsiveness
        ,"reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Multimedia\\SystemProfile\" /v \"SystemResponsiveness\" /t REG_DWORD /d 1 /f"
    //Disable GPU Energy Driver
        ,"reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Services\\GpuEnergyDrv\" /v \"Start\" /t REG_DWORD /d 4 /f"
    //Disable GPU Power Throttling
        ,"reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Power\\PowerThrottling\" /v \"PowerThrottlingOff\" /t REG_DWORD /d 1 /f"
    };
    int AMD_OptLength = sizeof(AMD_Optimizer) / sizeof(AMD_Optimizer[0]);

    for (int i = 0; i < AMD_OptLength; ++i) {
        system(AMD_Optimizer[i]);
        printf("\n%s has been Added and is ready to go.\n", AMD_Optimizer[i]);
    };

// ==========|| IP Flushing and Renewal ||==========
    const char* Ip_Flusher[] = {
        "ipconfig /flushdns"
        ,"ipconfig /registerdns"
        ,"ipconfig /release"
        ,"ipconfig /renew"
        ,"nbtstat -R"
        ,"nbtstat -RR"
        ,"netsh int reset all"
        ,"netsh int ip reset"
        ,"netsh winsock reset"
    };
    int FlusherLength = sizeof(Ip_Flusher) / sizeof(Ip_Flusher[0]);

    for (int i = 0; i < FlusherLength; ++i) {
        system(Ip_Flusher[i]);
        printf("\nIp Address and DNS's within %s has been Cleared.\n", Ip_Flusher[i]);
    };

// ==========|| PC Checkhealth and ScanNow ||==========
    const char* DISM_coms[] = {
        "DISM /Online /Cleanup-Image /CheckHealth"
        ,"DISM /Online /Cleanup-Image /ScanHealth"
        ,"DISM /Online /Cleanup-Image /RestoreHealth /Source:repairSource\\install.wim"
    };
    int DISM_Length = sizeof(ServicesDisabler) / sizeof(DISM_coms[0]);

    for (int i = 0; i < DISM_Length; ++i) {
        system(DISM_coms[i]);
        printf("\nDISM Commands within %s is done.\n", DISM_coms[i]);
    };

    printf("You will need to restart your PC to Apply Changes.\n");
    printf("This PC Will be shutting down in just a moment.\n");


    fclose(fp);

    // PC Shutdown
    system("shutdown -s -t 0");

    // PC Restart (change if needed)
    // system("shutdown -r -t 0");


    /*                    ==========|| Other commands: ||==========
    ==========|| These are some commands that didnt go with the main code. ||==========

    ipconfig /flushdns
    ipconfig /registerdns
    ipconfig /release
    ipconfig /renew
    nbtstat -R 
    nbtstat -RR
    netsh int reset all
    netsh int ip reset
    netsh winsock reset
    sfc /scannow
    DISM /Online /Cleanup-Image /CheckHealth
    DISM /Online /Cleanup-Image /ScanHealth
    DISM /Online /Cleanup-Image /RestoreHealth /Source:repairSource\install.wim
    
    // ==========|| App Cache Deletion ||==========
    system("del C:\\Users\\Miyazono\\AppData\\Roaming\\discord\\Cache /q");
    system("del C:\\Users\\Miyazono\\AppData\\Local\\Steam\\htmlcache\\GPUCache /q");
    system("del C:\\Users\\Miyazono\\AppData\\Local\\Steam\\htmlcache\\Cache /q");
    system("del C:\\Windows\\Prefetch /f /q");
    */

return 0;
}
