#include <iostream>
#include <string>

using namespace std;

//Structures
struct House {
	string address;
};

struct Person{
	string name;
	string house;
};

//prototypes
Person personGenerator(string name,House& house);
void DisplayIt(Person& person);

main(){
	
	House london = {"10 Downing Street SW1A 2AA"};
	House newYork = {"228 Park Avenue S, NY 10003"};

	Person jack(personGenerator("Jack",newYork));
	jack.house = london.address;
	Person jenny(personGenerator("Jenny",london));


	DisplayIt(jack);
	DisplayIt(jenny);

	return 0;
}


Person personGenerator(string name,House& home){
	Person person;

	person.name = name;
	person.house = home.address;

	return person;

}

void DisplayIt(const Person& person){
	cout << person.name << "'s address is "<< person.house << endl;
}

