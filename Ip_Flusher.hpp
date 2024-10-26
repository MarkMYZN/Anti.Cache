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
        system("ipconfig /flushdns > NUL 2>&1");
        cout<<"DNS Cleared." << endl ;

        system("ipconfig /registerdns > NUL 2>&1");
        cout<<"DNS Registered." << endl ;

        system("ipconfig /release > NUL 2>&1");
        cout<<"IP Released." << endl ;

        system("ipconfig /renew> NUL 2>&1");
        cout<<"Renewing IP..." << endl ;

        system("nbtstat -R > NUL 2>&1");
        cout<<"Done " << endl ;

        system("nbtstat -RR> NUL 2>&1");
        cout<<"Done." << endl ;

        system("netsh int reset all > NUL 2>&1");
        cout<<"Done." << endl ;

        system("netsh int ip reset > NUL 2>&1");
        cout<<"Done." << endl ;

        system("netsh winsock reset > NUL 2>&1");
        cout<<"Done." << endl ;

}

#endif