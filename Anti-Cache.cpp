#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <thread>

#include "AMD_Optimizer.h"
#include "App_Junk_Cleaner.h"
#include "HPET_Disabler.h"
#include "Ip_Flusher.h"
#include "Junk_Cleaner.h"
#include "PC_Health_Checker.h"
#include "Services_Disabler.h"
#include "Startup_App_Disabler.h"


using namespace std;

int main(){
    cout << "Created By MarkMYZN\n";
	cout << "The code will execute shortly.\n";
	cout << "Do not exit the console.\n";
	system("echo off");
	
    ofstream outFile("Anti_Cache_Logs.txt");

    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(outFile.rdbuf());


// ==========|| Creates a Restore Point ||==========
    system("wmic.exe /Namespace:\\\\root\\default Path SystemRestore Call CreateRestorePoint \"Latest Restore-Point\", 100, 7");

// ==========|| Disables Some Services from Starting in Logon ||==========
    Services_Disabler();

// ==========|| Disables Some apps from Starting in Logon ||==============
    Startup_App_Disabler();

// ==========|| Disable HPET ||========================
    HPET_Disabler();

// ==========|| System Junk Cleanup ||=================
    Junk_Cleaner();

// ==========|| Application Junk Cleanup ||============
    App_Junk_Cleaner();

// ==========|| AMD Optimizer (CPU and GPU) ||========= (this interacts with the registry editor.)
    AMD_Optimizer();

// ==========|| IP Flushing and Renewal ||=============
    Ip_Flusher();

// ==========|| PC Checkhealth and ScanNow ||==========
    PC_Health_Checker();



    cout << "All Processes has been completed. Thank you For Using Anti-Cache.\n";


    cout.rdbuf(coutbuf);
    outFile.close();
    
    
    cout << "All Processes has been completed. Thank you For Using Anti-Cache.\n";
    cout << "You will need to restart your PC to Apply Changes.\n";
    cout << "This PC Will be shutting down in Five (5) seconds.\n";

// ==========|| PC Shutdown ||=========================

	this_thread::sleep_for(chrono::seconds(5));
    system("shutdown /s /f /t 0");
};