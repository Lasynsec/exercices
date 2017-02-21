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
Qcm askQuestions();
Qcm testQuestions();
int examCreator();

//Typedef
typedef vector<Qcm> Exam; // A new type Exam that contain qcm elements.

int main(){
	examCreator();
	
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

/*
 * Ask the questions to the users.
 */
Qcm askQuestions(){
	Qcm qcm;
	cout<<"Write the question."<<endl;
	cin.ignore();
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
	
	//display(qcm);
	
	//int userInput(0);
	//userInput = askNumber(1,qcm.answers.size());

	return qcm;
}


/*
 * Create the exam
 */
int examCreator(){
	cout << "How many questions will the exam have ? "<< endl;
	int nbrQuestions;
	cin >> nbrQuestions;
	cout << "The number of question is "<<nbrQuestions << endl;	
	Exam anExam(nbrQuestions);
	
	cout << "Vector size "<< anExam.size()<<endl;
	for(size_t i(0); i < anExam.size(); ++i){
		//cout << "Write the question number  " << i+1 << endl;
		anExam[i]=askQuestions();
	
		cout << " la question est "<< anExam[i].question << endl;
	}
}

