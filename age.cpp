#include <iostream>
using namespace std;

int main()
{	
	cout << " How old are you ?" << endl;
	int age(0);					// will receive the user input.
	while(!(cin>>age)){				// ask until the user type a number.
		cin.clear();				// clear the error buffer.
		cin.ignore(1000,'\n');			// ignore it in memory address.
		cout << "It must be a number !!!"<<endl;
	}

	int birthYear;
	birthYear = 2016 - age;
	cout << "you are born in " << birthYear << endl;

	return 0;
}
