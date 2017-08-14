#include <iostream>
#include <vector>

using namespace std;

//Typedef degree.
typedef unsigned int degree;

class Monomial{
	private:
		degree power_;
		double coeficient_;
	public:
		//Constructor.
		Monomial(double coeficient, degree power):coeficient_(coeficient), power_(power)
			{}
		//Getters
		degree power() const { return power_;}
		double coeficient() const { return coeficient_;}

		//Overload operator less than.
		bool operator<(Monomial const&) const;

};

//Typedef vector monomial.
typedef vector<Monomial> monomials;

class Polynomial{
	private:
		monomials terms_;
		static double x_;

	public:
		//Default construct.
		//Polynomial():x_(0) {}

		//Getters
		monomials terms() const {return terms_;}
		static double x() {return x_;} 
		
		//Setters
		static void x(double n){
			x_= n;
		}
		//Add monomials.	
		void addMonomials(Monomial const&);
		
		//Decremental order.
		void exchange(Monomial&, Monomial&);
		void reorder();

};


//Prototypes functions
double userCoef();
Polynomial polyMaker();

//Operators
ostream& operator<<(ostream&, Monomial const&);
ostream& operator<<(ostream&, Polynomial const&);

//Initialisation of the variable.
double Polynomial::x_(0.0);
//------------------------------------------------------//Main
int main(){
	Monomial mone(-3.5,1);//test monomial.
	Monomial motwo(5.0,3);//test monomial.
	Monomial mothree(7.0,4);//test monomial.
	
	//test polynomial ostream.
	Polynomial p;
	p.addMonomials(mone);
	p.addMonomials(mothree);
	p.addMonomials(motwo);
	
	cout << "p = "<<p << endl;
	//reorder the polynome.
	p.reorder();
	cout << "p = "<<p << endl;
	return 0;
}
//----------------------------------------------------// End main.
/**
 * Ask the coeficient number to the user.
 * @return: return the user input.
 */
double userCoef(){
	double coef(0);
	bool isCorrect;
	
	do{
		cout << "Type your coeficient number: ";
		if(!(cin>>coef)){
			cin.clear();
			cin.ignore(1000,'\n');
			cout << "number only please"<<endl;
			isCorrect = false;
		} else {
			isCorrect = true;
		}
	}while(not isCorrect);
}

//ostream for monomial.
ostream& operator<<(ostream& out, Monomial const& mono){
	if(mono.coeficient() != 0 && mono.power() > 0){
		out << mono.coeficient() << "x^"<<mono.power();
	}
	return out;
}

//ostream for polynomial.
ostream& operator<<(ostream& out, Polynomial const& poly){
	string sign;
	for(size_t i(0); i < poly.terms().size(); ++i){
		if(i==0 and poly.terms()[i].coeficient() > 0.0 ){
			sign = "";
		} else {
			sign = poly.terms()[i].coeficient() > 0.0 ? "+":"";
		}
		if( poly.terms()[i].power() == 1){
			out << sign <<poly.terms()[i].coeficient() << "x";	
		} else {
			out << sign <<poly.terms()[i].coeficient() << "x^"<< poly.terms()[i].power();	
		}
	}
	return out;
}

/**
 *Add monomials
 */
void Polynomial::addMonomials(const Monomial&  monom){
	terms_.push_back(monom);
}

/**
 * Exchange the monomials position in the array. 
 * @param: the first monomial.
 * @param: the second monomial.
 */
void Polynomial::exchange(Monomial& one, Monomial& two){
	Monomial temp(one);
	one = two;
	two = temp;
}

/**
 *  
 */
void Polynomial::reorder(){
//	exchange(p.terms_[0],p.terms_[2]);
	for(size_t k(terms().size()/2); k > 0; k/= 2){
		for(size_t i(k+0); i < terms().size(); ++i){
				int j(i-k);
				if(j == 0){
					if(terms()[j]  < terms()[j+k]){
						exchange(terms_[j],terms_[j+k]);
					}
				}
				while(j > 0){
					if(terms()[j]  < terms()[j+k]){
						exchange(terms_[j],terms_[j+k]);
						j = j-k;
					} else {
						j = 0;
					}
				}
		}
	}
}


bool Monomial::operator<(Monomial const& mo) const{
	return (power() < mo.power() or coeficient() < mo.coeficient());
}
