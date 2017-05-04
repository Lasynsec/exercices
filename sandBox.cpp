#include <iostream>
#include <string>

using namespace std;

//prototypes
int calculer(int& nbone, int &nbtwo);
void afficher(int resultat);

int main()
{
	int one = 1;
	int two = 2;
	
	int* px(nullptr);
	int resultat = calculer(one,two);
	delete px;
	px = nullptr;

	afficher(resultat);

	return 0;
}

int calculer(int& nbone, int &nbtwo){

	if(nbone < nbtwo){
		px = new int(nbone);
	}else{
		px = new int(nbtwo);
	}

	return px;
}

void afficher(int resultat){
	echo << resultat;
}
