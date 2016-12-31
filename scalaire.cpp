#include <iostream>
#include <vector>

using namespace std;

//prototypes
double scalaire(vector<int> u, vector<int> v);
int vectorsSize(int const N_MAX);
int pushElements(vector<int>& vec);

int main()
{
	int const N_MAX(10); // the limit size of arrays.
	int askSize(0);


	askSize = vectorsSize(N_MAX); // get the array's size from the user.
	vector<int> a(askSize); // array vector a.
	vector<int> b(askSize); // array vector b.

	cout <<"Put " << askSize << " elements in the first vectors" << endl;
	pushElements(a);

	cout <<"Put  " << askSize << " elements in the second vectors" << endl;
	pushElements(b);

	int dotProduct(0);
	dotProduct = scalaire(a,b);

	cout << " The dot product of the two vectors is " << dotProduct << endl;
	return 0;
}

/* The function will calculate the Dot product.
 * @param: two array in which to calculate the Dot product.
 * @return: return the Dot product number.
 */
double scalaire(vector<int> a,vector<int> b){
	double dotProduct(0);

	for(size_t i(0); i <a.size();i++){
		dotProduct += a[i]*b[i];
	}

	return dotProduct;
}

/* The function will ask for the size of arrays.
 * @param: the limit size of arrays.
 * @return: the input of the user.
 */
int vectorsSize(int const N_MAX){
	int userInput;
	do{
		cout << "Type a size for you arrays under " << N_MAX<< " : ";
		if(!(cin>>userInput)){
			cout << "Please enter numbers only"<< endl;
			cin.clear(); 
			cin.ignore(100,'\n');
		}else if(userInput < 1){
			cout << "Your number must be greater than 1"<< endl;
		} else if(userInput > N_MAX){
			cout << "Your number must be less than " << N_MAX << endl;
		}
	}while(userInput < 1 || userInput >= N_MAX);

	return userInput;
}

/* The function will push elements in arrays.
 * @param: the vector in which to push elements in.
 */
int pushElements(vector<int>& vec){

	for(size_t i(0); i < vec.size(); i++){
		cout << " type the element number " << i << " : ";
		cin>>vec[i];
		cout << endl;
	}
}
