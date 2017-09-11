#include <iostream>
#include <vector>
#include <array>
#include <utility>

using namespace std;


//Typedef degree.
typedef unsigned int degree;

/**
 * The class for each monomial.
 */
class Monomial{
	private:
		degree power_;		// The exponant.
		double coeficient_; // The coeficient.

	public:
		/**
		 * The constructor for a monomial with a coeficient and an exponant. 
		 */
		Monomial(double coeficient, degree power):coeficient_(coeficient), power_(power)
			{}
		/**
		 * The constructor for a constant number.
		 */
		Monomial(double coeficient):coeficient_(coeficient),power_(0)
			{}
		/*
		 * Constructor for a monomial with value null.
		 */
		Monomial():coeficient_(0.0), power_(0)
			{}

		//Getters
		degree power() const { return power_;}
		double coeficient() const { return coeficient_;}
		
		//Setters
		void power(degree po){
			power_ = po;
		}

		void coeficient(double coef){
			coeficient_ = coef;
		}

		//Overload operators.
		bool operator<(Monomial const&) const;
		bool operator==(Monomial const&) const;

};

/**
 * Typedef for the monomials vector.
 */
typedef vector<Monomial> monomials;

/**
 * Typedef for the vector result calculated. 
 */
typedef vector<Monomial> result;

/**
 * Class polynomial to manipulate the monomials operation.
 */
class Polynomial{
	private:
		monomials terms_; // The vector for the three monomials.
		monomials res_; // The calculated result.  
	public:

		//Default construct for the founded result.
		Polynomial():res_(15) {}
		//Construct one monomial polynome.
		Polynomial(double coef):terms_(1,coef) {}

		//Getters
		monomials terms() const {return terms_;}
		
		//Setters
		monomials& res() {return res_;} 

		//Add monomials.	
		void addMonomials(Monomial const&);
		
		//Decremental order.
		void exchange(Monomial&, Monomial&);
		void exchange(Polynomial&);
		void reorder();
		void reorder(result&);

		//Overload operator
		Polynomial operator*(const Polynomial&) const; //done. 
		Polynomial operator*(double) const;//working on it.
		Polynomial& operator*=(const Polynomial&); //done.

		
		//Simplified the result.
		void simplification();
		void simplification(result&);
};


//Prototypes functions
double userCoef();
Polynomial polyMaker();

//Operators
ostream& operator<<(ostream&, Monomial const&);
ostream& operator<<(ostream&, Polynomial const&);

//------------------------------------------------------//Main.
int main(){
	Monomial one(2.0,2);//test monomial.
	//Monomial two(-2.0,1);//test monomial.
	//Monomial three(-1.0,0);//test monomial.

	Monomial four(-1.0,2);//test monomial.
	//Monomial five(-15.0,1);//test monomial.
	//Monomial six(-6.0,0);//test monomial.
	
	//test polynomial ostream.
	Polynomial p;
	p.addMonomials(one);
	//p.addMonomials(two);
	//p.addMonomials(three);
	
	Polynomial q;
	q.addMonomials(four);
	//q.addMonomials(five);
	//q.addMonomials(six);

	p.reorder();//check if the polynome is in a decremental organisation.

	//cout <<"("<<p <<")"<< " *= "<<"("<< q<<")"<< "= ";
	//cout << (p*=q) <<endl;// we multiply here.
	Polynomial r(p*q);
	cout <<"("<<p <<")"<< " * "<<"("<< q<<")"<< "= "<< r <<endl;// we multiply here.
	//cout <<"("<<p <<")"<< " * "<<"(5)"<< "= "<< p*6.0 <<endl;// we multiply here.

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
	} else if(mono.coeficient() != 0 && mono.power() == 0){
		out << mono.coeficient();
	}
	return out;
}

//ostream for polynomial.
ostream& operator<<(ostream& out, Polynomial const& poly){
	string sign;
	for(size_t i(0); i < poly.terms().size(); ++i){
		if(i==0 and poly.terms()[i].coeficient() > 0.0){
			sign = "";
		} else {
			sign = (poly.terms()[i].coeficient() > 0.0 ? "+" : "");
		}

		if(poly.terms()[i].power() == 1){
			out << sign <<poly.terms()[i].coeficient() << "x";	
		} else if(poly.terms()[i].power() == 0){
			out << sign <<poly.terms()[i].coeficient();	
		} else {
			out << sign <<poly.terms()[i].coeficient() << "x^"<< poly.terms()[i].power();	
		}
	}
	return out;
}

/**
 *Add a monomial.
 */
void Polynomial::addMonomials(Monomial const&  monom){
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
 * Exchange the polynomials position in the array. 
 * @param: the first polynomails.
 * @param: the second polynomials.
 */
void Polynomial::exchange(Polynomial& p){
	Polynomial temp(*this);
	*this = p;
	p = temp;
}
/**
 * organize the object polynomial in a decremantal manner.
 */
void Polynomial::reorder(){
	for(size_t k(terms().size()/2); k > 0; k/= 2){
		for(size_t i(k+0); i < terms().size(); ++i){
				int j(i-k);
				if(j == 0){
					if(terms()[j]  < terms()[j+k]){
						exchange(terms_[j],terms_[j+k]);
					} else if(terms()[j] < terms()[j+k+1]){
						exchange(terms_[j],terms_[j+k+1]);
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

/**
 * Set a given polynomial in order of powers.
 */
void Polynomial::reorder(result& res){
	for(size_t k(res.size()/2); k > 0; k/= 2){
		for(size_t i(k+0); i < res.size(); ++i){
				int j(i-k);
				if(j == 0){
					if(res[j]  < res[j+k]){
						exchange(res[j],res[j+k]);
					} else if(res[j] < res[j+k+1]){
						exchange(res_[j],res_[j+k+1]);
					}
				}
				while(j > 0){
					if(res[j]  < res[j+k]){
						exchange(res[j],res[j+k]);
						j = j-k;
					} else {
						j = 0;
					}
				}
		}
	}
}

/*
 * use the insertion function to remove the null monomials !!!
 */
void Polynomial::simplification(){
	int index(0);
	for(size_t i(0); i <terms().size(); ++i){
		if(terms()[i].coeficient() == 0 or terms()[i].coeficient() == -0){
			terms_.erase(terms().begin()+i);
		}
	}
}

/*
 * use the insertion function to remove the null monomials !!!

 */
void Polynomial::simplification(result& res){
	int index(0);
	for(size_t i(0); i <res.size(); ++i){
		if(res[i].coeficient() == 0 or res[i].coeficient() == -0){
			res.erase(res.begin()+i);
		}
	}
}

/**
 * Overload operator to find the less value of two monomials.
 */
bool Monomial::operator<(Monomial const& mo) const{
	return (power() < mo.power());
}
/**
 * Overload operator to check if the value of two monomials are the same.
 */
bool Monomial::operator==(Monomial const& mo) const{
	return (power() == mo.power() and coeficient() == mo.coeficient());
}

/**
 * Overload operator two multiply a monomial by another one.
 */
Polynomial& Polynomial::operator*=(const Polynomial& poly){
		bool needAddon(true); //If we need to extend the terms vector.
		//The difference of monomials between P and Q.
		int difference = poly.terms().size() - terms().size();
		
		//Get the size of vector Q.
		int sizeOfQ = poly.terms().size();
		
		//Create  a subvector for the vector terms().
		monomials *addon;
		
		cout <<"poly size "<<sizeOfQ<<", value element: "<< poly.terms()[0].coeficient()<<endl;
		/**
		 * Use dynamic allocation to merge a temp vector to res vector. 
		 */
		cout << "The difference before swap: "<<difference<<endl;
		if(difference > 0){
			if(difference == 1 and sizeOfQ == 3){
				addon = new monomials(3);
			} else if(difference == 1 and sizeOfQ == 2){
				addon = new monomials(2);
			} else if(difference == 2 and sizeOfQ == 3){
				addon = new monomials(3);
			}
		} else if(difference == 0){
			if(sizeOfQ == 2){	
				addon = new monomials(1);
			}else if(sizeOfQ == 3){
				addon = new monomials(2);
			}else{
				needAddon = false; //We doen't need to extend the value.
				cout << "Size of Q is one"<<endl;
			}
		}else{
			cout << "the difference is sub zero."<<endl;
		}
		
		if(needAddon){
			monomials inserting;
			inserting = (*addon); //Affect the value of object pointed.

			//Insert the addon pointer vector into the terms vector for the result.
			terms_.insert(terms_.end(), inserting.begin(), inserting.end());
		}
		/**
		 * The loop will multiplicate the two polynomials.
		 * and put the founded new monomials in a vector(res_).
		 */
		size_t v(0);
		for(size_t i(0); i < terms().size(); ++i){
			for(size_t j(0); j < poly.terms().size(); ++j){
				res()[v].power(terms()[i].power() + poly.terms()[j].power());
				res()[v].coeficient(terms()[i].coeficient() * poly.terms()[j].coeficient());
				++v;
			}
		}
		
		// Set the result in a decremental organisation and simplify.
		reorder(res());
		simplification(res());

		
		/**
		 * build a new polynomial with the addition of the monomials.  
		 */
		double coef(0);
		degree exposant(0);
		int increment(0);
		for(size_t i(0); i < terms().size(); ++i){
				exposant = res()[increment].power();
				if((res()[increment].power() == res()[increment+1].power()) and //if is equal to the second, the third and the fourth power.
						(res()[increment].power() == res()[increment+2].power()) and
						(res()[increment].power() == res()[increment+3].power())){
					terms_[i].coeficient(res()[increment].coeficient()
							+ res()[increment+1].coeficient()
							+ res()[increment+2].coeficient()
							+ res()[increment+3].coeficient());
					terms_[i].power(exposant);
					increment+=3;
				} else if((res()[increment].power() == res()[increment+1].power()) and //if is esqual to the second and the third power.
						(res()[increment].power() == res()[increment+2].power())){
					terms_[i].coeficient(res()[increment].coeficient()
							+ res()[increment+1].coeficient()
							+ res()[increment+2].coeficient());
					terms_[i].power(exposant);
					increment+=2;
				} else if(res()[increment].power() == res()[increment+1].power()){ //if is equal to the second power.
					terms_[i].coeficient(res()[increment].coeficient()+res()[increment+1].coeficient());
					terms_[i].power(exposant);
					++increment;
				} else{//just get the current polynome.
					terms_[i].coeficient(res()[increment].coeficient());
					terms_[i].power(exposant);
				}
				++increment;
		}

		// Let free the memory used by addon.
		if(needAddon){
			delete addon;
			addon = 0;
		}
		//we simplifly the result of the main poly (p).
		simplification(); 
		reorder();

		return *this;
}

/**
 * Overload operator: two multiply a polynomial by another one.
 */
Polynomial Polynomial::operator*(const Polynomial& c) const{ 
	return Polynomial(*this) *= c;
}

/**
 * Overload operator: multiply a polynomial by a double. 
 */
Polynomial Polynomial::operator*(double d) const{
	return Polynomial(*this) *= Polynomial(d);
}

