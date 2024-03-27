#ifndef IP_FLUSHER_H
#define IP_FLUSHER_H

#include <iostream>
using namespace std;

class Ip_Flusher
{
	public:
		Ip_Flusher();
	protected:
};

Ip_Flusher::Ip_Flusher()
{
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
        cout << "\nIp Address and DNS's within %s has been Cleared.\n" << Ip_Flusher[i];
    };
}

#endif