#include <iostream>
#include <array>
#include <math.h>
#include <string>

using namespace std;

//Typdef
typedef array<double,2>coordinates;

//The classe
class Circle
{
	public:

		// Calculate the circle surface.
		double surface() const {
				return M_PI * pow(radius_,2.0); 
		}

		bool isInside(double x, double y) const {
			bool inside;
			if(((x - center_[0]) + (y - center_[1])) <= radius_){
				inside = true;
			} else {
				inside = false;
			}
			return inside;
		}
		//Members functions Getters
		double radius() const{
			return radius_;
		}
		coordinates center() const{
			return center_;
		}

		// Members functions Setters
		void center(coordinates& center){
			center_ = center;
			
		}

		void radius(double rad){
			radius_ = rad;
		}

	private:
		//members
		double radius_;	
		coordinates center_;
};

int main(){
	Circle circ;
	coordinates coord = {3.0,4.0};

	circ.radius(5.0);
	circ.center(coord);

	cout <<"The radius is "<<circ.radius()<<endl;
	cout <<"The coordinate (x) is "<<circ.center()[0]<< ", the coordinate (y) is "<< circ.center()[1]<<endl;
	cout <<"The surface "<< circ.surface()<<"\n";
	string answer(circ.isInside(1.0,2.0) ? "yes" : "false");

	cout << "Is the point A(1,2) in the circle ? "<< answer<<"\n";
	
	return 0;
}
