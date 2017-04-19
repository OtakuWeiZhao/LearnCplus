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


int main()
{
	Point A;
	Point B( 15, 25 );


	Point	C[2];
	Point	D[2] = { Point( 5, 7 ), Point( 8, 12 ) };
	return 0;
}
/**
output:
Initializing default
Initializing 15,25
Initializing default
Initializing default
Initializing 5,7
Initializing 8,12
*/
