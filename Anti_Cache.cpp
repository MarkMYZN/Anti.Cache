#include <iostream>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <thread>

#include "Startup_Disabler.hpp"
#include "PC_Booster.hpp"
#include "Cache_Clean.hpp"
#include "Ip_Flusher.hpp"
#include "PC_Health_Checker.hpp"
#include "Services_Disabler.hpp"
#include "defragger.hpp"
#include "HPET_Disabler.hpp"

using namespace std;

int main(){
    cout<<"\n==================\n";
    cout<<"Anti.Cache V4\n";
    cout<<"Made by: _Mark\n";
    cout<<"==================\n";

    cout<<"!!WARNING!!\n";
    cout<<"This application takes a long time to finish.\n";
    cout<<" Please only run it when shutting down your computer and PLEASE BE PATIENT. \n";
    cout<<"Stopping it can cause problems, so be careful.\n";
    cout<<"Commands will run in Twenty(20) Seconds to Close this window if you ran this accedentally.\n\n";
    
    for (int i = 20; i > 0; --i) {
        cout << "Time left: " << i << endl;
        this_thread::sleep_for(chrono::seconds(1));  // Sleep for 1 second
    }
    cout<<"Running Anti.Cache.....";


    ofstream outFile("Anti.Cache_Logs.txt");
    streambuf* coutbuf = cout.rdbuf();
    cout.rdbuf(outFile.rdbuf());

//=====================|| For Logs Credits ||========================
    cout<<"\n==================\n";
    cout<<"Anti.Cache V4\n";
    cout<<"Made by: _Mark";
    cout<<"\n==================\n";
    cout<<"Running Anti.Cache.....";
// ==========|| Creates a Restore Point ||==========
    system("wmic.exe /Namespace:\\\\root\\default Path SystemRestore Call CreateRestorePoint \"Latest Restore-Point\", 100, 7  > NUL 2>&1");
// ==========|| Processes ||==========
    HPET_Disabler();
    Startup_Disabler();
    Services_Disabler();
    PC_Booster();
    Cache_Clean();
    Ip_Flusher();
    PC_Health_Checker();
    defragger();

// ==========|| Creates a Restore Point ||==========    
    cout << "\nAll Processes has been completed. \nThank you For Using Anti-Cache.\n";
    cout << "All logs should be found at: \"Anti.Cache_Logs.txt\"\n";

    cout << "You will need to restart your PC to Apply Changes.\n";
    cout << "This PC Will be shutting down in Five (5) seconds.\n";

// ==========|| PC Shutdown ||=========================
	for (int i = 5; i > 0; --i) {
        cout << "Time left: " << i << endl;
        this_thread::sleep_for(chrono::seconds(1));  // Sleep for 1 second
    }
    cout<<"Shutting Down.....";
    cout.rdbuf(coutbuf);
    outFile.close();
    system("shutdown /s /f /t 0");
}
