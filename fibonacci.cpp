#include <iostream>
#include <math.h>
#include <string>
#include <ctype.h>
#include <limits>


using namespace std; 

//prototypes
int Fibonacci(int n); // this function will calculate and return a fibonacci number
int askNumber(); // this functiun ask for the user input
bool playAgain(0); // this function ask to the user to play again

int main()
{

	do{
		int F(0); //will receive the fibonacci value.
		int askIt(0); // will receive the user value.
		string nth; // will receive the ordinal indicator.
	
		askIt = askNumber();// the user value
		F = Fibonacci(askIt);// the fibonacci value
	
		switch(askIt){
			case 1: // if the user type one.
				nth = "st";
				break;
			case 2: // If the user type two.
				nth = "nd";
				break;
			case 3: // If the user type three.
				nth = "rd";
				break;
			default: // otherwise.
				nth = "th";
		}	

			cout <<"The " << askIt << nth <<" number of fibonacci is "<< F << endl;
			char inputAgain; // will receive the user decision.
		do{
			cout << " Do you want to play again ? (y or n): ";
			cin >> inputAgain; // ask for the user decision.
			cout << endl;

				if(inputAgain !='n' && inputAgain != 'y'){ // if not n or y.
					cout << "I don't understand !" << endl;	// display this
				}else{	// else	
					if(inputAgain =='y'){ // if the user type 'y'.
						playAgain = 1; // the user will play again.
					} else { // else, the user typed 'n'.
						playAgain = 0; // the user don't want to play again.
						cout << "Goodbye !!"<<endl;
					}
				}
				
		}while(inputAgain != 'y' && inputAgain != 'n'); // ask until the user type y or n.
	}while(playAgain == 1); // ask until the user type yes.

	return 0;
}

/*
	calculate the nth value of fibonacci.
*/
int Fibonacci(int n)
{
	if(n <= 1){ // if the user input is less than or equal to 1.
		return n; //return the value of n.
	}

	return Fibonacci(n-1) +  Fibonacci(n-2); // recursive.
}

/*
	return the user input.
*/
int askNumber()
{
	int number; // will reiceve the user's number.
	do{
	   cout << "Write a number between 0 and 40 !! : ";
	   if(!(cin >> number)){ //if the number is not an integer.
			cout << "Please enter numbers only"<< endl;
			cin.clear(); // we clear the error buffer.
			cin.ignore(1000,'\n'); // ...
	   }else if(number < 1){ // if the number is less to 1.
	   	cout << "The number must be greater than 0 " << endl;	
	   } else if(number > 40){ // is the number is greater to 40.
	   	cout << "The number must be less  than 41" << endl;	
	   }
	}while(number < 1 || number > 40); // while number is not < 1
	
	return number; // return the value of the user.
}
