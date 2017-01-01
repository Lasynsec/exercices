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
vector<vector<double>> multiplyMatrixes(vector<vector<int>>M1,vector<vector<int>>M2);

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
	insertMatrixValues(M1);
	cout << endl;

	/*second matrix*/
	askHim(row,2);
	numberOfRow = dimensions();
	
	askHim(column,2);
	numberOfColumn = dimensions();
	vector<vector<int>> M2(numberOfColumn, vector<int>(numberOfRow));
	insertMatrixValues(M2);

	/*Read the matrixes*/
	matrixReader(M1,1);
	matrixReader(M2,2);	

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
		cout << " Put a value in the index " << incrementable++ << " : ";
			cin>>M[i][j];
		}
	}
}

/**
* Multiply ...
*@param: ....
*@return: ...
*/
vector<vector<double>> multiplyMatrixes(vector<vector<int>>M1,vector<vector<int>>M2){

}
