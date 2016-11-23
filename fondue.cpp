#include <iostream>
using namespace std;

int main()
{
	const int BASE(4);
	double cheese(800.0);
	double water(2.0);
	double garlic(2.0);
	double bread(400.0);

	cout << " How many persons will come to the dinner ?" << endl;
	int nbOfPers;
	cin >> nbOfPers;
	
	cheese = cheese * nbOfPers / BASE; 
	water = water * nbOfPers / BASE;
	garlic = garlic * nbOfPers / BASE;
	bread = bread * nbOfPers / BASE;

	cout << "- " << cheese << " :gr of Vacherin fribourgeoise" << endl;	
	cout << "- " << water << " :dl of water" << endl;
	cout << "- " << garlic << " :clove of garlic" << endl;
	cout << "- " << bread << " :gr of bread" << endl;
	return 0;
}
