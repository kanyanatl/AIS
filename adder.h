#ifndef ADDER_H
#define ADDER_H
#include <string>
using namespace std;

class Adder {
private:
	bool sum, carry;

public:
	Adder (bool, bool);
	Adder (bool, bool, bool);
	bool GetSum() {return sum;}
	bool GetCarry() {return carry;}

private:
	void FindHalfAdder (bool a, bool b){
			sum = a ^ b;
			carry = a & b;
	}

	void FindFullAdder (bool a, bool b, bool c){
		bool c_ha1, s_ha2, c_ha2;

		//Find the first Half adder 
		FindHalfAdder (b,c);
		c_ha1 = GetCarry();

		//Find the second Half adder 
		FindHalfAdder (a, GetSum());
		c_ha2 = GetCarry();

		sum = GetSum();
		carry = c_ha1 || c_ha2;
	}
};

Adder :: Adder (bool a, bool b){
	//Constructor for half adder
	this-> FindHalfAdder (a, b);
}

Adder :: Adder (bool a, bool b, bool c){
	//Constructor for full adder
	this-> FindFullAdder (a, b, c);
}

#endif