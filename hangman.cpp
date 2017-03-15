#include <iostream>
#include <string>
#include <vector>

using namespace std;

//struct
struct Player {
	string name;
	int points;
	int hangingStage;
};

//Def
typedef vector<Player> Players;

//Prototypes
void inscription(Players& players,int nbrPlayers);
int askNbrPlayers();
Player playerGenerator();
bool wordMatch(char& word, string& checkInString);

int main(){
	//how many player for the game.
	int nbrOfPlayer = askNbrPlayers();
	// register all players
	Players vec;
	inscription(vec,nbrOfPlayer);

	for(auto player : vec){
		cout << player.name << endl;
	}

	return 0;
}

/*
 * The number of player for the game.
 */
int askNbrPlayers(){
	int nbrPlayers;
	do{
		cout << "Number of players ?";
		if(!(cin>>nbrPlayers)){
			cin.clear();
			cin.ignore(1000,'\n');
			cout << " Number only, please !"<< endl;
		} else if(nbrPlayers<0){
			cout <<"The number must be greater than 0 !"<< endl;
		}
	}while(nbrPlayers<0);

	return nbrPlayers;
}

/*
 * get all players in a vector.
 */
void inscription(Players& vec,int nbrPlayers){
	for(size_t i(0); i < nbrPlayers; ++i){
		vec.push_back(playerGenerator());
	}
}

/*
 * Generate each player.
 */
Player playerGenerator(){
	Player p;

	cout <<"The name of the player : ";
	while(!(cin>>p.name)){
		cout << "Must be a string !!"<<endl;
		cin.clear();
		cin.ignore(1000,'\n');
	}
	p.points = 0;
	p.hangingStage = 0;
	return p;
}
/*
* The Word must match here.
*/
bool wordMatch(char& word, string& checkInString){
	bool isMatched;
	
	//1 - get the input from the user.
	//2 - do a regex search of the letter in the string.
	//3 - put the answer
	return isMatchted;	
	}
