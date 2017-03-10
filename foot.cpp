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
void displayClassification(Teams const& teams);
bool bestTeam(Team const& teamOne, Team const& teamTwo);
void classification(Teams& teams);
void exchange(Team& teamOne, Team& teamTwo);


int main(){
	
	// instantiate
	Team switzerland = {"Switzerland",0,0,0,0}; // instantiate switzerland. 
	Team croatia = {"Croatia",0,0,0,0}; // instantiate croatia.
	Team france = {"France",0,0,0,0}; // instantiaite france.
	Team england = {"England",0,0,0,0}; // instantiate england.

	// insert scores
	insertScores(switzerland,croatia);
	insertScores(france,england);
	insertScores(switzerland,england);
	insertScores(france,croatia);
	insertScores(england,croatia);
	insertScores(switzerland,france);

	Teams teams;
	teams.push_back(croatia);
	teams.push_back(england);
	teams.push_back(france);
	teams.push_back(switzerland);

	cout << endl;
	cout <<"Results \n" ;
	displayResult(teams);
	cout << endl;
	classification(teams);
	displayClassification(teams);

	return 0;
}

int askGoals(){/*ok*/
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

void insertScores(Team& nbrone, Team& nbrtwo){/*ok*/
	int matchScoreTeamOne, matchScoreTeamTwo;
	cout << " - " <<nbrone.name <<" vs "<<nbrtwo.name<< ": \n"; 
	cout << nbrone.name<<" -> ";
	matchScoreTeamOne = askGoals();
	cout << nbrtwo.name<<" -> ";
	matchScoreTeamTwo = askGoals();

	 if( matchScoreTeamOne > matchScoreTeamTwo){
		 nbrone.points += 3;
	 } else if(matchScoreTeamOne == matchScoreTeamTwo){
		nbrone.points += 1;
		nbrtwo.points += 1;
	 } else {
		 nbrtwo.points += 3;
	 }

	nbrone.goalsFor += matchScoreTeamOne; 
	nbrtwo.goalsFor += matchScoreTeamTwo;

	nbrone.goalsAgainst += matchScoreTeamTwo;
	nbrtwo.goalsAgainst += matchScoreTeamOne;
}


void displayResult(Teams const& teams){/*ok*/
	for(auto team : teams){
		team.goalDifference = team.goalsFor - team.goalsAgainst;
		cout << team.name <<" : "<<team.points <<" points, "<<team.goalsFor<<" goals for, "<<team.goalsAgainst<<" goals against, "<<team.goalDifference<<" goal difference"<<endl; 
	}
}
/*To test*/
bool bestTeam(Team const& teamOne, Team const& teamTwo){
	bool isBest;
	string userIput;
	if(teamOne.points == teamTwo.points){
		if(teamOne.goalsFor == teamTwo.goalsFor){
			cout << "Choose the best team between both of them\n";
			cout <<" - type 1 for "<< teamOne.name <<"\n";
			cout <<" - type 2 for "<< teamTwo.name <<"\n";
			int userInput(0);
			do {
				if(!(cin>>userInput)){
					cout <<"Enter numbers only"<<endl;
					cin.clear();
					cin.ignore(1000,'\n');
				} else if(userInput < 1 || userInput > 2){
					cout <<"Your number is not in the resquested range !! "<< endl;
				}
			}while(userInput < 1 || userInput > 2);

			if(userInput == 1){
				cout <<"The best is ?" << endl;	
			}
		} else if(teamOne.goalsFor > teamTwo.goalsFor){
			isBest = true;	
		}else {
			isBest = false;
		}
	}else if(teamOne.points > teamTwo.points){
		isBest = true;
	} else {
		isBest = false;
	}
	return isBest;
}
/*Keep working on it!!*/
void classification(Teams& teams){
	for(size_t i(0); i < 2; ++i){
		for(size_t j(3); j > i;--j){
		//cout << teams[j].name << " against " <<teams[j-1].name<<"-> ";
			if(bestTeam(teams[j],teams[j-1]) == true){
				exchange(teams[j],teams[j-1]);
			}
		}
	}
}

void exchange(Team& teamOne, Team& teamTwo){/*ok*/
	Team temp;
	//cout << teamOne.name<<": points = " << teamOne.points <<" <->"<< teamTwo.name <<": points =  " << teamTwo.points <<endl;
	temp.points			 = teamOne.points; 
	temp.goalsFor	     = teamOne.goalsFor;
	temp.goalsAgainst	 = teamOne.goalsAgainst;
	temp.goalDifference = teamOne.goalDifference;
	temp.name			 = teamOne.name;

	teamOne.points			= teamTwo.points;
	teamOne.goalsFor	    = teamTwo.goalsFor;
	teamOne.goalsAgainst	= teamTwo.goalsAgainst;
	teamOne.goalDifference  = teamTwo.goalDifference;
	teamOne.name			= teamTwo.name;

	teamTwo.points			= temp.points;
	teamTwo.goalsFor	    = temp.goalsFor;
	teamTwo.goalsAgainst	= temp.goalsAgainst;
	teamTwo.goalDifference  = temp.goalDifference;
	teamTwo.name			= temp.name;
}


void displayClassification(Teams const& teams){
	cout << "Final Classification :" << endl;
	for(size_t team(0); team < teams.size(); ++team){
		cout << team+1 << " : "<< teams[team].name << endl;
	}
}
