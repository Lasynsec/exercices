#include <iostream>

using namespace std;

//class
class Complexe{
	private:
		double x_;
		double y_;
	
	public:
		Complexe(double x=0.0,double y=0.0)
			:x_(x),y_(y)
		{}
		
		//prototypes
		bool operator==(Complexe const& z) const;
		Complexe& operator+=(Complexe const& z2);
		Complexe& operator-=(Complexe const& z2);
		Complexe& operator/=(Complexe const& z2);
		Complexe& operator*=(Complexe const& z2);
	
		//Getters
		double x() const {return x_;}
		double y() const {return y_;}

};
//Prototypes
ostream& operator<<(ostream& output, Complexe const& z);
const Complexe operator+(Complexe z1, Complexe const& Z2);
const Complexe operator*(Complexe z1,Complexe const& z2);
const Complexe operator/(Complexe z1,Complexe const& z2);

int main(){
	Complexe defaut;
	Complexe zero(0.0,0.0);
	Complexe one(1.0,0.0);
	Complexe i(0.0,1.0);
	Complexe j;
	
	cout << zero<<"=="<<defaut;
	if(zero==defaut) cout <<" = oui"<<endl;
		else cout << "= non"<< endl;

	cout << zero<<"=="<<i;
	if(zero==i) cout <<" = oui"<<endl;
		else cout << " = non"<< endl;

	j = one + i;
	cout << one << " + "<< i << " = "<< j << endl;
	
	Complexe three(one);
	three += one;
	three += 1.0;
	cout << one << " + " << one << " + 1.0 = "<< three<<endl;

	Complexe two(three);
	two -= one;
	cout << three << " - " << one << " = " << two << endl;

	Complexe z(i*i);
	cout << i << " * "<< i << " = " << z <<endl;
	cout << z << " / "<< i << " = " << z/i <<" = "<<(z/=i)<<endl;	

	Complexe k(2.0,-3.0);
	z = k;
	z *= 2.0;
	z *= i;
	cout << k << "* 2.0 *" << i << " = "<< z << endl;
	z = 2.0 * k * i / 1.0;
	cout << " 2.0 * "<< k << " * " << i << " / 1 = "<< z << endl;
	return 0;
}

ostream& operator<<(ostream& output, Complexe const& z){
	output << '('<<z.x()<<", "<<z.y()<<')';
	return output;
}

bool Complexe::operator==(Complexe const& z) const{
	return (x_ == z.x() && y_ == z.y());
}

const Complexe operator+(Complexe z1, Complexe const& z2){
	return Complexe (z1.x() + z2.x(), z1.y() + z2.y());
}

Complexe& Complexe::operator+=(Complexe const& z2){
	x_ += z2.x();
	y_ += z2.y();
	return *this;
}

Complexe& Complexe::operator-=(Complexe const& z2){
	x_ -= z2.x();
	y_ -= z2.y();
	return *this;
}

const Complexe operator*(Complexe z1, Complexe const& z2){
	return Complexe (z1.x() * z2.x() - z1.y() * z2.y(), z1.x() * z2.y() + z1.y() + z2.x());
}

const Complexe operator/(Complexe z1,Complexe const& z2){
	return Complexe ((z1.x() * z2.x() + z1.y() * z2.y()) / (z2.x() * z2.x() + z2.y() * z2.y()), (z1.y() * z2.x() - z1.x() + z2.y()) / (z2.x() * z2.x() + z2.y() * z2.y()));
}

Complexe& Complexe::operator/=(Complexe const& z2){
	x_ = (x_ * z2.x() + y_ * z2.y()) / (z2.x() * z2.x() + z2.y() * z2.y());
	y_ = (y_ * z2.x() - x_ + z2.y()) / (z2.x() * z2.x() + z2.y() * z2.y());
	return *this;
}
Complexe& Complexe::operator*=(Complexe const& z2){
	x_ = x_ * z2.x() - y_ * z2.y();
	y_ = x_ * z2.y() + y_ + z2.x();
	return *this;
}	
