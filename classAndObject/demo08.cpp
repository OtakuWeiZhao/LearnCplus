#include <iostream>

using namespace std;

class Point {
private:
	int x, y;
public:
	Point( int = 0, int = 0 );
	~Point();
};
Point::Point( int a, int b ) : x( a ), y( b )
{
	cout << "Initializing" << endl;
}


Point::~Point()
{
	cout << "Destructor is active" << endl;
}


int main()
{
	Point *ptr = new Point[2];
	delete[] ptr;
}
/**
Output:
Initializing
Initializing
Destructor is active
Destructor is active
*/
