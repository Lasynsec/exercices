#include <iostream>
#include <math.h>

using namespace std;

//prototype
int Fibonacci(int n);

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
    //cout << " n" << " = " << n << endl;
		return n;
	}

    //cout << Fibonacci(n-1) << " + " <<Fibonacci(n-2)  <<" = " << Fibonacci(n-1) + Fibonacci(n-2) << endl;
	return Fibonacci(n-1) +  Fibonacci(n-2);
}

