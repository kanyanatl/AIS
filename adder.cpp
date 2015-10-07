#include <iostream>
#include <stdio.h>  
using namespace std;

class Adder {
	bool sum, carry;

public:
	Adder (bool, bool);
	Adder (bool, bool, bool);
	bool GetSum() {return sum;}
	bool GetCarry() {return carry;}

private:
	void FindHalfAdder (bool a, bool b){
			this->sum = a ^ b;
			this->carry = a & b;
	}

	void FindFullAdder (bool a, bool b, bool c){
		bool s_ha1, c_ha1, s_ha2, c_ha2;

		//Find the first Half adder 
		this-> FindHalfAdder (b,c);
		//s_ha1 = this-> GetSum();
		c_ha1 = this-> GetCarry();

		//Find the second Half adder 
		this-> FindHalfAdder (a,this-> GetSum());
		c_ha2 = this-> GetCarry();

		this->sum = this-> GetSum();
		this->carry = c_ha1 || c_ha2;
	}
};

Adder :: Adder (bool a, bool b){
	this-> FindHalfAdder (a, b);
}

Adder :: Adder (bool a, bool b, bool c){
	this-> FindFullAdder (a, b, c);
}

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
				cout<< "Please Enter input (a b): ";
				cin>> a >> b;
			}
			else if (toupper(adderType) == 'F'){
				cout<< "Please Enter input (a b c): ";
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