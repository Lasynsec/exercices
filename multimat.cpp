#include <iostream>
#include <math.h>
#include <vector>
#include <string>

using namespace std;

//prototypes
int dimensions();
void insertMatrixValues(vector<vector<int>>& M);
void matrixReader(vector<vector<int>> M, int which);
void askHim(string &matrix,int nbr);
vector<vector<int>> multiplyMatrices(vector<vector<int>> &M1,vector<vector<int>> &M2);

int main()
{
	string row = "row";
	string column = "column";
	int numberOfRow;
	int numberOfColumn;
	vector<vector<int>> result;

	/*first matrix*/
	askHim(row,1);
	numberOfRow = dimensions();
	
	askHim(column,1);
	numberOfColumn = dimensions();
	vector<vector<int>> M1(numberOfRow, vector<int>(numberOfColumn));
	insertMatrixValues(M1);
	cout << endl;

	/*second matrix*/
	askHim(row,2);
	numberOfRow = dimensions();
	
	askHim(column,2);
	numberOfColumn = dimensions();
	vector<vector<int>> M2(numberOfRow, vector<int>(numberOfColumn));
	insertMatrixValues(M2);

	/*Read the matrixes*/
	matrixReader(M1,1);
	matrixReader(M2,2);
	

	/*Mutliply matrices*/
    result = multiplyMatrices(M1,M2);

	return 0;
}

/*
* Ask the user to type the dimensions of the two matrices.
* @return the dimensions. 
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
* Loop through the matrices and display his content.
* @param: the matrix to loop in and the number to the matrix M1 or M2.
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

/**
 * display a message to the user based on the matrix number.
*/
void askHim(string &matrix,int  nbr){
	cout << " Type a number of "<< matrix << " for the matrix number "<< nbr <<" : ";
}

/**
* Insert elements in each matrix.
* @param: the reference of a matrix in which to insert elements.   
*/
void insertMatrixValues(vector<vector<int>>& M){
	int incrementable(1);
	for(size_t i(0); i < M.size(); i++){
		for(size_t j(0);j < M[i].size(); j++){
		cout << " Put a value in the index " << incrementable++ << " of your matrix: ";
			cin>>M[i][j];
		}
	}
}

/**
* Multiply ...
*@param: ....
*@return: ...
*/
vector<vector<int>> multiplyMatrices(vector<vector<int>> &M1, vector<vector<int>> &M2){
	vector<vector<int>> result;
	int nbrOfColumn(0);
	int nbrOfLine(0);

//	nbrOfLine = M1.size();
	nbrOfColumn = M1[0].size();
//	cout <<" The Matrix M1 has " << nbrOfLine << " lines and " <<nbrOfColumn <<" columns " << endl;
	
//	nbrOfLine = 0;

	nbrOfLine = M2.size();
//	nbrOfColumn = M2[0].size();
//	cout <<" The Matrix M2 has " << nbrOfLine << " lines and " <<nbrOfColumn <<" columns " << endl;

	if(nbrOfLine != nbrOfColumn){
		cout <<"The number of column of M1 must be equal to the number of row of M2" <<endl;
	}
	return result;
}
