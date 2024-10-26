#ifndef defragger_h
#define defragger_h

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class defragger
{
	public:
		defragger();
	protected:
};

defragger::defragger()
{
        system("defrag /C /O > NUL 2>&1");
        cout<<"\n\"Defragged\" Existing Drives.\n";
}


#endif