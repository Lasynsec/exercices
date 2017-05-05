#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Enum: color for each disk.
enum Color {empty, red, yellow};

//Structure
struct Player{
	int id;
	string name;
	bool hasWon;
	Color disk;
};


/*Typdef*/
typedef array<array<Color,7>,6> Grid;
typedef vector<Player> Players;
typedef vector<char> colorsDisk;
typedef array <int,2> Positions;

/*Prototypes*/
void display(const Grid& grid);
void initialisation(Grid& grid);
Player playerGenerator(int &id, colorsDisk& colorsVec);
void playersRegistration(Players& player);
bool checkDuplicateDisk(char color, colorsDisk& colorVec);
void askPosition(Grid& grid, Player& player);
int askNumber(bool isVertical);
void connectFour(Players& players, Grid& grid);
bool isEmpty(Grid& grid, Positions& positions);

int main(){
	/*Grid initialisation*/
	Grid grid;				// create the grid.
	initialisation(grid);	// initialise the grid.
	
	/*Players registration*/
	//Players players; //------------------------------------// get rid of the comment after testing.
	Players players = {{1,"emma",false,red},{2,"jenna",false,yellow}}; // remove the line after testing.

	//playersRegistration(players); //save the players.---------------------// get rid of the comment after testing.
	
	/*Play the game*/
	connectFour(players, grid);
	//grid[2][3] = red;

	/*Display the game*/
	//display(grid);

	return 0;
}

// diplay 0 for a red case, X pour a yellow case.
/**
 * Display the grid on screen.
 * @param: the array of the grid.
 */
void display(const Grid& grid){
	cout << endl;
	for(auto row: grid){
		cout << " |";
		for(auto kase : row){
			if(kase == empty){
				cout << ' ';
			} else if(kase == red){
				cout << 'O';
			} else {
				cout << 'X';
			}
			cout << '|';
		}
		cout << endl;
	}

	cout << '=';
	for(size_t i(1); i <= grid[0].size(); ++i){
		cout << '='<<i;
	}
	cout << "==";
	cout << endl << endl;
	bool isNotAvailable = false;
}
/**
 * Initiate the grid case to empty.
 * @param: the grid to initiate.
*/ 
void initialisation(Grid& grid){
	for(auto &row : grid){
		for(auto &kase : row){
			kase = empty;
		}
	}
}



/**
 * Generate each players
 * @param: the id of the player.
 * @return: return the player.
 */
Player playerGenerator(int id, colorsDisk& colorsVec){
	Player p;
	p.id = id;
	cout << "Player ("<< p.id << "), please type your name : "; 
	cin>>p.name;
	p.hasWon = false;
	char colorDisk; // the color of the disk(y or r);
	bool isAvailable; // if he can choose the disk color.

	do{
		cout << "->Choose the color of your disk.\n";
		cout << "->Type (r) for the red disk or (y) for the yellow disque : ";
		cin>>colorDisk;
		if(colorDisk != 'r' && colorDisk != 'y'){
			cout <<"->Please type only (r) or (y) !"<<endl;
		}else{
				isAvailable = checkDuplicateDisk(colorDisk, colorsVec);
				if(isAvailable){
					if(colorDisk == 'r'){
						p.disk = red;
					} else {
						p.disk = yellow;
					}
				}else{
					cout <<"Sorry, but this color has already been chosen. Please choose the other color."<<endl;
				}
		}
	}while((colorDisk != 'r' && colorDisk != 'y') || isAvailable != true);
	
	if(colorDisk == 'r'){
		p.disk = red;
	}else{
		p.disk = yellow;
	}

	return p;
}

/**
 * Registration of both players
 * @param: The Players vector.
 */
void playersRegistration(Players& players){
	colorsDisk colorsVec;
	for(size_t i(0); i < 2; i++){
		players.push_back(playerGenerator(i+1, colorsVec));
		cout << endl;

	}
}

/**
 * Check if the same color is chosen twice.
 * @param: a disk to check for.
 * @return: return the color disk.
 */
bool checkDuplicateDisk(char color, colorsDisk& colorVec){
	bool isNotAvailable;
	auto isDuplicate = find(begin(colorVec), end(colorVec), color);
	if(isDuplicate != end(colorVec)){ //the color already exist.
		isNotAvailable = false;
	} else {
		colorVec.push_back(color);
		isNotAvailable = true;
	}

	return isNotAvailable;
}

/**
 * Ask the disk position to the players.
 * @param: the grid to modiy.
 * @param: the player that will play.
 */
void askPosition(Grid& grid, Player& player){
	int horizontal; // for the player vertical position.
	int vertical; // for the player horizontal position.
	Positions positions;
	bool isempty;

	do{
		cout << "Player "<< "("<<player.id <<") "<< player.name <<": " << "\n";
		cout <<" - type the horizontal position of your new disk:";
		horizontal = askNumber(false);
		cout <<" - type the vertical position of your new disk:";
		vertical = askNumber(true);
		
		positions[0] = vertical;
		positions[1] = horizontal;
	
		isempty = isEmpty(grid,positions);

		if(isempty){
			grid[vertical-1][horizontal-1] = player.disk;
		} else {
			cout << endl;
			cout <<"*Sorry but you cannot put a disk here !"<< endl;
		}
	}while(isempty != true);
}

/**
 * Ask a number to the players.
 * @return: return the number typed by the player.
 */
int askNumber(bool isVertical){
	int numberToSend;
	bool isCorrect;

	do{
		isCorrect = true;
		if(!(cin>>numberToSend)){
			cin.clear();
			cin.ignore(1000,'\n');
			cout <<"Number only please ! :";
			isCorrect  = false;
		} else {
			if(numberToSend < 1){
				cout <<"The number must be greater than 0 :";
				isCorrect  = false;
			} else if(numberToSend > 7){
				cout <<"The number must be under 8 :";
				isCorrect  = false;
			}else{ 
				if(numberToSend > 6){
					if(isVertical == true){	
						cout <<"The number must be under 7 :";
						isCorrect  = false;
					}
				}
			}
		}

	}while(isCorrect != true );

	return numberToSend;
}

/**
 * Will handle the game.
 */
void connectFour(Players& players, Grid& grid){
	cout << "WELCOME TO CONNECTOR 4 !"<<endl;
	for(auto player : players){
		askPosition(grid, player);//place the disk in the grid.
		display(grid); // display the grid.
	}
}

/**
 * Check if the input position is not empty.
 * @param: the grid.
 * @param: the player positions in the multi array.
 * @return: the boolean value.
 */
bool isEmpty(Grid& grid, Positions& positions){
	bool isempty;
	if(grid[positions[0]-1][positions[1]-1] == empty){
		isempty = true; // is not empty can't play.
	}else {
		isempty = false; // is empty can play.
	}
	return isempty;
}
