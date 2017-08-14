#include <iostream>
#include <string>

using namespace std;

class Costumer{
	private:
		string name_;
		string city_;
		double current_;
		double savings_;
		bool gender_;

	public:
		Costumer(string n,string c, double cu,double sa, bool gender)
			:name_(n),city_(c),current_(cu),savings_(sa),gender_(gender)
		{}
		//Getters
		string name() const { return name_; }
		string city() const { return city_; }
		double current() const { return current_; }
		double savings() const { return savings_; }
		bool gender() const { return gender_; }

		//Setters
		void current(double cu){ 
			current_ = cu;
		}

		void savings(double sa){
			savings_ = sa;
		}
};

class Rate{
	private:
		double current_;
		double savings_;
	public:
		Rate():current_(0.01),savings_(0.02){}

		double current() const { return current_; }
		double savings() const { return savings_; }
};

void display(const Costumer& client){
	string gender = (client.gender() ? "Mr":"Ms");
	cout << gender << " "<<client.name() << " from "<<client.city()<<endl;
	cout << "- Current account : " << client.current()<<" dollars"<<endl;
	cout << "- savings account : " << client.savings()<<" dollars"<<endl;
}

void addInterests(Costumer& client, Rate& rate) {
	double interestCurrent(rate.current() * client.current());
	double interestSavings(rate.savings() * client.savings());

	client.current(client.current() + interestCurrent);
	client.savings(client.savings() + interestSavings);
}

int main()
{
	Rate rate;
	cout <<"Statement before the closing of accounts : "<<endl;	
	Costumer pedro("Pedro","Genève",1000.0,2000.0,1);
	display(pedro);
	Costumer alex("Alexandra","Lausane",3000.0,4000.0,1);
	display(alex);
	Costumer laura("Laura","Paris",5000.0,10000.0,0);
	display(laura);
	cout << endl;
	addInterests(pedro,rate);
	addInterests(alex,rate);
	addInterests(laura,rate);
	cout <<"Statement after the closing of accounts : "<<endl;	
	display(pedro);
	display(alex);
	display(laura);
	return 0;
}
