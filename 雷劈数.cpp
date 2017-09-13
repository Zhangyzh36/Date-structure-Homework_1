#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	for (int i = 4; i * i < 99999999; ++i )
	{
		int num = i * i;
		int a = num;
		int b = 0;
		int exp = 0;
		while ( a != 0 ) {
			b += ( a % 10 ) * pow( 10, exp ); 
			a /= 10;
			exp++;
			
			if ( a + b == i )
			{
				cout << num << endl;
				break;
			}
			
		}	
	}
	
	return 0;
}
