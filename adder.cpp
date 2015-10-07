#include <iostream>
#include <stdio.h>  

#include "adder.h"

using namespace std;

int main()
{
	bool a, b, c;
	char exit, adderType;

	while (toupper(exit) != 'Y'){

		exit = ' ';
		cout<<	"What adder would you like to find out? (H=Half, F=Full) : ";
		cin>>	adderType;

		if (toupper(adderType) == 'H' || toupper(adderType) == 'F'){
			if (toupper(adderType) == 'H'){
				cout<< "Please enter input (a b): ";
				cin>> a >> b;
			}
			else if (toupper(adderType) == 'F'){
				cout<< "Please enter input (a b c): ";
				cin>> a >> b >> c;
			}

			Adder adder = toupper(adderType) == 'H'? Adder(a,b) : Adder(a, b, c);
			cout<< "Sum:\t" << adder.GetSum() << endl;
			cout<< "Carry:\t" << adder.GetCarry() << endl; 
		}

		while (toupper(exit) != 'N' && toupper(exit) != 'Y'){
			cout<< "Do you want to exit? (N=No, Y=Yes) :";
			cin>> exit;
			cout<< endl;
		}
	}

	return 0;
}


