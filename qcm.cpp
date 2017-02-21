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

//Typedef
typedef vector<Qcm> Exam; // A new type Exam that contain qcm elements.

//Prototypes
void displayExam(Exam const& exam);
int askNumber(int min, int max);
Qcm askQuestions();
Exam examCreator();


int main(){
	Exam theExam;

	theExam = examCreator();
	displayExam(theExam);

	return 0;
}

/*
 * Display the questions
 */
void displayExam(Exam const& exam){
	cout << "Multiple Choice Questions" << endl;
	int userInput(0);
	for(size_t i(0); i < exam.size(); ++i){
		cout << exam[i].question<< endl;
		
		for(size_t j(0); j < exam[i].answers.size(); ++j){
			cout << j+1 <<"-"<< exam[i].answers[j] << endl;
		}
		askNumber(1,exam[i].answers.size());
	}
}

/*
 * Ask for the right answer to the user.
 */
int askNumber(int min, int max){
	int userInput;
	do{
		cout << "Enter a number between "<< min << " and " << max << " : ";
		if(!(cin>>userInput)){
			cout << "Please enter numbers only !"<< endl;
			cin.clear();
			cin.ignore(1000,'\n');
		} else if(userInput < min || userInput > max){
			cout <<"Your number must be between " << min << " and "<< max << endl;
		}
	}while((min > userInput) || (max < userInput));

	return userInput;
}

/*
 * Ask the questions to the users.
 */
Qcm askQuestions(){
	Qcm qcm;
	cin.ignore();
	getline(cin,qcm.question);
	
	cout<<"- How many answers the users will have ? : ";
	int nbr_questions;
	while(!(cin>>nbr_questions)){
		cout << "- Please enter numbers only !!! : ";
		cin.clear();
		cin.ignore();
	}
	
	string actualValue;
	cin.ignore();
	for(size_t i(0); i < nbr_questions; ++i){
		cout << "- Enter the answer number "<< i+1 <<" : ";
		getline(cin,actualValue);
		qcm.answers.push_back(actualValue);
			
	}
	
	cout << "- The solution for this question is number : ";
	int solution;
	cin >> qcm.solution;

	return qcm;
}


/*
 * Create the exam
 */
Exam examCreator(){
	cout << "How many questions will the exam have (write at least 2 questions)? : ";
	int nbrQuestions;
	cin >> nbrQuestions;
	Exam anExam(nbrQuestions);

	for(size_t i(0); i < anExam.size(); ++i){
		cout << "Write the question number  " << i+1 << " : ";
		anExam[i]=askQuestions();
		cout << endl;
	}

	return anExam;
}

