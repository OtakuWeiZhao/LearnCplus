#include <iostream>

using namespace std;

class Point {
private:
	int x, y;
public:
	Point( int = 0, int = 0 );
};

Point::Point( int a, int b ) : x( a ), y( b )
{
	cout << "Initializing " << a << "," << b << endl;
}


int main()
{
	Point A;
	Point B( 15, 25 );


	Point C[2];
}
/**
Output:
Initializing 0,0
Initializing 15,25
Initializing 0,0
Initializing 0,0
 */
