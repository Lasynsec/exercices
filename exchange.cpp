#include <iostream>
using namespace std;

//prototytpes
void alternator(int& first, int& second);
int askIt();

int main()
{
	int first(askIt());
	int second(askIt());
	
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

int askIt()
{
	cout << " Type a number : ";
	int nbr(0);
	while(!(cin>>nbr))
	{
		cout << "It must be a number !!! "<< endl;
		cin.clear();
		cin.ignore(1000,'\n');
	}
	cout << endl;
	
	return nbr;
}
