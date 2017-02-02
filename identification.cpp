#include <iostream>
#include <string>

using namespace std;

struct Person { /*Structure type Persons always in the beginig*/
	string name;
	double height;
	int age;
	char sex;
};

//prototypes
Person birth(); // the function generator for persons.
void display(Person const& p); // for displaing things.

// main 
int main(){
	Person aPerson( birth() ); // We create a variable aPerson with the Person type initiated by the function birth. 
	display(aPerson); // we display the content of aPerson instance.
	cout << endl;

	return 0;
}

//Functions definition.
Person birth(){
	Person p; // we create an empty instance of a person.

	cout << "Enter a new person" << endl;
	cout << " Enter a name for the person : ";
	cin >> p.name; // get user input for the name.
	cout <<" Enter the height of the person in meter : ";
	cin >> p.height; // get the user input for the height.
	cout << " Enter the age of the person : ";
	cin >> p.age; // get the user input for the age.
	do{
		cout << " Male [M] or Female [F] : ";
		cin >> p.sex;	// get the user input for the input.
	} while((p.sex != 'F') and (p.sex != 'M')); // if input user is not F and not M ask again.

	return p;
}

void display(Person const& p){
	cout << p.name << ", ";
	switch (p.sex){
		case 'M' : cout << "Male";break;
		case 'F' : cout << "Female";break;
		default  : cout << "alien";break;
	}
	cout << ", "
		<< p.height << "m, "
		<< p.age << " an";
	if(p.age > 1){
		cout << 's';
	}
}
