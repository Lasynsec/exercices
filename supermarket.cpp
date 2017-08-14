#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Item{
	private:
		string name_;
		double price_;
		bool onSale_;
	public:
		Item(string name, double price, bool onSale)
			: name_(name), price_(price), onSale_(onSale)
		{}

		//Getters
		string name() const { return name_; }
		double price() const { return price_; }
		bool onSale() const {return onSale_; }

};

class Buyings{
	private:
		Item item_;
		int quantity_;
	public:
		Buyings(string name, double price, bool onSale, int quantity)
			:item_(name, price, onSale),quantity_(quantity)
		{}

		void display(){
			string onsale = (item_.onSale() ?"(on sale)":"" );
			cout << item_.name() <<" : " << item_.price() << " x " <<quantity_<<" = "<< item_.price() * quantity_<<" "<< onsale <<"\n";	
		}
		
		//Getters
		Item item() const { return item_;}
		int quantity() const { return quantity_;} 
};

typedef vector<Buyings> buyingsvec;
class Cart{
	private:
		buyingsvec buyings_;

	public:
		void fill(Buyings buyings){
			buyings_.push_back(buyings);
		}

		//Getter
		buyingsvec buyings() const{ return buyings_; }
};

typedef vector<Cart> carts; 
class CashRegister{
	private: 
		double total_;
		double totalCashier_;
		int number_;
		carts cartvec_;
	public:

		//Getters
		double totalCashier() const { return totalCashier_; }
		
		//Setters
		double scanning(Cart& cart){
			double amount(0);
			cartvec_.push_back(cart);

		}

		void display(){
			double amount(0);
			cout<<endl;
			for(size_t i(0); i < cartvec_.size(); ++i){
				for(size_t j(0); j < cartvec_[i].buyings().size(); ++j){
					amount	= cartvec_[i].buyings()[j].item().price() * 
							  cartvec_[i].buyings()[j].quantity();

					cout << cartvec_[i].buyings()[j].item().name()<<" : "<< 
						cartvec_[i].buyings()[j].item().price()<<" x "<<
						cartvec_[i].buyings()[j].quantity()<<" = "<< amount<<"$ \n";

					total_ += amount;
			}
			cout<<"-----\n";
			cout <<"The bill is :"<<total_<<" $\n";
			cout<<"================================================\n";
			totalCashier_+= total_;
		}
	}
};

//Typedef.
typedef vector<CashRegister> Cashregisters; 

//Main code
int main(){
	Buyings choufleur("Chou-fleur extra",3.50,true,2);
	Buyings roman("Les malheurs de Sophie",16.50,true,1);
	Buyings cdrom("Thriller",18.50,true,1);
	Buyings cremeux("Creumeux 100%",5.50,true,1);
	Buyings c("C++ en trois jours",48.50,true,1);
	Buyings lait("Petit-lait",2.50,true,2);
	Buyings sardines("Sardines",4.50,false,1);
	Buyings arabica("Arabica",6.50,false,3);
	Buyings pain("Pain d'epautre",1.50,true,3);
	
	carts cart(5); //initialisation of two carts.
	//cart one.
	cart[0].fill(choufleur);// fill the cart with an item. 
	cart[0].fill(roman);// fill the cart with an other item.

	//cart two.
	cart[1].fill(cdrom);// fill the cart with an item.
	cart[1].fill(cremeux);//fil the cart with another item.

	//cart three.
	cart[2].fill(c);// fill the cart with an item.
	cart[2].fill(lait);//fil the cart with another item.
	
	//cart four.
	cart[3].fill(sardines);// fill the cart with an item.
	cart[3].fill(arabica);//fil the cart with another item.
	//cart five.
	cart[4].fill(pain);//fil the cart with another item.

	//Scannig cart with the cashregister.
	Cashregisters cashregister(3);	// Initialisation of a cash register.
	cashregister[0].scanning(cart[0]);//cash register 1.
	cashregister[0].scanning(cart[1]);//cash register 2.
	cashregister[1].scanning(cart[2]);//cash register 3.
	cashregister[1].scanning(cart[3]);//cash register 4.
	cashregister[2].scanning(cart[4]);//cash register 5.

	for(size_t i(0); i < cashregister.size(); ++i){
		cashregister[i].display();
	}
	cout<<"The result of the day is : \n";
	for(size_t i(0); i < cashregister.size(); ++i){
		cout << "Cash register "<<i+1 << " : "<<cashregister[i].totalCashier()<<" $ \n";
	}
	return 0;
}

