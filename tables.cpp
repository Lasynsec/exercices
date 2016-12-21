#include <iostream>
#include <array>

using namespace std;

int main()
{
	 const size_t sizeTable(8);
	 const size_t sizeMulti(10);

	 array <int, sizeTable> tables;

	cout << " Table de multiplication" << endl;
	for(size_t i = 2; i <= tables.size(); i++) {
		cout << "Table de " << i << " : " << endl;
		for(size_t j = 1; j <= tables.size() + 2; j++){
			cout << j <<  " * " << i << " = " <<  j  *  i << endl;  
		}
	}
}
