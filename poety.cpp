#include <iostream>
#include <string>

using namespace std;

class Flower {
	private:
		string wordOne_;
		string wordTwo_;
	public:
		Flower(string one, string two) : wordOne_(one),wordTwo_(two){
			cout << one << " fraichement cuillie\n";
		}
		
		~Flower() {
			cout << "qu'un simple souffle...\n";
		}
		Flower(Flower const& f):wordOne_(),wordTwo_(){
			cout <<"Fragile corolle taillée \n";
		} 
		//Getters
		string wordone(){return wordOne_;}

		//Fonctions
		void eclore(){
			cout << " veine de blue \n";
		}
};

int main()
{
	Flower f1("Violette","bleu");
	Flower f2(f1);
	cout << "dans un cristal";
	f2.eclore();
	cout << "Donne un poème un peu fleur blue"<<endl<<"ne laisse plus ";
	return 0;
}
