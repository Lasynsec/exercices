#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//Enum: color for each disk.
enum Color {empty, red, yellow};

//Structure
struct Player{ //structure of the player.
	int id;
	string name;
	bool hasWon; // if the player win or not.
	Color disk; // color of the disk (red or yellow.
};


/*Typdef*/
typedef array<array<Color,7>,6> Grid; // The grid of the game.
typedef vector<Player> Players; // A array of players.
typedef vector<char> colorsDisk; // A array of disks colors in the game.
typedef vector<int> fourInaRow; // get a row of disks.
typedef array <int,2> Positions; // get the position of the disk.
typedef array <bool,4> WishDirection; // ?

/*Prototypes*/
void display(const Grid& grid); // Display the grid with all disks.
void initialisation(Grid& grid); // The game will start with empty cases;
Player playerGenerator(int &id, colorsDisk& colorsVec); // create each player.
void playersRegistration(Players& player);//Registrate each player.
bool checkDuplicateDisk(char color, colorsDisk& colorVec);//Check if the same color has been chosen twice.
Positions askPosition(Grid& grid, Player& player); // Ask to the player the next position in which to play.
int askNumber(bool isVertical);// Ask numbers of the two positions to the player.
void connectFour(Players& players, Grid& grid);// The whole game is handled here.
bool isEmpty(Grid& grid, Positions& positions);//Check if the next chosen position is free.
bool hasWonTheGame(Player& player, Positions& positions, Grid& grid); // check if the player has won.
bool checkTheConnectFour(fourInaRow& four,Player& player); //check if the player get a four row.
 
int main(){
	/*Grid initialisation*/
	Grid grid;				// create the grid.
	initialisation(grid);	// initialise the grid.
	
	/*Players registration*/
	Players players; //------------------------------------// get rid of the comment after testing.
	//Players players = {{1,"emma",false,red},{2,"jenna",false,yellow}}; // remove the line after testing.

	playersRegistration(players); //save the players.---------------------// get rid of the comment after testing.
	
	/*Play the game*/
	connectFour(players, grid);

	return 0;
}

// diplay 0 for a red case, X pour a yellow case.
/**
 * Display the grid on screen.
 * @param: the array of the grid.
 */
void display(const Grid& grid){
	cout << endl;
	int column(1);
	for(auto row: grid){
		cout <<column<< "|";
		for(auto kase : row){
			if(kase == empty){ // empty is equal to 0.
				cout << ' ';
			} else if(kase == red){
				cout << 'O'; // is equal to 1.
			} else {
				cout << 'X'; // equal to 2.
			}
			cout << '|';
		}
		cout << endl;
		++column;
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
	cin>>p.name; //The player type his name here.
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
				if(isAvailable){ //if the color has not already been taken.
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

	return p; //return the struct of the player.
}

/**
 * Registration of both players
 * @param: The Players vector.
 */
void playersRegistration(Players& players){
	colorsDisk colorsVec; //for the color's disk.
	for(size_t i(0); i < 2; i++){
		players.push_back(playerGenerator(i+1, colorsVec)); // save the player configuration in the vector players.
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
	auto isDuplicate = find(begin(colorVec), end(colorVec), color); //loop through the array.
	if(isDuplicate != end(colorVec)){ //the color already exist.
		isNotAvailable = false;
	} else {
		colorVec.push_back(color); // if color free, push it into the vector.
		isNotAvailable = true;
	}

	return isNotAvailable;
}

/**
 * Ask the disk position to the players.
 * @param: the grid to modiy.
 * @param: the player that will play.
 */
Positions askPosition(Grid& grid, Player& player){
	int horizontal; // for the player vertical position.
	int vertical; // for the player horizontal position.
	Positions positions; //for the disk position.
	bool isempty; // if the position is free.
	bool horiFour(false);

	do{
		cout << "Player "<< "("<<player.id <<") "<< player.name <<": " << "\n";
		cout <<" - type the horizontal position of your new disk:";
		horizontal = askNumber(false);
		cout <<" - type the vertical position of your new disk:";
		vertical = askNumber(true);
		
		positions[0] = vertical;
		positions[1] = horizontal;
	
		isempty = isEmpty(grid,positions);// false or true.

		if(isempty){ // if the futur position is free.
			grid[vertical-1][horizontal-1] = player.disk; // put the player's disk in this position.
		} else {
			cout << endl;
			cout <<"*Sorry but you cannot put a disk here !"<< endl;
		}
	}while(isempty != true); // ask until the futur position is free.

	return positions; // return the coordonate.
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
 * The game is handled here.
 */
void connectFour(Players& players, Grid& grid){
	cout << "WELCOME TO CONNECTOR 4 !"<<endl;
	bool gameIsOver(false);
	Positions positions; // For the position of the disk.
	int checkFour(0);// check if the player reaches four disks in a row.

	do{
		for(auto player : players){ // all players must play.
			positions = askPosition(grid, player);//place the disk in the grid.
			gameIsOver = hasWonTheGame(player, positions, grid); //check if the player has won the game.
			//cout << "\n game is over "<< gameIsOver<<"\n"; // delete after testing.
			if(gameIsOver){
				cout << "\n Well done "<< player.name <<", you've won the game !!!\n"; // delete after testing.
				break;
			}
			display(grid); // display the grid.
		}
	}while(gameIsOver != true);
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

/**
 * Check if the player has a row of four elements
 * @param: the new position of the disk.
 * @param: all the grid.
 * @return: return a boolean value.
 */
bool hasWonTheGame(Player& player, Positions& positions, Grid& grid){
	fourInaRow four;//will get all the row or column in a line.
	WishDirection AllDirection;
	
	/**
	 *check in the horizontal direction.
	 */
	//cout << "Horizontal : ";
	for(size_t i(0); i < grid[positions[0]].size(); ++i){
		//cout<<grid[positions[0]-1][i]<<"-";
		four.push_back(grid[positions[0]-1][i]);
	}
	
	bool horiFour(false); // if the line of disks is in the horizontal;
	horiFour = checkTheConnectFour(four, player); // check for the four disks.
	four.clear(); //clear the array.

	/**
	 * check in the vertical direction.
	 */
	//cout << "Vertical : ";
	for(size_t i(0); i < 6; ++i){
		//cout<<grid[i][positions[1]-1]<<"-";
		four.push_back(grid[i][positions[1]-1]);
	}
	bool vertiFour(false);
	vertiFour = checkTheConnectFour(four, player);
	four.clear(); //cleart the array.

	/**
	 * check in the diagonal direction (from left).
	 */
	Positions intercept; // first we find the intercept if x = 0, what is y.
	int b(0);
	int y(0);
    int yUser(positions[0]);
	int x(positions[1]);
    int inversedY(0);

	y = 6 - 1 * (yUser - 1);// calculate the Y position reversed.
	b = y - x;
	inversedY = 6-b+1; // inversed intercept for the programme.

	// Y-intecept.
	// Put a condition here.
	if(inversedY-1 > 6){
		intercept[0] = 5; 
		intercept[1] = (inversedY-1)-6;
	}else{
		intercept[0] = inversedY-2; 
		intercept[1] = 0;
	}
	
	//cout << "Diagonal R : ";
	for(size_t i(0); i < 6; ++i){
		if(((intercept[0] - i) < 6 && (intercept[0] - i) >= 0) && ((intercept[1] + i) < 7 && (intercept[1] + i) >= 0)){
			//cout << grid[intercept[0] - i][intercept[1] + i] << "-";
			four.push_back(grid[intercept[0] - i][intercept[1] + i]);
		}
	}
	bool diagRFour(false);
	diagRFour = checkTheConnectFour(four, player);
	four.clear(); //clear the array.

	/**
	 * check in the diagonal direction (from left).
	 *
	 */
	Positions leftDiagYIntercept;
	int mirrorB(0);
	int mirrorY(0);
	int inputYUser(positions[0]); // input Y from user.
	int inputXUser(positions[1]); // input X from user.
	int mirrorInversedY(0); // reverse it.
	int leftDiagonal(0);
	int leftMirrorB(0);
	int leftMirrorInversedY(0);

	mirrorY = 6 -1 * (inputYUser - 1);
	mirrorB = mirrorY - inputXUser;
	leftMirrorB = mirrorY + inputXUser;

	mirrorInversedY = 6-mirrorB+1;
	leftDiagonal = 6-leftMirrorB+1;
	
	if(leftDiagonal < 0){
		leftDiagYIntercept[0] = 0;
		leftDiagYIntercept[1] = 0-1*leftDiagonal;
	}else{
		leftDiagYIntercept[0] = leftDiagonal;
		leftDiagYIntercept[1] = 0;
	}
	//cout << "Diagonal L - ";
	int testValue(0);
	for(size_t i(0); i < 6; ++i){
		if(((leftDiagYIntercept[0] + i) < 6 && (leftDiagYIntercept[0] + i) >= 0) && ((leftDiagYIntercept[1] + i) < 7 && (leftDiagYIntercept[1] + i) >= 0)){
		//	cout << grid[leftDiagYIntercept[0]+i][leftDiagYIntercept[1]+i]<<"-";
			four.push_back(grid[leftDiagYIntercept[0]+i][leftDiagYIntercept[1]+i]);
		}
	}
	
	bool diagLFour(false);
	diagLFour = checkTheConnectFour(four, player);
	four.clear(); //clear the array.

	AllDirection[0] = horiFour;
	AllDirection[1] = vertiFour;
    AllDirection[2] = diagLFour;
	AllDirection[3] = diagRFour;


	bool heWonPtr(false);
	for(size_t i(0); i < AllDirection.size(); ++i){
		if(AllDirection[i]){
			heWonPtr =  AllDirection[i];
		}
	}
	return heWonPtr;
}


/**
 * Check if the player has four times the same colors.
 * @param: the discs in the grid.
 * @param: the disc of the player.
 * @return: the number of player's disc in the row, column or diagonal.
 */
 bool checkTheConnectFour(fourInaRow& four,Player& player){
	bool fourDisk(false);
	//cout << "\n Disk = ";
	for(size_t i(0); i < four.size(); ++i){
		if(player.disk == four[i]){
			//cout << four[i]<<" - ";
			if((four[i] == four[i+1]) && (four[i+1] == four[i+2]) && (four[i+2] == four[i+3])){ //if we have four time the same color in a row.
				fourDisk = true; 
			} 
		}
	}
	//cout << "\n";
	//cout << "player " << player.name << "[ "<< player.disk<< " ]"<<" have four disks in a row " << fourDisk<<" disks\n";
	return fourDisk;
 }
