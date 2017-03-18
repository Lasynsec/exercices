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
void inscription(Players& players,int nbrPlayers);	//	player register.
int askNbrPlayers();								//	how many players ?
Player playerGenerator();							// create each player.
bool wordMatch(char& playerLetter, string& checkInString);	// check if the word match.
char aLetter();										// the player give a letter.
string giveWord();									// the word to find.
void gameManager(Players& players);					// the game manager.

int main(){
	//how many player for the game.
	int nbrOfPlayer = askNbrPlayers();
	// register all players for the game.
	Players vec;
	inscription(vec,nbrOfPlayer);

	/** Test for the players
	for(auto player : vec){
		cout << player.name << endl;
	}*/

	//ask the word.	
	string wordToFind;
	wordToFind = giveWord();
	cout <<"You have to find the word : "<< wordToFind << endl;

	char letterFromPlayer;
	letterFromPlayer = aLetter();
	cout << "You type the letter : "<< letterFromPlayer<<endl;

	bool itMatchOrNot;
	itMatchOrNot = wordMatch(letterFromPlayer, wordToFind);

	string yesOrNot;
	string* response = &yesOrNot;

	if(itMatchOrNot == true){
		*response ="Well done, the letter is correct !";
	} else {
		*response = "Sorry, but the letter doesn't match !";
	}

	cout << *response <<endl;
	return 0;
}

/*
 * The number of player for the game.
 */
int askNbrPlayers(){
	int nbrPlayers;
	do{
		cout << "Number of players ? : ";
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
 * Creat players.
 */
Player playerGenerator(){
	Player p;
	int playerNbr(1);
	int *ptr;

	ptr = &playerNbr;

	cout <<"The name of the player " << *ptr << " : ";
	while(!(cin>>p.name)){
		cout << "Must be a string !!"<<endl;
		cin.clear();
		cin.ignore(1000,'\n');
	}
	p.points = 0;
	p.hangingStage = 0;
	(*ptr)++;

	return p;
}
/*
* The Word must match here.
*/
bool wordMatch(char& playerLetter, string& checkInString){
	bool isMatched;
		if(checkInString.find(playerLetter) != -1){
			isMatched = true;
		}else{
			isMatched = false;
		}
	return isMatched;	
	}

/*
 * The player must write a letter.
 */
char aLetter(){
	char theWord;
	cout <<"Type a letter : ";
	while(!(cin>>theWord)){
		cin.clear();
		cin.ignore(1000,'\n');
	}

	return theWord;
}

/*
 * The word to find.
 */
string giveWord(){
	string aWord;
	
	cout << "Write the word to find : ";
	while(!(cin>>aWord)){
		cin.clear();
		cin.ignore(1000,'\n');
	}
	return aWord;
}

/*
 * The game manager
void gameManager(Players& players){
	for(size_t i(0); i < players.size(); ++i){
		
	}		
}
*/
