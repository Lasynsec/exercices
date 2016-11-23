#include <iostream>
#include <math.h>
#include <string>

using namespace std;


int main()
{
	cout << " Write a Reel Number : ";
	double x(0.0), result(0.0);
	cin >> x;
/* expression 1*/
	if(exp(x) != 1.0){
		result = x / (1.0 - exp(x));
		cout << " Expression 1 : " <<  result  << endl; 
	} else { 
		cout <<  " Expression 1 Undefined !" << endl;
	}

/* expression 2 */
	if(x > 1.0 ){
		result = x * log(x) * exp(2.0 / (x - 1));
		cout << " Expression 2 : " << result << endl;
	} else {
		cout << " Expression 2 Undefined !" << endl;
	}

/* expression 3*/
	if(x >= 8){
		result = (-x - sqrt(x*x - 8.0 * x) ) / (2.0 - x);	
		cout << " Expression 3 : " << result << endl;
	} else {
		cout << " Expression 3 Undefined !" << endl;
	}

/* expression 4*/
	if(x > 0){	
		result = sqrt( (sin(x) - (x/20.0)) * log(x*x - 1/x));
		cout << " Expression 4 : " << result << endl;

		if(result == "-nan") {
			cout << " not good" << endl;
		}
	} else {
		cout << " Expression 4 Undefined !" << endl;
	}
	return 0;
}
