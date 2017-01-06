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
/*	string row = "row";
	string column = "column";
	int numberOfRow;
	int numberOfColumn;*/
	vector<vector<int>> result;
/*
//	first matrix
	askHim(row,1);
	numberOfRow = dimensions();
	
	askHim(column,1);
	numberOfColumn = dimensions();
	vector<vector<int>> M1(numberOfRow, vector<int>(numberOfColumn));
	insertMatrixValues(M1);
	cout << endl;

//	second matrix
	askHim(row,2);
	numberOfRow = dimensions();
	
	askHim(column,2);
	numberOfColumn = dimensions();
	vector<vector<int>> M2(numberOfRow, vector<int>(numberOfColumn));
	insertMatrixValues(M2);

//	Read the matrixes
	matrixReader(M1,1);
	matrixReader(M2,2);
	

//	Mutliply matrices */

   vector<vector<int>> M1(
	{
		{1,7},
		{2,4}
	}
   );

   vector<vector<int>> M2(
	{
		{3,3},
		{5,2}
	}
   );

   result = multiplyMatrices(M1,M2);
   for(size_t i(0); i < result.size(); i++){
		for(size_t j(0); j < result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

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
* Multiplication of  two matrices
*@param:  reiceve two mutlidimensionals vectors
*@return: return a multidimensional vector as result. 
*/
vector<vector<int>> multiplyMatrices(vector<vector<int>> &M1, vector<vector<int>> &M2){
	vector<vector<int>> result;
	vector<int> row;
	int sumRow(0);
	int col(0);
	int line(0);
	int nbrOfColumn(0);
	int nbrOfLine(0);
	int sizeRow(0);

	nbrOfColumn = M1[0].size();
	nbrOfLine = M2.size();

	if(nbrOfLine != nbrOfColumn){
		cout <<"The number of column of M1 must be equal to the number of row of M2";
		cout <<"Sorry but we cannot proceed to the multiplication..."<<endl;
	} else {
	    for(size_t i(0); i < M1.size(); i++){
				for(size_t j(0);j < M1[i].size(); j++){
					cout << " [ "<< i << "-"<< j << " ] "<< M1[i][j] << " * " <<" [ "<< i << "-"<< j << " ] "<< M2[line][col] << endl;
					sumRow += M1[i][j] * M2[line][col];
					++line;
				}
			row.push_back(sumRow);
			sumRow = 0;
			line = 0;
			++col;
		}
	result.push_back(row);
    
	line = 1;
	col = 1;
	  /*for(size_t i(0); i < M1.size(); i++){
				for(int j = M1[i].size() - 1;j >= 0; j--){
					cout << M1[i][j] * M2[line][col]<<" = " <<" [ "<< i << "-"<< j << " ] "<< M1[i][j] << " * " <<" [ "<< i << "-"<< j << " ] "<< M2[line][col] << endl;
					sumRow += M1[i][j] * M2[line][col];
					cout << " Here the total is : "<< sumRow << endl;
					--line;
					if(line < 0){
						line = 0;	
					}
				}
			cout << " Here we insert " << sumRow << endl;
			row.push_back(sumRow);
			sumRow = 0;
			++line;
		    --col;
	 }
	
	result.push_back(row);*/
	return result;

  }
}
