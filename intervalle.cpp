#include <iostream>
using namespace std;

int main()
{
	cout << " Write a number " << endl;
	double x(0);

	cin >> x;

	if(x >= -1 && x < 1){
		cout << " X belongs to I" << endl;
	} else {
		cout << " X doesn't belong to I" << endl;
	}
	return 0;
}
