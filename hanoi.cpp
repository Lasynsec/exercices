#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

//Enum for disks:
enum Disks {empty,one,two,three};

//Typedef
typedef array<array<int,3>,3> Towers; // the three towers.

//Prototypes
void initialisation(Towers& towers);
void display(const Towers& towers);
Disks pickUpDisk();
void RemoveDisk(Towers& towers, Disks disk);
void MoveDisk(Towers& towers, Disks disk);
int chooseTower();
bool IspossibleToPlay(int row, int column, Towers& towers,Disks disk);
void HanoiManagment(Towers& towers);

int main(){

	//We generate the three towers
	Towers towers;
	
	//Initiate each value
	initialisation(towers);

	//We display the game
	cout << "WELCOME TO HANOI 2017 !!!"<<endl;
	
	//----------------------------------/Test
//	Disks chosenDisk(pickUpDisk());
//	RemoveDisk(towers,chosenDisk);
//	MoveDisk(towers, chosenDisk);
	//----------------------------------/Test
	
	HanoiManagment(towers);
	//display(towers);

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
 */
void RemoveDisk(Towers& towers, Disks disk){
	for(size_t row(0); row < towers.size(); ++row){
		for(size_t column(0); column < towers[row].size(); ++column){
			if(towers[row][column] == disk){
				towers[row][column] = empty;
			}
		}
	}
}


/**
 * Move disk from a tower to another one.
 * @param: all towers.
 * @param: the disk to move.
 */
void MoveDisk(Towers& towers, Disks disk){
	bool canPlayIt(false);
	int column(0);
	vector <bool>wrongMovment;
	
	column = chooseTower();
	
	for(int row(towers.size()-1); row > -1; --row){	
		 canPlayIt = IspossibleToPlay(row,column,towers,disk);
		 cout << "Is it a good play: "<< canPlayIt <<"\n";
		 if(canPlayIt){
			towers[row][column] = disk;
		 } 	
		wrongMovment.push_back(canPlayIt);
	}
	
	if((wrongMovment[0] + wrongMovment[1]+ wrongMovment[2]) == 0){
		// put back the disk in his position.
	}
}

/**
 * choose a tower to place the disk.
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

bool IspossibleToPlay(int row, int column, Towers& towers, Disks disk){
	bool canPlay(false);
	if(row == 2){
	cout << "Row value is : "<< row<<"\n";
		if(towers[row][column] == empty){
			canPlay = true;
		}
	}else if(row == 1){
	cout << "Row value is : "<< row<<"\n";
		if((towers[row][column] == empty) 
				&& (disk != towers[2][column]) 
					&& (disk < towers[2][column])){
			canPlay = true;
		}
	}else if(row == 0){
	cout << "Row value is : "<< row<<"\n";
	cout << "level 2 is "<<towers[2][column]<<"\n";
	cout << "Level 1 is "<< towers[1][column]<<"\n";
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
 */
void HanoiManagment(Towers& towers){
	bool gameIsOver(false);
	do{	
		Disks chosenDisk(pickUpDisk());
		RemoveDisk(towers,chosenDisk);
		MoveDisk(towers, chosenDisk);
		
		display(towers);
	}while(not gameIsOver);
}
