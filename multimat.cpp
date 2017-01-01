#include <iostream>
#include <math.h>

using namespace std;

//prototypes
int dimensions();

int main()
{
	
	cout << "Type a number of row";
	int numberOfRow(0);
	numberOfRow = dimensions();

	
	cout << "Type a number of column";
	int numberOfColumn(0);
	numberOfColumn = dimensions;

	//vector<vector<int>> M1(numberOfColumn, vector<int>(numberOfRow));
	vector<vector<int>> M1({4,2},{1,3});

	for(auto ligne : M1){
		for(auto element : ligne){
			cout << element << endl;	
		}
	}	
	
	return 0;
}

int dimensions(){
	int dimensions(0);
	while(!(cin>>dimensions)){
		cin.clear();
		cin.ignore(1000,'\n');
		cout << "It must be a number !!! : ";
	}
	return dimensions; 
}
