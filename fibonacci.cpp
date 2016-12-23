#include <iostream>
#include <math.h>

using namespace std;

//prototype
int Fibonacci(int n);
int askNumber();

int main()
{
	int F(0);
	int askIt(0);
	
	askIt = askNumber();
	F = Fibonacci(askIt);

	cout <<" The" << <<"number of fibonacci is "<< F << endl;
	return 0;
}

/*
return the nth value of fiboncci.
*/
int Fibonacci(int n)
{
	if(n <= 1)
	{
		return n;
	}

	return Fibonacci(n-1) +  Fibonacci(n-2);
}

/*
return the user value.
*/
int askNumber()
{
	int number;
	int increment(0);

	do{
	   cout << " Write a number between 0 and 40 !! : ";
	   cin >> number;
	   cout << endl;

	   if(number < 1)
	   {
	   	cout << " The number must be greater than 0 " << endl;	
	   }
       
	}while(number < 1); // while number is not < 1
	
	return number;
}
