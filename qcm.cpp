#include <iostream>
#include <string>
#include <vector>

using namespace std;

//struct
struct Qcm{
	string question;
	vector<string> answers;
	int solution;
};

//Prototypes
void display(Qcm const& qcm);
int askNumber(int min, int max);
int askQuestions(Qcm& qcm);

int main(){
	Qcm qcm;	
	
	askQuestions(qcm);

	return 0;
}

/*
 * Display the questions
 */
void display(Qcm const& qcm){
	cout << qcm.question<< endl;

	for(auto row : qcm.answers){
		cout <<" -" << row << endl;
	}
}

/*
 * Ask for the answer to the user.
 */
int askNumber(int min, int max){
	int userInput;
	do{
		cout << "Enter a number between "<< min << " and " << max << endl;
		if(!(cin>>userInput)){
			cout << "Please enter numbers only !"<< endl;
			cin.clear();
			cin.ignore(1000,'\n');
		} else if(userInput < min || userInput > max){
			cout <<"Your number must be beetwen " << min << " and "<< max << endl;
		}
	}while((min > userInput) || (max < userInput));

	return userInput;
}
	
int askQuestions(Qcm& qcm){
	cout<<"Write the question."<<endl;
	getline(cin,qcm.question);
	
	cout<<"How many answers the users will have ? "<<endl;
	int nbr_questions;
	while(!(cin>>nbr_questions)){
		cout << "Please enter numbers only !!!"<< endl;
		cin.clear();
		cin.ignore();
	}
	
	string actualValue;
	for(size_t i(0); i < nbr_questions; ++i){
		cout << "Enter the answer number "<< i <<" : ";
		cin.ignore();
		getline(cin,actualValue);
		qcm.answers.push_back(actualValue);
		
	}
	cout << endl;
	
	display(qcm);
	
	int userInput(0);
	userInput = askNumber(1,qcm.answers.size());

	return userInput;
}
