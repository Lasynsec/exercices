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
	Qcm qcm = {"How many theeth does an elephant have ?",{"32", "from 6 to 10","to many","24","2"},2};	
	display(qcm);

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

int askNumber(int min, int max){
	int userInput;
	do{
		cout << "Enter a number between "<< min << " and " << max << "endl;
		if(!(cin>>userInput)){
			cout << "Please enter numbers only !"<< endl;
			cin.clear();
			cin.ignore(1000,'\n');
		} else if(userInput < min || userInput > max){
			cout <<"Your answer is not in the answers listed below." << endl;
		}
	}while((min > userInput) || (max < userInput));

	return userInput;
}
	
int askQuestions(Qcm& qcm){
	cout << " Write the question."<<endl;
	cin<<qcm.question;

}
