#include <iostream>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

//prototypes
int dimensions();
void insertMatrixValues(vector<vector<int>>M);
void matrixReader(vector<vector<int>> M, int which);
void askHim(string &matrix,int nbr);

int main()
{
	string row = "row";
	string column = "column";
	int numberOfRow;
	int numberOfColumn;

	/*first matrix*/
	askHim(row,1);
	numberOfRow = dimensions();
	
	askHim(column,1);
	numberOfColumn = dimensions();
	vector<vector<int>> M1(numberOfColumn, vector<int>(numberOfRow));
	cout << endl;

	/*second matrix*/
	askHim(row,2);
	numberOfRow = dimensions();
	
	askHim(column,2);
	numberOfColumn = dimensions();
	vector<vector<int>> M2(numberOfColumn, vector<int>(numberOfRow));
	
	/*Read the matrixes*/
	matrixReader(M1,1);
	matrixReader(M2,2);	

	return 0;
}

/*
*
*/
int dimensions(){
	int dimension(0);
	while(!(cin>>dimension)){
		cin.clear();
		cin.ignore(1000,'\n');
		cout << "It must be a number !!! : ";
	}
	return dimension; 
}

/*
*
*/
void matrixReader(vector<vector<int>> M, int which){
	cout << "The matrix number " << which << endl;
	for(auto ligne : M){
		for(auto element : ligne){
			cout << element << " ";	
		}
		cout << endl;
	}	
}

/*
*
*/
void askHim(string &matrix,int  nbr){
	cout << " Type a number of "<< matrix << " for the matrix number "<< nbr <<" : ";
}

/**
*
*/
insertMatrixValues(vector<vector<int>>&M){

}
