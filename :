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
vector<int> multiplyMatrices(vector<vector<int>> &M1,vector<vector<int>> &M2);
vector<vector<int>>splitArray(vector<int>& arrayToSplit, int matrix_size);
int main()
{
	string row = "row";
	string column = "column";
	int numberOfRow;
	int numberOfColumn;
	vector<vector<int>> result;

//	first matrix
/*
	askHim(row,1);
	numberOfRow = dimensions();
	
	askHim(column,1);
	numberOfColumn = dimensions();
	vector<vector<int>> M1(numberOfRow, vector<int>(numberOfColumn));
	insertMatrixValues(M1);
	cout << endl;
*/

//	second matrix
/*	
	askHim(row,2);
	numberOfRow = dimensions();
	
	askHim(column,2);
	numberOfColumn = dimensions();
	vector<vector<int>> M2(numberOfRow, vector<int>(numberOfColumn));
	insertMatrixValues(M2);
*/

//	Read the matrixes
/*	
	matrixReader(M1,1);
	matrixReader(M2,2);
*/
	

//	Mutliply matrices
    vector<vector<int>> M1(
	{
        {1,2,3},
		{4,5,6}
//		{1,7},
//		{2,4}
	}
   );

    vector<vector<int>> M2(
	{
		{1,2,3,4},
		{5,6,7,8},
		{9,0,1,2}
//		{3,3},
//		{5,2}
	}
   );
	
	
   vector<int>result_two_dim;
   result_two_dim = multiplyMatrices(M1,M2);
	cout << " list of elements : ";
	for(auto element : result_two_dim){
		cout <<element << " ";
	}
	cout << endl;


   int sizeM2(0);
   sizeM2 = M2[0].size(); // get the column size of vector two.
	
   result =  splitArray(result_two_dim, sizeM2);

   for(size_t i(0); i < result.size(); i++){
		for(size_t j(0); j < result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl;

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
vector<int> multiplyMatrices(vector<vector<int>> &M1, vector<vector<int>> &M2){
	vector<int> row;	// vector will contain the 
	int sumRow(0); // wil contain the sum of each rows.
	int col(0);
	int line(0);
	int nbrOfColumn(0);
	int nbrOfLine(0);
	int sizeRow(0);

	nbrOfColumn = M1[0].size(); // vector 1 column size.
	nbrOfLine = M2.size();		// vector 2 whole size.

	if(nbrOfLine != nbrOfColumn){ // If the number of line of M2 is not equal to the number of column of M1. 
		cout <<"The number of column of M1 must be equal to the number of row of M2 "<<endl; // we send those sentences to the users.
		cout <<"Sorry but we cannot proceed to the multiplication..."<<endl;
	} else { // if there are equal.
		int incrementCol(0); // we initiate the incemrentation to a value of 0.
	    do{ // we start the while loop here.
	    for(size_t i(0); i < M1.size(); i++){ // 
				for(size_t j(0);j < M1[i].size(); j++){
					cout << " [ "<< i << "-"<< j << " ] " << M1[i][j] << " * " << " [ " << i << "-"<< j << " ] " << M2[line][col] << endl;
					sumRow += M1[i][j] * M2[line][col];
					++line;
				}
			row.push_back(sumRow);
			sumRow = 0;
			line = 0;
		};
		++incrementCol;
		++col;
		cout << " col is " << col << endl;
		cout << " M2 number of column is  "<< M2[0].size() << endl;
		cout << " incrementCol is  " << incrementCol << endl;
	    }while(incrementCol < M2[0].size());
		//result.push_back(row); 

	return row;
	}
  }

/**
* function splits vector to several sub vectors.
*
*/
vector<vector<int>>splitArray(vector<int>& arrayToSplit, int matrix_size){
	cout << "The result is :"<< endl;										// Display the sentence on screen.
	vector<vector<int>> result;												// the empty multi vector for the result.
	//cout <<"Array split : "<< arrayToSplit.size()<< endl;					
	//cout <<"matrix two column size  : "<<  matrix_size << endl;
	//int length = arrayToSplit.size() / matrix_size;							//  
	//int remain = arrayToSplit.size() % matrix_size;
	int length = matrix_size;
	int remain = 0;
	//cout << "the size of matrix_size is  " << matrix_size << endl;
	int begin = 0;
	int end = 0;
	int matrixLength(0);
	matrixLength = (matrix_size / 2) < 2 ? matrix_size : (matrix_size / 2);
	for(int i(0); i < matrixLength; i++){
		end +=  length;
		//cout << "End : " << end << endl;
		result.push_back(vector<int>(arrayToSplit.begin() + begin, arrayToSplit.begin() + end));
		begin = end;
		//cout << "begin "<< begin << endl;
	}
	return result;	
}
