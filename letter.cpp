#include <iostream>
#include <string>

using namespace std;

//prototype
void lettersGenerator(string name, string subject, string date);

int main(){
	
	lettersGenerator("Jhon"," last course","18/12");	
	return 0;
}

void lettersGenerator(string name, string subject, string date){
	string letter;
	cout << "Good morning deer " << name <<endl;
	cout << "I\'m writing concerning your "<< subject << endl;
	cout << "We should meet up on " << date << " to talk about it" << endl;
	cout << "I'm looking forward to hear about you!"<<endl;
	cout << "Kindest regards, Herve"<<endl;
}
