#include <iostream>
using namespace std;

int main()
{	
	cout << " How old are you ?" << endl;
	int age(0);
	cin >> age;

	int birthYear;
	
	birthYear = 2016 - age;

	cout << "you are born in " << birthYear << endl;

	return 0;
}
