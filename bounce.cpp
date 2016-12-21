#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main()
{
		const double g(9.81);
		double heightAfterAscent(0);

		cout << " Give a number of bounces greater than 0 ? : ";
		int nbrOfBounce(0);
		cin >> nbrOfBounce;

		cout << " Give a initial height  greater than 0 : ? ";
		double initialHeight(0.0);
		cin >>  initialHeight;
			
		cout << " Give an EPS  greater than 0 and less 1 : ? ";
		double eps(0.0);
		cin >> eps;
		cout << endl;
		
		if((nbrOfBounce < 0) || (eps < 0 || eps > 1) || (initialHeight < 0)){
			cout << " Your inputs are not correct !!!" << endl;
		} else {

			for(size_t i = 0; i < nbrOfBounce; i++){
			
				double speedBeforeBounce(0.0);
				speedBeforeBounce = sqrt(2.0 * initialHeight * g); /*the fall before the bounce.*/ 

				double speedAfterBounce(0.0);
				speedAfterBounce = eps * speedBeforeBounce; /* speed after bouncing */

				 heightAfterAscent = (speedAfterBounce * speedAfterBounce) / (2.0 * g); /*height*/
				initialHeight =  heightAfterAscent; 

			}
		}
		cout << heightAfterAscent << endl;
	return 0;
}
