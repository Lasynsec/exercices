
#include<iostream>
#include<math.h>
using namespace std;

//prototypes
double factorial(int k);
int askForN();
double askForX();
double partialSum(double x, int n);

int main()
{
	int n = askForN();

	double x = askForX();	
	double cos(0);
	cos = partialSum(x,n);
	
	cout << " The cos is : " << cos << endl;

	return 0;		
}

double factorial(int k)
{
	int facto(1);
	for(size_t i(1); i <= k ; i++){
		facto *= i;
	}
	
	cout << "The factorial is : " << facto << endl;
	return facto;
}

int askForN()
{
	int n(0);
	do{
		cout << " Write an integer (n) under 85" << endl;
		cin >> n;
		if(n > 85){
			cout << " The integer (n) is too high" << endl;
		} else if(n <= 0){
			cout << " The integer (n) is to low" << endl;
		} else {
			cout << " alright !! " << endl;
		}
	}while(n > 85 || n < 0);
	
	return n;
}

double askForX()
{
	double x;
	do{
		cout << "Write a number (x) greater than 0 " << endl;
		cin >> x;
	if(x < 0){
		cout << " the number(x) is too low !!" << endl;
	} else {
		cout << " alright !!!" << endl;
	}
	}while(x < 1);

	return x;
}

double partialSum(double x, int n)
{
	double cos(0);
	for(size_t i(0); i <= n; i++)
	{
		cos += (pow(-1.0,i) * pow(x,2.0 * i))/factorial(2.0*i);
	}
	
	return cos;
}
