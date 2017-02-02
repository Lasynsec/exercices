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
	
int main()
{
	Complex z1 = {-2.0, 5.0};
	Complex z2 = {1.0, -3.0};
	
	Result z;

	//addition(z1,z2,z);
	//substraction(z1,z2,z);
	multiplication(z1, z2, z);

	display(z);

	return 0;
}

/**
 * The sum
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
 * The difference
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
 *
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

/**
 *
 */
void display(Result const& z)
{
	cout << "(" << z.reel << ", " << z.imagin << ")"<< endl;
}
