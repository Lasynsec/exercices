#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//struct for player.
struct Player {
	int id;
	string name;
	int points;
	int hangingStage;
	bool eliminated;
};

//Def
typedef vector<Player> Players; // vector with all players.
typedef vector<Player> EliminatedPlayers; // vector with eliminated players.
typedef vector<vector<char>> gallowImages; 
typedef vector<gallowImages> vectorGallows;
typedef vector<char> lettersFounded;


//Prototypes
void inscription(Players& players,int nbrPlayers);	//	player register.
int askNbrPlayers();								//	how many players ?
Player playerGenerator(int& playerNbr);				// create each player.
bool wordMatch(char& playerLetter, string& checkInString);	// check if the word match.										
char aLetter(Player& player, int nbr);						// one player propose a letter.
string giveWord();									// the word to find.
void gameManager(Players& players, vectorGallows& gallowSequence); // the game manager with all players and gallow images.
string lettersToDisplay(char& playerLetter, string& checkInstring,string& wordToShow, Player& player, bool& isFound, vectorGallows& gallowSequence, int& hangingStage);
void displayGallow(gallowImages& images);
void displayGameResults(Players& players); // display the final result.

int main(){

	//The gallow images 
	gallowImages gallowLevelOne(
	 {	 
		 {'_','_','_','_','_','_','_','_'} }
	);
	//gallowImages gallowLeveTwo;
	gallowImages gallowLevelTwo(
	 {	 
		 {' ',' ','|',' ',' ',' ',' ',' '},
		 {'_','/','|','\\','_','_','_','_'} }
	);
	//gallowImages gallowLeveThree;
	gallowImages gallowLevelThree(
	 {	 
		 {' ',' ','|',' ',' ',' ',' ',' '},
		 {' ',' ','|',' ',' ',' ',' ',' '},
		 {'_','/','|','\\','_','_','_','_'} }
	);
	//gallowImages gallowLeveFour;
	gallowImages gallowLevelFour(
	 {	 
		 {' ',' ','|',' ',' ',' ',' ',' '},
		 {' ',' ','|',' ',' ',' ',' ',' '},
		 {' ',' ','|',' ',' ',' ',' ',' '},
		 {' ',' ','|',' ',' ',' ',' ',' '},
		 {'_','/','|','\\','_','_','_','_'} }
	);
	//gallowImages gallowLeveFive;
	gallowImages gallowLevelFive(
	 {	 {' ',' ','_','_','_','_','_',' '},
		 {' ',' ','|',' ',' ',' ',' ',' '},

		 {' ',' ','|',' ',' ',' ',' ',' '},
		 {' ',' ','|',' ',' ',' ',' ',' '},
		 {' ',' ','|',' ',' ',' ',' ',' '},
		 {'_','/','|','\\','_','_','_','_'} }
	);
	//gallowImages gallowLeveSix;
	gallowImages gallowLevelSix(
	 {	 {' ',' ','_','_','_','_','_',' '},
		 {' ',' ','|','/',' ',' ',' ',' '},
		 {' ',' ','|',' ',' ',' ',' ',' '},
		 {' ',' ','|',' ',' ',' ',' ',' '},
		 {' ',' ','|',' ',' ',' ',' ',' '},
		 {'_','/','|','\\','_','_','_','_'} }
	);
	//gallowImages gallowLeveSept;
	//vector<Player>::iterator searchIt;
	gallowImages gallowLevelSeven(
	 {	 {' ',' ','_','_','_','_','_',' '},
		 {' ',' ','|','/',' ','|',' ',' '},
		 {' ',' ','|',' ',' ',' ',' ',' '},
		 {' ',' ','|',' ',' ',' ',' ',' '},
		 {' ',' ','|',' ',' ',' ',' ',' '},
		 {'_','/','|','\\','_','_','_','_'} }
	);
	//gallowImages gallowLeveEight;
	gallowImages gallowLevelEight(
	 {	 {' ',' ','_','_','_','_','_',' '},
		 {' ',' ','|','/',' ','|',' ',' '},
		 {' ',' ','|',' ','_','0','_',' '},
		 {' ',' ','|',' ',' ',' ',' ',' '},
		 {' ',' ','|',' ',' ',' ',' ',' '},
		 {'_','/','|','\\','_','_','_','_'}}
	);
	//gallowImages gallowLeveNine;
	gallowImages gallowLevelNine(
	 {	 {' ',' ','_','_','_','_','_',' '},
		 {' ',' ','|','/',' ','|',' ',' '},
		 {' ',' ','|',' ','_','0','_',' '},
		 {' ',' ','|',' ',' ','|',' ',' '},
		 {' ',' ','|',' ',' ',' ',' ',' '},
		 {'_','/','|','\\','_','_','_','_'}}
	);
	//gallowImages gallowLeveTen;
	gallowImages gallowLevelTen(
	 {	 {' ',' ','_','_','_','_','_',' '},
		 {' ',' ','|','/',' ','|',' ',' '},
		 {' ',' ','|',' ','_','0','_',' '},
		 {' ',' ','|',' ',' ','|',' ',' '},
		 {' ',' ','|',' ','/',' ','\\',' '},
		 {'_','/','|','\\','_','_','_','_'}}
	);

    vectorGallows gallowSequence({gallowLevelOne, gallowLevelTwo, gallowLevelThree, gallowLevelFour, gallowLevelFive, gallowLevelSix, gallowLevelSeven, gallowLevelEight, gallowLevelNine, gallowLevelTen});

	string theWord;
	//how many player for the game.
		//int nbrOfPlayer(askNbrPlayers());-------------------delete the comment after testing.
	// register all players for the game.
		//Players vec;-------------------------delete the comment after testing.
		//inscription(vec,nbrOfPlayer);-------delte the comment after testing.
	Players vec = { //---------delete the structure after testing. 
		{1,"Jordan",0,0,false},
		{2,"Marc",0,0,false},
		{3,"Jenna",0,0,false},
		{4,"Anna",0,0,false}
	};
	
	//The game
	gameManager(vec,gallowSequence); 
	
	// The game is over.
	cout<<"The game is over !\n";
	cout <<"results :\n";
	
	displayGameResults(vec);
	return 0;
}


/*
 * The number of player for the game.
 */
int askNbrPlayers(){
	bool isNumber;
	int nbrPlayers(0);

		cin.ignore();
	do{
		cout << "Number of players ? : ";
		if(!(cin>>nbrPlayers)){
			cin.clear();
			cin.ignore(1000,'\n');
			cout << "-Number only, please !"<< endl;
			isNumber = false;
		} else if(nbrPlayers<0){
	//vector<Player>::iterator searchIt;
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
	p.id = playerNbr;
	cout <<"The name of the player " << playerNbr << " : ";
	while(!(cin>>p.name)){
		cout << "Must be a string !!"<<endl;
		cin.clear();
		cin.ignore(1000,'\n');
	}
	p.points = 0;
	p.hangingStage = 0;
	p.eliminated = false;

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
	cout <<"Player"<< " ( "<<  player.id<<" ) "<<player.name <<" type a letter : ";
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
		//cin.ignore(); ----------------Delete the comment after testing.
		getline(cin,aWord);
		wordSize = aWord.length(); 

		if(wordSize < 2){
			cout <<"The length of your word must be greater than 1 !"<<endl;
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
void gameManager(Players& players, vectorGallows& gallowSequence){
	string wordToFind;
	string displayLetters;
	int nbr;
	char letterFromPlayer;
	bool isFound(false); // the word has been found o not.
	bool isEliminated(false); // the player is eliminated;
	int hangingStage(0); // the hanging level.i
	int nbrEliminated(0);
	int showNbrEliminated(0);
	EliminatedPlayers eliPlayers; // vector of eliminated players
	lettersFounded lettersVec; // for the founded letters.


	for(size_t i(0); i < players.size(); ++i){
		cout <<"The player" << " ( "<< players[i].id<< " ) "<< players[i].name << " must write a word. \n";
		cout <<"Others players, please don't look at the word, written by "<< players[i].name<<". \n";
		wordToFind = giveWord();
		cout << wordToFind<<endl;
		cout << "<Clear the screen !>"<<endl;
		//cout << string(80,'\n');----delete the comment after testing.
		string wordToShow(wordToFind.length(),'_'); // for the letterToDisplay function.
		cout <<"You have to find the word : "<<wordToShow<<endl;
		//loop here until the end of a play.
		while(isFound != true)
		{
			for(size_t j(0); j < players.size(); ++j){
				if(players[i].name == players[j].name){// if the player that guess is the same than the player that propose the word.
					continue;
				}else {
					if(players[j].eliminated == true){ //if the player is eliminated.
						int ID = players[j].id;
						auto searchIt = find_if(begin(eliPlayers), end(eliPlayers), [=] (Player const& p){
							return (p.id == ID);
						});
						if(searchIt != end(eliPlayers)){
							cout <<"Already hanged"<<endl;
						}else{
							eliPlayers.push_back(players[j]);
						}
						cout << "The player "<< players[j].name<<" can't play, he is eliminated !\n";
					}else{
						nbr = j;

						letterFromPlayer = aLetter(players[j],nbr); // the player give a letter.
						auto foundedLetter = find(begin(lettersVec), end(lettersVec), letterFromPlayer);
						if(foundedLetter != end(lettersVec)){ // the letter has already been typed.
							cout << "Sorry but this letter has already been typed !\n";
							displayGallow(gallowSequence[players[j].hangingStage]);
							++players[j].hangingStage;

							if(players[j].hangingStage >= gallowSequence.size()){
								players[j].eliminated = true; // the player is eliminated.
								cout << "Player " << players[j].name << " is eliminated "<<endl;
							}		
						} else {
							lettersVec.push_back(letterFromPlayer);
							displayLetters = lettersToDisplay(letterFromPlayer,wordToFind,wordToShow,players[j],isFound, gallowSequence, hangingStage);// the word is displaying on the screen.
						}

						if(isFound == true){
							break;
						}
						cout << "The word to find is : "<<displayLetters << endl;
					}
				}
				if( eliPlayers.size() >= players.size()-1){
					isFound = true;
				}
			}
		cout << "isFound is "<<isFound << endl;
		}
		cin.ignore();//-------------------------//delete cin after test.
		isFound = false;
		cout << endl;
		if(eliPlayers.size() >= players.size()-1){
			break;
		}
		//break;
	}		
}
 string lettersToDisplay(char& playerLetter, string& checkInstring, string& wordToShow, Player& player, bool& isFound, vectorGallows& gallowSequence, int& hangingStage){
	bool isMatched(wordMatch(playerLetter, checkInstring));
	string replaceLetter;
	string wordToReturn;
	
	if(isMatched){
		cout <<"Well done "<< player.name<<", you're well on your way."<<endl;
		for(size_t i(0); i < checkInstring.length(); ++i){
			if(checkInstring[i] == playerLetter){
				replaceLetter = checkInstring[i];
				wordToShow.replace(i,1,replaceLetter);
			}
		}
	} else {
		cout <<"Sorry "<<player.name<<" but the letter doesn't match !"<<endl;
		displayGallow(gallowSequence[player.hangingStage]);
		++player.hangingStage;

		if(player.hangingStage >= gallowSequence.size()){
			player.eliminated = true; // the player is eliminated.
			cout << "Player " << player.name << " is eliminated "<<endl;
		}
	}

	//  If the two words are the same.
	if(checkInstring == wordToShow){
		cout << "Good job "<< player.name<<" , you've found the word"<<endl;
		isFound = true;
	}
	
	wordToReturn = wordToShow;
	return wordToReturn;
}

/**
 * that manage the gallow. 
 */
void displayGallow(gallowImages& images){
	for(auto row : images){
		for(auto content : row){
			cout << content << "";
		}
		cout << '\n';
	}
}

void displayGameResults(Players& players){
	string message;
	for(auto player : players){
		if(player.eliminated == true){
			message = " is hanged, ";
		} else{
			message = " is still alive, ";
		}

		cout << player.name << message <<" with " << player.points << " points "<< endl;
	}
}
