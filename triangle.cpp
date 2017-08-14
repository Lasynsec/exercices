#include <iostream>
#include <string>
#include <cmath>
#include <string>

using namespace std;

class Point
{
	public:

		/**
		 * Getters
		 */
		double x() const { return x_;}
		double y() const { return y_;}
		double z() const { return z_;}
/*
*/
		/**
		 * Setters
		 */
		void x(double x){
			x_ = x;
		}

		void y(double y){
			y_ = y;
		}

		void z(double z){
			z_ = z;
		}
/*
*/
	private:
		double x_;
		double y_;
		double z_;
};

class Triangle{
	public:
		/**
		 * Calculate the perimeter from the given coordinate.
		 * @param: the coordinates for the perimeter.
		 * @return: the parameter.
		 */
		double calculatePerimeter(Point point1, Point point2, Point point3){
			double perimeter(0.0);
			double distanceAB(this->distanceOfPoint(point1,point2));
			double distanceBC(this->distanceOfPoint(point2,point3));
			double distanceAC(this->distanceOfPoint(point1,point3));

			perimeter = distanceAB + distanceBC + distanceAC;

			return perimeter;
		}
		/**
		 * Is the triangle isoscele.
		 * @param: 
		 * @return: the triangle's perimeter.
		 */
		bool isIsoscele(Point point1, Point point2, Point point3){
			
			bool isoscele;

			double distanceAB(this->distanceOfPoint(point1,point2));
			double distanceBC(this->distanceOfPoint(point2,point3));
			double distanceAC(this->distanceOfPoint(point1,point3));
			
			if((distanceAB == distanceAC) || 
			   (distanceBC == distanceAC)||
			   (distanceAB == distanceBC)){
				isoscele = true;
			} else {
				isoscele = false;
			}
				return isoscele;
		}
		/**
		 * Calculate the distance between to point.
		 * @param: The two point needed for calculating the distance.
		 * @return: return the distance of the both points.
		 */
		double distanceOfPoint(Point point1, Point point2){
			double theDistance(0.0);
			theDistance =	sqrt(pow(point1.x() - point2.x(),2) + 
								 pow(point1.y() - point2.y(),2) + 
								 pow(point1.z() - point2.z(),2));	
				return theDistance;
		}
		/**
		 * Getter
		 */
		Point a() const {return a_;}
		Point b() const {return b_;}
		Point c() const {return c_;}
		
		/**
		 * Setter
		 */
		void a(Point a){
			a_ = a;
		}
		void b(Point b){
			b_ = b;
		}
		void c(Point c){
			c_ = c;
		}

	private:
		Point a_;
		Point b_;
		Point c_;
};
/**
 * As for a number to the user.
 * @param: the name of each coordinate.
 * @return: the number typed by the user.
 */
double coordinate(char coordiName){
	bool isCorrect(true);
	double coordinate(0.0);
	do{
		cout << "Type a number for the " << coordiName << " coordinate. : ";
		if(!(cin>>coordinate)){
			isCorrect = false;
			cin.clear();
			cin.ignore(1000,'\n');
			cout << "Number only please !\n";

		}
	}while(not isCorrect);
	return coordinate;
}
int main(){
	Point point1;
	Point point2;
	Point point3;

	cout << "Point A:\n";
	point1.x(coordinate('x'));
	point1.y(coordinate('y'));
	point1.z(coordinate('z'));
	cout << endl;
	cout << "Point B:\n";
	point2.x(coordinate('x'));
	point2.y(coordinate('y'));
	point2.z(coordinate('z'));
	cout << endl;
	cout << "Point C:\n";
	point3.x(coordinate('x'));
	point3.y(coordinate('y'));
	point3.z(coordinate('z'));

	Triangle triangular;
	triangular.a(point1);
	triangular.b(point2);
	triangular.c(point3);
	cout << endl;
	cout <<"The perimeter of the triangle is : "<< triangular.calculatePerimeter(triangular.a(),triangular.b(), triangular.c())<<"\n";
	
	string isOrNot = triangular.isIsoscele(triangular.a(), triangular.b(), triangular.c()) ?"is an":"is not an";
	cout << "The triangle "<<isOrNot<<" isoscele !\n";
	return 0;
}
