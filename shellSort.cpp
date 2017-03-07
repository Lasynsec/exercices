#include <iostream>
#include <vector>

using namespace std;

//prototype
void exchange(int& nbrone, int& nbrtwo);
void shellIt(vector<int>& vec);

int main(){
	//vector<int> vec({3,5,12,-1,215,-2,17,8,3,5,13,18,23,5,4,3,2,1});
	vector<int> vec({50,49,48,47,46,45,44,43,42,41,40});
	int one = 1;
	int two = 2;

	//cout <<"one " <<one << "two"<<two<<endl;
	//exchange(one,two);
	//cout <<"one " <<one << "two"<<two<<endl;
	
	cout << "To sort : ";
	for(auto el : vec){
		cout << el<<" ";
	}
	cout << endl;

	shellIt(vec);
	cout <<"Result : ";
	for(auto el : vec){
		cout << el<<" ";
	}
	cout << endl;
	
	return 0;
}

void exchange(int& nbrone, int& nbrtwo){
	int tempvar;
	tempvar = nbrone;
	nbrone = nbrtwo;
	nbrtwo = tempvar;
}

//Shell sort.
void shellIt(vector<int>& vec){
	for(size_t k(vec.size()/2);k>0;k/=2){//K est l'intervalle.
		cout << "*k"<<k<<" - ";
		for(size_t i(k+0);i<vec.size();++i){ //
			cout << " i"<<i;
			int j(i-k);
			cout << " = j "<<j<<endl;
			if(j == 0){
				if(vec[j] > vec[j+k]){
					exchange(vec[j],vec[j+k]);
				}
			}
			while(j > 0){
				//cout <<"if"<< "["<<j <<"] "<<vec[j]<<" > "<< j << "+"<< k<< "="<<vec[j+k]<<";";
				if(vec[j] > vec[j+k]){
					//cout << " - oui"<<endl;
					//cout <<"if"<< "j["<<j <<"] "<<vec[j]<<" > "<< "vec["<< j<<" + "<<k<<"]"<<"="<<vec[j+k]<<endl;
					//cout << "normal "<< vec[j]<< " and "<<vec[j+k]<<endl;
					exchange(vec[j],vec[j+k]);
					//cout << "exchange "<< vec[j]<< " and "<<vec[j+k]<<endl;
					j = j-k;
				} else {
					j = 0;// pour sortir de la boucle.
				}
			}
		}
	}
}		
