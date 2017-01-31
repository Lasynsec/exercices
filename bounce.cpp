/**
*  
*/
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main()
{
		const double g(9.81);		 // const of gravitational acceleration.
		double heightAfterAscent(0); //   

		cout << " Give a number of bounces greater than 0 ? : ";
		int nbrOfBounce(0); // will receive the input of the user.
		cin >> nbrOfBounce; // return the input value into the variable(number of bounce for the ball).

		cout << " Give a initial height  greater than 0 : ? ";
		double initialHeight(0.0); // will receive the input of the user.
		cin >>  initialHeight;     // return the input value into the variable(start height). 
			
		cout << " Give an EPS  greater than 0 and less 1 : ? ";
		double eps(0.0); // will receive the input of the user.
		cin >> eps;
		cout << endl;
		
		if((nbrOfBounce < 0) || (eps < 0 || eps > 1) || (initialHeight < 0)){
			cout << " Your inputs are not correct !!!" << endl;
		} else {

			for(size_t i = 0; i < nbrOfBounce; i++){
			
				double speedBeforeBounce(0.0); // will receive the velocity before the ball touches the ground.
				speedBeforeBounce = sqrt(2.0 * initialHeight * g); /*the fall before the bounce.*/ 

				double speedAfterBounce(0.0); // will receive the velocity after the ball has touched the ground.
				speedAfterBounce = eps * speedBeforeBounce; /* speed after bouncing */

				 heightAfterAscent = (speedAfterBounce * speedAfterBounce) / (2.0 * g); /*height*/
				initialHeight =  heightAfterAscent; 

			}
		}
		cout << heightAfterAscent << endl;
	return 0;
}
