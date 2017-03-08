#include <iostream>
#include <vector>
#include <set>

using namespace std;

//Structures
struct Team
{
	string name;
	int points;
	int goalsFor;
	int goalsAgainst;
	int goalDifference;
};

//Def
typedef vector<Team> Teams;

//Prototypes
int askGoals();
void insertScores(Team& nbrone, Team& nbrtwo);
void displayResult(Teams const& teams);


int main(){
	
	// instantiate
	Team switzerland = {"Switzerland",0,0,0,0}; // instantiate switzerland. 
	Team croatia = {"Croatia",0,0,0,0}; // instantiate croatia.
	Team france = {"France",0,0,0,0}; // instantiaite france.
	Team england = {"England",0,0,0,0}; // instantiate england.
	
	// insert scores
	//insertScores(switzerland,croatia);
	insertScores(france,england);
	insertScores(switzerland,england);
	//insertScores(france,croatia);
	insertScores(england,croatia);
	//insertScores(switzerland,france);

	Teams teams;
	//teams.push_back(croatia);
	teams.push_back(england);
	//teams.push_back(france);
	//teams.push_back(switzerland);
	
	cout << endl;
	cout <<"Results \n" ;
	displayResult(teams);
	return 0;
}

int askGoals(){
	int nbrGoal;
	
	do{
		if(!(cin>>nbrGoal)){
			cout << "Please enter numbers only !"<< endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}else if(nbrGoal < 0){
			cout << "The number must be equal or greater than 0.";
		}
	}while(nbrGoal<0);

	return nbrGoal;
}

void insertScores(Team& nbrone, Team& nbrtwo){
	if(){
	}
	cout << " - " <<nbrone.name <<" vs "<<nbrtwo.name<< ": \n"; 
	cout << nbrone.name<<" -> ";
	nbrone.goalsFor += askGoals();
	cout << nbrtwo.name<<" -> ";
	nbrtwo.goalsFor += askGoals();
	

	int goalsOne, goalsTwo;
	goalsOne = nbrone.goalsFor;
	goalsTwo = nbrtwo.goalsFor;

	 if(nbrone.goalsFor > nbrtwo.goalsFor){
		 nbrone.points += 3;
	 } else if(nbrone.goalsFor == nbrtwo.goalsFor){
		nbrone.points += 1;
		nbrtwo.points += 1;
	 } else {
		 nbrtwo.points += 3;
	 }
	nbrone.goalsAgainst += nbrtwo.goalsFor;
	nbrtwo.goalsAgainst += nbrone.goalsFor;

	nbrone.goalDifference += nbrone.goalsFor - nbrone.goalsAgainst;
	nbrtwo.goalDifference += nbrtwo.goalsFor - nbrtwo.goalsAgainst;
	
}


void displayResult(Teams const& teams){
	for(auto team : teams){
	cout << team.name <<" : "<<team.points <<" points, "<<team.goalsFor<<" goals for, "<<team.goalsAgainst<<" goals against, "<<team.goalDifference<<" goal difference"<<endl;
	}
}

