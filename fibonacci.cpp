#include <iostream>
#include <math.h>
#include <string>
#include <ctype.h>


using namespace std;

//prototype
int Fibonacci(int n);
int askNumber();
bool playAgain(0);

int main()
{
	do{
		int F(0);
		int askIt(0);
		string nth;
	
		askIt = askNumber();
		F = Fibonacci(askIt);
	
		switch(askIt){
			case 1:
				nth = "st";
				break;
			case 2:
				nth = "nd";
				break;
			case 3:
				nth = "rd";
				break;
			default:
				nth = "th";
		}	

			cout <<"The " << askIt << nth <<" number of fibonacci is "<< F << endl;
			char inputAgain;
		do{
			
			cout << " Do you want to play again ? (y or n): ";
			cin >> inputAgain;
			cout << endl;

				if(inputAgain !='n' && inputAgain != 'y'){/* must loop if the user don't put the n button*/
					cout << " don't understand !" << endl;	
				}else{		
					if(inputAgain =='y'){
						playAgain = 1;
					} else {
						playAgain = 0;
					}
				}
				
		}while(inputAgain != 'y' && inputAgain != 'n');
	}while(playAgain == 1);

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
	   } else if(number > 40){
	   	cout << " The number must be less  than 41" << endl;	
	   }
       
	   if(!isdigit(number)){/*Problem with the isdigit*/
			cout << " You have to write a number !!!" << endl;
	   }

	}while(number < 1 || number > 40 || !isdigit(number)); // while number is not < 1
	
	return number;
}
