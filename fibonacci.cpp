#include <iostream>
#include <math.h>

using namespace std;

//prototype
int Fibonacci(int n);
int recursTest(int n);
int askNumber();

int main()
{
	int F(0);
	F = Fibonacci(3);

	cout << F << endl;
	return 0;
}

int Fibonacci(int n)
{
	if(n <= 1)
	{
		return n;
	}
   
	return Fibonacci(n-1) +  Fibonacci(n-2);
}

int askNumber()
{
	cout << " Write a number between 0 and 40 !!";
	int number(0);
	cin >> number;
	cout << endl;

	
}
