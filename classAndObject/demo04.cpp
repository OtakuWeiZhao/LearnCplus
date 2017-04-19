#include <iostream>

using namespace std;

class Point {
private:
	int x, y;
public:
	Point();
	Point( int, int );
};
Point::Point() : x( 0 ), y( 0 )
{
	cout << "Initializing default" << endl;
}


Point::Point( int a, int b ) : x( a ), y( b )
{
	cout << "Initializing " << a << "," << b << endl;
}


Point global( 5, 7 );


int main()
{
	cout << "Entering main and exiting main" << endl;
	return(0);
}
/**
output:
Initializing 5,7
Entering main and exiting main
*/
