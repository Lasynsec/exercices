#include <iostream>
using namespace std;

//structures
struct Complex {
	double x;
	double y;
};

struct Result {
	double reel;
	double imagin;
};

//prototypes
void display(Result const& z);
Result addition(Complex& z1, Complex& z2, Result& z);
Result substraction(Complex& z1, Complex& z2, Result& z);
Result multiplication(Complex& z1, Complex& z2, Result& z);
Result division(Complex& z1, Complex& z2, Result& z);
//double opposite(Complex& z1, Complex& z2);
double opposite(double z1y, double z2y);

int main()
{
	Complex z1 = {20.0, 4.0};
	Complex z2 = {3.0, 2.0};
	
	Result z;

	//addition(z1,z2,z);
	//substraction(z1,z2,z);
	//multiplication(z1,z2,z);
	division(z1,z2,z);

	display(z);

	return 0;
}

/**
 * The addition
 */
Result addition(Complex& z1, Complex& z2, Result& z)
{
	double reel;
	double imagin;

	reel = z1.x + z2.x;
	imagin = z1.y + z2.y;
	
	z.reel = reel;
	z.imagin = imagin;

	return z; 
}

/**
 * The substraction
 */
Result substraction(Complex& z1, Complex& z2, Result& z)
{
	double reel;
	double imagin;

	reel = z1.x - z2.x;
	imagin = z1.y - z2.y;
	
	z.reel = reel;
	z.imagin = imagin;

	return z;
}

/**
 * The multiplication
 */
Result multiplication(Complex& z1, Complex& z2, Result& z)
{
	double reel;
	double imagin;
 
	reel = z1.x * z2.x;
	cout << "reel "<< reel << endl;
	imagin = z1.x * z2.y;
	cout << "imagin " << imagin << endl;
	
	imagin += z1.y * z2.x;
	cout << " imagin "<< imagin << endl;

	if((z1.y * z2.y) > 1){
		reel += z1.y * z2.y;
	} else if((z1.y * z2.y) == 1){
		reel += -1;
	} else {
		reel += (z1.y * z2.y) -2 * (z1.y * z2.y);
	}
	// reel += (z1.y * z2.y) > 0 ? z1.y * z2.y : (z1.y * z2.y) -2 * (z1.y * z2.y);
	cout << " reel " << reel << endl;
	
	z.reel = reel;
	z.imagin = imagin;

	return z;
	
}
/*
 * Division
 * Imagin result doesn't work well. 
 */
Result division(Complex& z1, Complex& z2, Result& z){
	double reel;
	double imagin;
	double denom;
	double inversed;
	
	reel = (z1.x) * (z2.x);
	//cout << " reel 1: "<< reel << endl;
	inversed = z2.y > 0 ? -(z2.y) : z2.y -2 * z2.y;
	imagin = z1.x * inversed;
	//cout << " imagin 1: "<< imagin << endl; 
	imagin += z1.y * z2.x;
	//cout << " imagin+ : "<< imagin << endl;
	//cout << " opposite "<< opposite(z1.y,z2.y)<< endl;
	reel += opposite(z1.y,z2.y) * -1;
	//cout << " reel+ : "<< reel << endl;

	denom = (z2.x * z2.x) + (z2.y * z2.y);
	z.reel = reel/denom;
	z.imagin = imagin/denom;
	//cout << " Division "<<endl;
	return z;
}
/**
 * Display the result
 */
void display(Result const& z)
{
	cout << "z = (" << z.reel << ", " << z.imagin << ")"<< endl;
}

/*
double opposite(Complex& z1, Complex& z2)

	if((z1.y * z2.y) > 1){
		reel += z1.y * z2.y;
	} else if((z1.y * z2.y) == 1){
		reel += -1;
	} else {
		reel += (z1.y * z2.y) -2 * (z1.y * z2.y);
	}
	
	return reel;
}
*/

double opposite(double z1y, double z2y)
{
	double reel;
	if((z1y * z2y) > 1){
		reel += z1y * z2y;
	} else if((z1y * z2y) == 1){
		reel += -1;
	} else {
		reel += (z1y * z2y) -2 * (z1y * z2y);
	}
	return reel;
}
