#include <iostream>
#include <string>

using namespace std;

class Apero{
	public:
		Apero(string a = "It's time for the apperitif!"): appetizer_(a){
			cout << appetizer_<<"\n";
		}
		~Apero() { 
			cout <<"Lunch time !\n";
		}

		void bis(){
			cout <<"Another one ?\n";
		}
	private:
		string appetizer_;
};
int main(){
	Apero apero;
	cout << "Great!\n";
	apero.bis();
	cout << "No, thanks.\n";
	return 0;
}
