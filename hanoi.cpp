#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

//Enum for disks:
enum Disks {empty,one,two,three};

//Typedef
typedef array<array<int,3>,3> Towers; // the three towers.
typedef array<int,2> PriorPosition;

//Prototypes
void initialisation(Towers& towers);
void display(const Towers& towers);
Disks pickUpDisk();
PriorPosition RemoveDisk(Towers& towers, Disks disk);
void MoveDisk(Towers& towers, Disks disk, PriorPosition& lastPosition);
int chooseTower();
bool IspossibleToPlay(int row, int column, Towers& towers,Disks disk);
void HanoiManagment(Towers& towers);
bool CanPickThisOne(Towers& towers, Disks disk);

int main(){

	//We generate the three towers
	Towers towers;
	
	//Initiate each value
	initialisation(towers);

	//We display the game
	cout << "WELCOME TO HANOI 2017 !!!"<<endl;
	
	//The game is managed here.
	HanoiManagment(towers);

	return 0;
}

/**
 * Initiate all towers to empty.
 * @param: the array of all three towers.
 */
void initialisation(Towers& towers){
	int sizeDisk(3);
	for(size_t row(0); row < towers.size(); ++row){
		for(size_t column(0); column < towers[row].size(); ++column){
			
			if(column  == 0 and row == 2){
				towers[row][column] = three;
			} else if(column == 0 and row == 1){
				towers[row][column] = two;
			} else if(column == 0 and row == 0){
				towers[row][column] = one;
			}else {
				towers[row][column] = empty;
			}
		}
	}
}

/**
 * Display the game.
 * @param: the last update of the tower.
 */
void display(const Towers& towers){
	array<char,3> letter = {'A','B','C'};
	cout << endl;
	for(size_t row(0); row < towers.size(); ++row){
		for(size_t column(0); column < towers[row].size(); ++column){
				
				if(towers[row][column] == 0){;
					cout << ' ';	
				} else {
					cout << towers[row][column];
				}


				if(column == 0){
					cout << " | ";
				} else if(column == 1){
					cout << " | ";
				} else {
					cout << "   ";	
				}
			}
			cout << endl;
		}
	size_t j(0);
	for(size_t i(0); i < 3; ++i){
		cout<<"---";
	}
	cout << "\n";
	for(size_t j(0); j < letter.size(); ++j){
		cout << letter[j]<<"   ";
	}
	cout << "\n";
}

/**
 * Ask the user to pick up a disk by his number.
 */
Disks pickUpDisk(){
	unsigned int sizeDisk(0);
	Disks* ptr(nullptr);
	ptr = new Disks;

	do{
		cout << "Choose a disk by its size (1 to 3): ";
		if(!(cin >> sizeDisk)){
			cin.clear();
			cin.ignore(1000,'\n');
			cout <<"- Number only, please ! \n";
		
		} else if(sizeDisk > 3){
			cout << "- Must not be greater than 3 \n";
		} else if(sizeDisk < 1){
			cout << "- Must not be lower than 1 \n";
		}else {

			switch(sizeDisk){
				case 1:
					*ptr = one;
					break;
				case 2:
					*ptr = two;
					break;
				case 3:
					*ptr = three;
					break;
			}
		}
	}while(sizeDisk < 1 || sizeDisk > 3);
	
	Disks NumDisk(*ptr);
	delete ptr;
	ptr = nullptr;

	return NumDisk;
}

/**
 * Remove the chosen disk from the current tower.
 * @param: the towers.
 * @param: the disk.
 * @return: the last position of the disk.
 */
PriorPosition RemoveDisk(Towers& towers, Disks disk){
	PriorPosition getPosition;
	for(size_t row(0); row < towers.size(); ++row){
		for(size_t column(0); column < towers[row].size(); ++column){
			if(towers[row][column] == disk){
				getPosition[0] = row;
				getPosition[1] = column;
				towers[row][column] = empty;
			}
		}
	}
	return getPosition;
}


/**
 * Move disk from a tower to another one.
 * @param: all towers.
 * @param: the disk to move.
 * @param: the last position of the current disk befor moving it.
 */
void MoveDisk(Towers& towers, Disks disk, PriorPosition& lastPosition){
	bool canPlayIt(false);
	int column(0);
	vector <bool>wrongMovment;
	
	// Choose the next tower to place the disk.
	column = chooseTower();

	// Loop through the chosen tower and check if it's possible to play here.
	for(int row(towers.size()-1); row > -1; --row){	
		 canPlayIt = IspossibleToPlay(row,column,towers,disk);
		 if(canPlayIt){//if ok.
			towers[row][column] = disk;//place the disk here.
		 } 	
		// get the situation of the tower.
		wrongMovment.push_back(canPlayIt); 
	}
	// if it's not possible to play here, we return in the last position.	
	if((wrongMovment[0] + wrongMovment[1]+ wrongMovment[2]) == 0){
		towers[lastPosition[0]][lastPosition[1]] = disk; 
		cout << " - Sorry but you cannot place your disk here !\n";
	}
}

/**
 * choose a tower to place the disk.
 * @return: the input of the player.
 */
int chooseTower(){
	char tower;
	int nbrTower(0);
	do{
		cout << "Choose a tower where to place your disk (a, b or c): ";
		cin >> tower;
		
		if((tower != 'a') and (tower != 'b') and (tower != 'c')){
			cout << " - Please type only one of the required letters !\n";
		}
	}while((tower != 'a') and (tower != 'b') and (tower != 'c'));

	switch(tower){
		case 'a':
			 nbrTower = 0;
			break;
		case 'b':
			 nbrTower = 1;
			break;
		case 'c':
			nbrTower = 2;
			break;
	}
	return nbrTower; 
}

/**
 * Check if it's possible to play in the chosen tower.
 * @param: row, the number of the line.
 * @param: column, the number of the column.
 * @param: the towers.
 * @param: the disk.
 * @return: return a bolean, that say if the player can or cannot play in this position.
 */
bool IspossibleToPlay(int row, int column, Towers& towers, Disks disk){
	bool canPlay(false);
	if(row == 2){
		if(towers[row][column] == empty){
			canPlay = true;
		}
	}else if(row == 1){
		if((towers[row][column] == empty) 
				&& (disk != towers[2][column]) 
					&& (disk < towers[2][column])){
			canPlay = true;
		}
	}else if(row == 0){
		if((towers[row][column] == empty) 
				&& (disk != towers[1][column]) 
					&& (disk < towers[1][column])
						&& (disk != towers[2][column])){
			canPlay = true;
		}
	}
	return canPlay;
}

/**
 * The game is handled here.
 * @param: the towers.
 */
void HanoiManagment(Towers& towers){
	bool gameIsOver(false);
	Disks chosenDisk;
	PriorPosition lastPosition;
	bool canPickThis;

	do{	
		do{
			//We choose the disk.
			chosenDisk = pickUpDisk();
			//We check if the player can take the disk.
			canPickThis = CanPickThisOne(towers, chosenDisk);
			
			if(not canPickThis){
				cout << " - you cannot take this disk !\n";
			}
		}while(not canPickThis);

		//We remove the disk from the last position.
		lastPosition = RemoveDisk(towers,chosenDisk);
		//We put the disk in the chosen position.
		MoveDisk(towers, chosenDisk, lastPosition);
		//We display the game here.	
		display(towers);
	}while(not gameIsOver);
}

/**
 * Check if the player can take this disk.
 */
bool CanPickThisOne(Towers& towers, Disks disk){
	bool canPickThis(false);
	for(size_t i(0); i < towers.size(); ++i){
		for(size_t j(0); j < towers[i].size(); ++j){
			if(towers[i][j] == disk){
				if(towers[i-1][j] != one 
						and towers[i-1][j] != two
							and towers[i-1][j] != three){
					canPickThis = true;
				} else {
					canPickThis = false;
				}
			}
		}
	}
	return canPickThis; 
}
