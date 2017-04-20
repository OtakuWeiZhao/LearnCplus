#include <iostream>

using namespace std;

class Point {
private:
	int x, y;
public:
	Point( int = 0, int = 0 );
	~Point();
};
Point::~Point()
{
	cout << "Destructor" << endl;
}


Point::Point( int a, int b ) : x( a ), y( b )
{
	cout << "Initializing " << a << "," << b << endl;
}


int main()
{
	Point A( 5, 68 );


	cout << "Exiting main" << endl;
	return(0);
}
/**
Output
Initializing 5,68
Exiting main
Destructor
*/
