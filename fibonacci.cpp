#include <iostream>
#include <math.h>
#include <string>
#include <ctype.h>
#include <limits>


using namespace std;

//prototypes
int Fibonacci(int n);
int askNumber();
bool playAgain(0);

int main()
{

	int askIt(0);
	int F(0);
	
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

				if(inputAgain !='n' && inputAgain != 'y'){
					cout << "I don't understand !" << endl;	
				}else{		
					if(inputAgain =='y'){
						playAgain = 1;
					} else {
						playAgain = 0;
						cout << "Goodbye !!"<<endl;
					}
				}
				
		}while(inputAgain != 'y' && inputAgain != 'n');
	}while(playAgain == 1);

	return 0;
}

/*
	calculate the nth value of fibonacci.
*/
int Fibonacci(int n)
{
	if(n <= 1){
		return n;
	}

	return Fibonacci(n-1) +  Fibonacci(n-2);
}

/*
	return the user input.
*/
int askNumber()
{
	int number;
	int increment(0);
	do{
	   cout << "Write a number between 0 and 40 !! : ";
	   if(!(cin >> number)){
			cout << "Please enter numbers only"<< endl;
			cin.clear();
			cin.ignore(1000,'\n');
	   }else if(number < 1){
	   	cout << "The number must be greater than 0 " << endl;	
	   } else if(number > 40){
	   	cout << "The number must be less  than 41" << endl;	
	   }
	}while(number < 1 || number > 40); // while number is not < 1
	
	return number;
}
