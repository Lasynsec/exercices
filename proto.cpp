#include <iostream>
using namespace std;

int askForANumber(int min, int max); 

int main()
{	
	askForANumber(1,10);
	return 0;	
}

int askForANumber(int min, int max)
{
	int numberToSend(0);
	do{
	    cout << " Write a integer ";
		cin >> numberToSend;
	}while((min > numberToSend) ||(max < numberToSend));

	return numberToSend;
}
