#include <iostream>
#include <stdio.h>  
using namespace std;

double abs (double num)
{
	return num < 0.00 ? -1*num: num ;
}

double findSquareRoot(double num)
{
	double estimate, quotient, mean = 1.0000;

	cout<< "Estimate\t\tQuotient\t\tMean" << endl;
	cout<< "----------------------------------------------------" << endl;

	while (abs(estimate - quotient)/quotient > 0.001){
		estimate = mean;
		quotient = num/estimate;
		mean = (estimate + quotient)/2;
		cout<< estimate << "\t\t\t" << quotient << ",\t\t\t" << mean << endl;
	}

	return mean;
}

int main()
{
	double	input, result = 0.0000;
	char	exit;
	
	while (toupper(exit) != 'Y'){
		
		exit = ' ';

		cout<< "Please enter value to find square root: ";
		cin>> input;

		result = input == 0 ? 0: findSquareRoot(abs(input));
		cout<< "The square root of " << input << " is " << result << (input < 0 ? "i": "") << endl << endl;

		while (toupper(exit) != 'N' && toupper(exit) != 'Y'){
			cout<< "Do you want to exit? (N=No, Y=Yes) : ";
			cin>> exit;
			cout<< endl;
		}
	}

	return 0;
}

