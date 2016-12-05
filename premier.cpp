#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main()
{
	cout << "Write an integer greater than 1 : ";
	int premier(0);
	cin >> premier;
	cout << endl;

	int isPrime(false);
	int isDivisible(0);

	if(premier > 1){
		if(premier % 2 != 0 || premier == 2 ){ /* not even */
			isPrime = true;
			if(premier/premier == 1 || premier/1 == premier){/*is divisible by one or itself*/
				isPrime = true;
				for(size_t i = 1; i <= sqrt(premier); i+= 2){ 
					if((i > 1) && (premier % i == 0)){ /* is divisible by a odd */	
						isPrime = false;
						isDivisible = i;
						break;
					}
				}
			}
		} 
	} else {
		cout << "The number must stricly be greater than 1" << endl;
	}

	if(isPrime){
		cout << premier << " is  prime " << endl;
		
	} else {
		cout << premier  << " is not prime because it's divisible by : " << isDivisible << endl;	
	}
	return 0;
}
