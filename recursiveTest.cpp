#include <iostream>
#include <iostream>

using namespace std;

// prototypes
int puissance(int a, int n);

int main()
{
	int p;
	p=puissance(2,3);
	cout << p << endl;
	return 0;
}

int puissance(int a, int n)
{
	if(n == 0)
	{
		return (1);
	}

	return a * puissance(a,n-1);
}

