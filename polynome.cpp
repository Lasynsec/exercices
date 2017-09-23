#include <iostream>
#include <vector>
#include <array>
#include <stdlib.h> //for debugging

using namespace std;


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

		//Add a monomial in the .	
		void addMonomials(Monomial const&);
		void addMonomials(monomials const&);
		
		//Decremental order.
		void exchange(Monomial&, Monomial&);
		void exchange(Polynomial&);
		void reorder();
		void reorder(result&);

		//Overload operator
		Polynomial operator*(const Polynomial&) const; //done. 
		Polynomial operator*(double) const;//done.
		Polynomial& operator*=(const Polynomial&); //done.
		Polynomial& operator*=(double); //done.
		Polynomial& operator+=(const Polynomial&); //working on it.

		
		//Simplified the result.
		void simplification();
		void simplification(result&);
};



//External overload operator.
ostream& operator<<(ostream&, Monomial const&);
ostream& operator<<(ostream&, Polynomial const&);
Polynomial operator*(double, Polynomial const&);

//Prototypes functions
double userCoef();
Polynomial polyMaker();
void debuggingMulti(Polynomial&,const Polynomial&);
void debuggingAddi(Polynomial&,const Polynomial&);

//------------------------------------------------------//Main.
int main(){
	Monomial one(2.0,2);//test monomial.
	Monomial two(-5.0,1);//test monomial.
	Monomial three(-1.0,0);//test monomial.
	//--*
	Monomial four(-1.0,2);//test monomial.
	Monomial five(-15.0,1);//test monomial.
	Monomial six(-6.0,2);//test monomial.
	//--*
	Monomial seven(9.0,2);//test monomial.
	Monomial eight(-5.0,1);//test monomial.
	Monomial nine(-3.0,0);//test monomial.
	//--*
	Monomial ten(-6.0,2);//test monomial.
	Monomial eleven(-4.0,1);//test monomial.
	Monomial twelve(-7.0,0);//test monomial.

	Polynomial p1;
	p1.addMonomials((monomials){one,two,three});//cast the unknown vector for the function argument.
	
	Polynomial p2;
	p2.addMonomials((monomials){four,five});
	
	Polynomial p3;
	p3.addMonomials((monomials){seven,eight,nine});

	Polynomial p4;
	p4.addMonomials((monomials){ten,eleven,twelve});

	Polynomial p5;
	p5.addMonomials(six);
/*	
	cout <<"("<<p1 <<")"<< " *= "<<"("<< p2<<")"<< " = ";
	cout << (p1*=p2) <<endl;// we multiply here.
	Polynomial r(p3*p4);
	cout <<"("<<p3<<")"<< " * "<<"("<< p4<<")"<< " = "<< r <<endl;// we multiply here
	cout <<"("<<p2<<")"<< " * "<<"(5)"<< " = "<< p2*5.0 <<endl;// we multiply here.
	cout <<"("<<p4<<")"<< " *= "<<"(7)"<< " = ";
	cout << (p4*=7.0) << endl;// we multiply here.
	cout <<"(8)"<<" * ("<<p5<<")"<< " = ";
	cout << 8.0*p5 << endl;// we multiply here.
*/
	cout<<"("<<p1<<")"<<" + " <<"("<<p2<<")"<<" = "<<(p1+=p2)<<endl;
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

void Polynomial::addMonomials(monomials const& monov){
	for(size_t i(0);  i < monov.size();++i){
		terms_.push_back(monov[i]);
	}
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
 * Overload operator to multiply a monomial by another one.
 */
Polynomial& Polynomial::operator*=(const Polynomial& poly){
		//If we need to extend the terms vector.
		bool needAddon(true);
		
		//The difference of monomials between P and Q.
		int difference = poly.terms().size() - terms().size();
		
		//Get the size of vector Q.
		int sizeOfQ = poly.terms().size();
		
		//Get size of the vector P.
		int sizeOfP = terms().size();

		//Create  a subvector for the vector terms().
		monomials *addon;

		/**
		 * Use dynamic allocation to merge a temp vector to term vector. 
		 */
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
			}
		}else{ 
			int termSize = terms().size();
			if(difference == -1){
				if(termSize == 3 and sizeOfQ == 2){
					addon = new monomials(2);
				}else if(termSize == 2 and sizeOfQ == 1){
					//addon = new monomials(1);
					needAddon = false;
				}
			}else if(difference == -2){
				if(termSize == 3 and sizeOfQ == 1){
					addon = new monomials(1);
				}
			}
		}
		if(needAddon){
			monomials inserting;
			inserting = (*addon); //Affect the value of object pointed.

			//Insert the addon pointer vector into the terms vector for the result.
			terms_.insert(terms_.end(), inserting.begin(), inserting.end());//add in the end of the terms vector the pointer vector.
		}
		
		/**
		 * We create dinamycally 15 elements in the res vector if not there are not already there  
		 */
		bool needAddonRes(false);
		monomials *addonRes; 
		if(res().size() == 0){
			addonRes = new monomials(15);
			res().insert(res().begin(), (*addonRes).begin(), (*addonRes).end());
			needAddonRes = true;
		}
		/**
		 * The loop will multiplicate the two polynomials.
		 * and put the founded new monomials in a vector(res_).
		 */
		size_t v(0);
		for(size_t i(0); i < terms().size(); ++i){
			for(size_t j(0); j < poly.terms().size(); ++j){
				res()[v].power(terms()[i].power() + poly.terms()[j].power()); // The addition of the exposant 'monomials from each polynomials.
				res()[v].coeficient(terms()[i].coeficient() * poly.terms()[j].coeficient()); //The multiplication of monomials from each polynomials.
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
		}

		if(needAddonRes){
			delete addonRes;
		}

		//we simplifly the result of the main poly (p).
		simplification(); 
		reorder();

		//The pointeris must be anyway pointed to null.
		addon = 0; 
		addonRes = 0;

		return *this;
}
/**
 * Overload operator for the addition.
 */
Polynomial& Polynomial::operator+=(const Polynomial& poly){
	for(size_t i(0); i < terms().size(); ++i){
		for(size_t j(0); j < poly.terms().size();++j){
			if(terms()[i].power() == poly.terms()[j].power()){
				terms_[i].coeficient(terms()[i].coeficient()+poly.terms()[j].coeficient());
			}
		}
	}
	//debuggingAddi(*this,poly);
	return *this;
}
//-------------internal Overload operator* methode*.
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

/**
 * 
 */
Polynomial& Polynomial::operator*=(double d){
	return (*this *= Polynomial(d)); 	
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


//************externalt Overload operator function.
/*
 */
Polynomial operator*(double d, Polynomial const& c){
	return (Polynomial(d) * c);
}

//------------//Debug
/**
 * Fonction for debugging the multiplication operators
 * @argm: two polynomials objects.
 */
void debuggingAddi(Polynomial& p,const Polynomial& poly);
void debuggingMulti(Polynomial& p,const Polynomial& poly){
	cout << "p.perms:";
	for(size_t i(0); i < p.terms().size();++i){
		cout << "["<<p.terms()[i].coeficient()<<"x^"<<p.terms()[i].power()<<"] ";	
	}
	cout <<endl;
	cout << "poly.perms:";
	for(size_t i(0); i < poly.terms().size();++i){
		cout << "["<<poly.terms()[i].coeficient()<<"x^"<<poly.terms()[i].power()<<"] ";	
	}
	cout <<endl;
	cout<<"------"<<endl;	
	size_t v(0);
	for(size_t i(0); i < p.terms().size(); ++i){
		for(size_t j(0); j < poly.terms().size(); ++j){
			cout << "p.res("<<"power of p["<<i<<"]->"<<p.terms()[i].power()
				<<" + "<< "power of poly["<<j<<"]->"<<poly.terms()[j].power()
				<<")="<<p.terms()[i].power()+poly.terms()[j].power()<<endl; // The addition of the exposant 'monomials from each polynomials.
			cout << "p.res("<<"coeficient of p["<<i<<"]->"<<p.terms()[i].coeficient()
				<<" * "<< "coeficient of poly["<<j<<"]->"<<poly.terms()[j].coeficient()
				<<")="<<p.terms()[i].coeficient()*poly.terms()[j].coeficient()<<endl; //The multiplication of monomials from each polynomials.
			++v;
		}
		cout<<"-----"<<endl;
	}

	cout << "p.res..."<<endl;
	for(size_t i(0); i < p.res().size();++i){
		cout <<"["<<i<<"]"<<p.res()[i].coeficient()<<"^"<<p.res()[i].power()<<endl;	
	}

	cout<<"The value of p is: "<<p<<endl;
	cout<<"The value of poly is: "<<poly<<endl;
	abort();
}
/**
 * Fonction for debugging the addition operators
 * @argm: two polynomials objects.
 */
void debuggingAddi(Polynomial& p,const Polynomial& poly){
	cout << "p.perms:";
	for(size_t i(0); i < p.terms().size();++i){
		if(p.terms()[i].power() > 0){
			cout << "["<<p.terms()[i].coeficient()<<"x^"<<p.terms()[i].power()<<"] ";	
		} else {
			cout << "["<<p.terms()[i].coeficient()<<"] ";	
		}
	}
	cout <<endl;
	cout << "poly.perms:";
	for(size_t i(0); i < poly.terms().size();++i){
		if(poly.terms()[i].power() > 0){
			cout << "["<<poly.terms()[i].coeficient()<<"x^"<<poly.terms()[i].power()<<"] ";	
		} else {
			cout << "["<<poly.terms()[i].coeficient()<<"] ";	
		}
	}
	cout <<endl;
	cout<<"------"<<endl;	
	for(size_t i(0); i < p.terms().size(); ++i){
		for(size_t j(0); j < poly.terms().size(); ++j){
			if(p.terms()[i].power() == poly.terms()[j].power()){
				cout<< "("<<p.terms()[i].coeficient()<<")"<<" + "<<"("<<poly.terms()[j].coeficient()<<")"<<" = "<<p.terms()[i].coeficient()+poly.terms()[j].coeficient()<<endl;
			}
		}
		cout<<"-----"<<endl;
	}
/*
	cout << "p.res..."<<endl;
	for(size_t i(0); i < p.res().size();++i){
		cout <<"["<<i<<"]"<<p.res()[i].coeficient()<<"^"<<p.res()[i].power()<<endl;	
	}
*/
	cout<<"The value of p is: "<<p<<endl;
	cout<<"The value of poly is: "<<poly<<endl;
	abort();
}

