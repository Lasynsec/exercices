#include <iostream>
#include <vector>

using namespace std;

//Def types
typedef size_t Position;
typedef vector<int> Sequence;

//Struct 
struct SousSequence{
	Position debut;
	Position fin;
	int somme;
};

//Prototypes
SousSequence trancheMax1(Sequence& seq);
SousSequence trancheMax2(Sequence& seq);
SousSequence trancheMax3(Sequence& seq);
void displayIt(SousSequence const& sssq);
Sequence userSeq();

int main(){
	Sequence seq({11,13,-4,3,-26,7,-13,25,-2,17,5,-8,1});
	//trancheMax1(seq);

	SousSequence sssq(trancheMax1(seq));
	SousSequence sssq2(trancheMax2(seq));
	SousSequence sssq3(trancheMax3(seq));

	//cout << "Début : "<< sssq.debut <<" Fin : " << sssq.fin <<" Somme : " << sssq.somme << endl; // algorithme naif.
	//cout << "Début : "<< sssq2.debut <<" Fin : " << sssq2.fin <<" Somme : " << sssq2.somme << endl;// algorithme moins nail.
	//cout << "Début : "<< sssq3.debut <<" Fin : " << sssq3.fin <<" Somme : " << sssq3.somme << endl; // algorithme efficace.

	
	displayIt(sssq);
	return 0;
}

//Algorythme naif.
SousSequence trancheMax1(Sequence& seq){
	SousSequence sssq = {0,0,seq[0]}; //On crée une instance de structure est l'initialise.
	int somme; //On declare la somme;
	if(seq.size() > 0){ //On verifie si la liste n'est pas vide.
		for(size_t debut(0); debut < seq.size(); ++debut){ // On part de 0 pour le début de la sous-sequence jusqu'à la fin de la sequence.		
			for(size_t fin(debut); fin < seq.size(); ++fin ){ // On initialise la fin de la sous-sequence à parir du début de celle-ci jusqu'à la fin de la sequence.
				somme = 0; //On initialise la somme.
				//cout << "Debut: "<< debut <<"->"<< seq[debut] <<" - Fin: "<< fin <<"->"<<seq[fin]<<endl; 
				for(size_t position(debut); position < fin; ++position){ //On va parcourir la sous-sequence de debut de celle-ci jusqu'à fin.
					//cout << "position : " << position << endl;
					somme = somme + seq[position];  //On additionne chaque position dans une variable.
					//cout << "Somme: "<<somme<<endl;
				}	
				if(somme > sssq.somme){ // Si la somme obtenue est plus grande que l somme de la structure.
					sssq.debut = debut; // On recupère le début de la sous-sequence.
					sssq.fin = fin; // On recupère la fin de la sous-sequence.
					sssq.somme = somme; // On recupère la somme

					//cout << "Le début est: "<< debut <<endl; 
					//cout << "La fin est: "<< fin <<endl;
					//cout << "La somme est: "<< somme <<endl; 
					//cout << endl;
				}
			}
		}
	}
	return sssq; // On envoie toute la structure.
}

//Algorithme unpeu moins naif
SousSequence trancheMax2(Sequence& seq){
	SousSequence sssq2 = {0,0,seq[0]}; //On crée une instance de structure est l'initialise.
	int somme; //On declare la somme;
	if(seq.size() > 0){ //On verifie si la liste n'est pas vide.
		for(size_t debut(0); debut < seq.size(); ++debut){ // On part de 0 pour le début de la sous-sequence jusqu'à la fin de la sequence.		
			somme = 0; //On initialise la somme.
			for(size_t fin(debut); fin < seq.size(); ++fin ){ // On initialise la fin de la sous-sequence à parir du début de celle-ci jusqu'à la fin de la sequence.
				somme = somme + seq[fin];  //On additionne chaque position dans une variable.
				if(somme > sssq2.somme){ // Si la somme obtenue est plus grande que l somme de la structure.
					sssq2.debut = debut; // On recupère le début de la sous-sequence.
					sssq2.fin = fin; // On recupère la fin de la sous-sequence.
					sssq2.somme = somme; // On recupère la somme
				}
			}
		}
	}
	return sssq2; // On envoie toute la structure.
}


SousSequence trancheMax3(Sequence& seq){
	SousSequence sssq3 = {0,0,seq[0]};
	
	Position debut(1);
	int somme(0);

	for(Position fin(0); fin < seq.size(); ++fin){
		somme = somme + seq[fin];
		if(somme > sssq3.somme){
			sssq3.debut = debut; // On recupère le début de la sous-sequence.
			sssq3.fin = fin; // On recupère la fin de la sous-sequence.
			sssq3.somme = somme; // On recupère la somme
		}

		if(somme <= 0){
			debut = fin+1;
			somme = 0;
		}
	}
	return sssq3;
}

void displayIt(SousSequence const& sssq){
	cout << "Début : "<< sssq.debut <<" Fin : " << sssq.fin <<" Somme : " << sssq.somme << endl; 
}

Sequence userSeq(){ 
	cout <<"Combien d'éléments vous voulez ?" << endl;
	int elem;
	cin>>elem;

	Sequence 

	for(Position i(0); i < elem){

	}
}
