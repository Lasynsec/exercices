#include <iostream>
using namespace std;


void alternator(int& first, int& second);

int main()
{
	int first(30);
	int second(50);

	cout << " Before : " << first << " and " << second << endl;
	alternator(first,second); 	
	cout << " After : " << first << " and " << second << endl;
	return 0;
}


void alternator(int& first, int& second) 
{
	int temp(0);
	temp = first;
	first = second;
	second = temp;
}

