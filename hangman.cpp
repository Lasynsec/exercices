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
Player playerGenerator(int& playerNbr);				// create each player.
bool wordMatch(char& playerLetter, string& checkInString);	// check if the word match.										
char aLetter(Player& player, int nbr);						// one player propose a letter.
string giveWord();									// the word to find.
void gameManager(Players& players);					// the game manager.
string lettersToDisplay(char& playerLetter, string& checkInstring,string& wordToShow, Player& player);

int main(){
	string theWord;
	//how many player for the game.
	int nbrOfPlayer(askNbrPlayers());
	// register all players for the game.
	Players vec;
	inscription(vec,nbrOfPlayer);

	/** Test : list the players
	for(auto player : vec){
		cout << player.name << endl;
	}*/

	//The game
	gameManager(vec);
/*



*/
	return 0;
}


/*
 * The number of player for the game.
 */
int askNbrPlayers(){
	bool isNumber;
	int nbrPlayers(0);

	do{
		cout << "Number of players ? : ";
		if(!(cin>>nbrPlayers)){
			cin.clear();
			cin.ignore(1000,'\n');
			cout << "-Number only, please !"<< endl;
			isNumber = false;
		} else if(nbrPlayers<0){
			cout <<"The number must be greater than 0 !"<<endl;
		} else {
			isNumber = true;
		}
	}while((nbrPlayers < 0) || (isNumber != true));

	return nbrPlayers;
}

/*
 * get all players in a vector.
 */
void inscription(Players& vec,int nbrPlayers){
	int playerNbr;

	for(size_t i(0); i < nbrPlayers; ++i){
		playerNbr = i+1;
		vec.push_back(playerGenerator(playerNbr));
	}
}

/*
 * Creat players.
 */
Player playerGenerator(int& playerNbr){
	Player p;

	cout <<"The name of the player " << playerNbr << " : ";

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
char aLetter(Player& player, int nbr){
	char theWord;
	cout <<"Player"<< " ("<< nbr+1 <<") "<<player.name <<" type a letter : ";
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
	int wordSize;
	bool wordCheck;

	do{
		cout << "Write the word to find : ";
		cin.ignore();
		getline(cin,aWord);
		wordSize = aWord.length(); 

		if(wordSize < 1){
			cout <<"You have to type something !"<<endl;
			wordCheck = false;
			cin.clear();
		}else {
			wordCheck = true;
		}
	}while(wordCheck != true);

	return aWord;
}

/*
 * The game manager*/
void gameManager(Players& players){
	string wordToFind;
	string displayLetters;
	int nbr;
	char letterFromPlayer;
	//string wordToShow;// for the letterToDisplay function.

	for(size_t i(0); i < players.size(); ++i){
		cout <<"The player"<<" ("<< i+1 <<") " << players[i].name << " must write a word. \n";
		cout <<"Others players, please don't look at the word, written by "<< players[i].name<<". \n";

		wordToFind = giveWord();
		cout << "<Clear the screen !>"<<endl;
		
		string wordToShow(wordToFind.length(),'_'); // for the letterToDisplay function.
		cout <<"You have to find the word : "<< wordToShow << endl;

		for(size_t j(0); j < players.size(); ++j){
			if(players[i].name == players[j].name){
				continue;
			}else {
				nbr = j;
				letterFromPlayer = aLetter(players[j],nbr);
				displayLetters = lettersToDisplay(letterFromPlayer,wordToFind,wordToShow,players[j]);
				cout << "The word to find is : "<<displayLetters << endl;
			}
		}

		//to delete
		break;
	}		
}

 string lettersToDisplay(char& playerLetter, string& checkInstring, string& wordToShow, Player& player){
	bool isMatched(wordMatch(playerLetter, checkInstring));
	string replaceLetter;
	string wordToReturn;
	
	if(isMatched){
		cout <<"Well done, you are on the right way."<<endl;
		for(size_t i(0); i < checkInstring.length(); ++i){
			if(checkInstring[i] == playerLetter){
				replaceLetter = checkInstring[i];
				wordToShow.replace(i,1,replaceLetter);
			}
		}
	} else {
		cout <<"Sorry but the letter doesn't match !"<<endl;
		player.hangingStage++; 
	}
	
	wordToReturn = wordToShow;
	return wordToReturn;
}
