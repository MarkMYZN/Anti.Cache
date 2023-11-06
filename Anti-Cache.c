#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    
    system("echo off");

    // ==========|| Browser Cache Deletion ||==========
    system("del C:\\Users\\Miyazono\\AppData\\Roaming\\discord\\Cache /q");
    system("del C:\\Users\\Miyazono\\AppData\\Local\\Steam\\htmlcache\\Cache /q");
    system("del C:\\Users\\Miyazono\\AppData\\Local\\Steam\\htmlcache\\GPUCache /q");

    // ==========|| App Cache Deletion ||==========
    system("del C:\\Users\\Miyazono\\AppData\\Roaming\\discord\\Cache /q");
    system("del C:\\Users\\Miyazono\\AppData\\Local\\Steam\\htmlcache\\GPUCache /q");
    system("del C:\\Users\\Miyazono\\AppData\\Local\\Steam\\htmlcache\\Cache /q");
    system("del C:\\Windows\\Prefetch /f /q");

    // ==========|| Temporary File Remover ||==========
    system("del C:\\Windows\\Temp /f /q");
    system("del C:\\Users\\Miyazono\\AppData\\Local\\D3DSCache /f /q");
    system("del C:\\Users\\Miyazono\\AppData\\Local\\Microsoft\\Windows\\Explorer /f /q");

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

    /*
    ==========|| Other commands: ||==========

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
    
    */

return 0;
}