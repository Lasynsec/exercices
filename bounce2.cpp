#include <iostream>
#include <math.h>

using namespace std;

int main()
{	
	const double g(9.81);
	double heightAfterAscent(0);

	cout << " give an initial height greater than 0 ! : "; 
	double ho(0);
	cin >> ho;

	cout << " Give an eps greater and equal to 0 and less than 1 ! : ";
	double eps(0);
	cin >> eps;

	cout << " Give a final height greater than 0 and less than initial height ! : ";
	double h_fin(0);
	cin >> h_fin;
	
	cout << endl;

	int bounce(0);

	do {
		bounce++;
		double speedBeforeBounce(0.0);
		speedBeforeBounce = sqrt(2.0 * ho * g);

		double speedAfterBounce(0.0);
		speedAfterBounce = eps * speedBeforeBounce;

		heightAfterAscent = (speedAfterBounce * speedAfterBounce) / (2.0 * g);
		ho = heightAfterAscent;

	}while(h_fin <= heightAfterAscent);
	cout << bounce << endl;
	return 0;
}
