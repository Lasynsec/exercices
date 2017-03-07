#include <iostream>

using namespace std;

main()
{
	double value1(10);
	double value2(20);
	double value3(30);

	//pointers
	double *choice(nullptr);

	int userInput(0);
	do{
		cout << "Make your choices between 1 and 3 "<<endl;
		if(!(cin>>userInput)){
			cout << "Please enter number only !!!"<< endl;
			cin.clear();
			cin.ignore(1000,'\n');
		} else if(userInput < 1 || userInput > 3){
			cout << "Your number must be between 1 and 3 "<< endl;
		}
	}while(1 > userInput || 3 < userInput);

	switch(userInput){
		case 1:
			choice = &value1;
			break;
		case 2:
			choice = &value2;
			break;
		case 3:
			choice = &value3;
	}

	cout << "Your choice has the value " << *choice <<endl;

	return 0;	
}
