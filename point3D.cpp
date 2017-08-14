#include <iostream>
using namespace std;


class Point3D{
	public:
		/**
		 * Will initiate the coordinates
		 * @param: receive the three coordinates for the 3d objects.
		 */
		void initiate(double x, double y,double z){
			if(not x){
				cout << "No the good type from the parameters!";
			} else {
				x_ = x;
				y_ = y;
				z_ = z;
			}
		}

		/**
		 * Will compare the values of two objet's classes.
		 * @param: the object to compare with.
		 * @return: a bool.
		 */
		bool compare(Point3D& point) const{
			bool isSame(false);
			if ((this->x_ == point.x()) && (this->y_ == point.y()) && (this->z_ == point.z())){
				isSame = true;
			}
		}

		/**
		 * Will display the value of the coordindates.
		 *//*
		void display(){
			cout << "X is "<<x_<<", Y is "<<y_<<", Z is "<< z_<<"\n";
		}
*/
		/**
		 * Getter for X
		 */
		double x() const {return x_;} 
		double y() const {return y_;}
		double z() const {return z_;}
	private:
		double x_;
		double y_;
		double z_;
};

//Prototypes
//void display();
ostream& operator<<(ostream& output, Point3D const& d);

int main(){
	Point3D point1;
	Point3D point2;
	Point3D point3;

	point1.initiate(1.0,2.0,-0.1);
	point2.initiate(2.6,3.5,4.1);
	point3 = point1;
	
	cout << "Point1 : "<<point1;
	cout << "Point2 : "<<point2;
	cout << "Point3 : "<<point3;
	
	if(point1.compare(point3)){
		cout << "Point1 and point2 are the same \n";
	} else {
		cout << "Point1 and point2 are not equal \n";
	}
	return 0;
}


ostream& operator<<(ostream& output, Point3D const& d){
	output << "X is "<<d.x()<<", Y is "<<d.y()<<", Z is "<<d.z()<<"\n";
}
