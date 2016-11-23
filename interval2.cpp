#include <iostream>
using namespace std;

int main()
{
	cout << " Write a number " << endl;
	double x(0);

	cin >> x;

	if((x >= 2 && x < 3) || (x > 0 && x <= 1) || (x >= -10 && x <= -2)){
		cout << " X belongs to "<< endl;
	} else {
		cout << " X doesn't belong to I" << endl;
	}
}
