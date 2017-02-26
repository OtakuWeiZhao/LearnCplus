#include <iostream>

using namespace std;

template <class T>
T Max( T m1, T m2 )
{
	return( (m1 > m2) ? m1 : m2);
}


int main()
{
	cout	<< Max( 2, 5 ) << "\t" << Max( 2.0, 5.0 ) << "\t"
		<< Max( 'w', 'a' ) << "\t" << Max( "ABC", "ABD" ) << "\t" << endl;
		return 0;
}
