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

