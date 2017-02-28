#include <iostream>

using namespace std;

template <typename T>
T Max( T m1, T m2 )
{
	return( (m1 > m2) ? m1 : m2);
}


template <typename T> /* ±ÿ–Î÷ÿ–¥ */
T Min( T m1, T m2 )
{
	return( (m1 < m2) ? m1 : m2);
}


int main()
{
	cout << Max( "ABC", "ABD" ) << "," << Min( "ABC", "ABD" ) << "," << Min( 'W', 'T' ) << "," << Min( 2.0, 5. );
	cout << "\t" << Min<double>( 8.5, 6 ) << "," << Min( 8.5, (double) 6 ) << "," << Max(( int ) 8.5, 6);
	cout << "\t" << Min<int>( (int)2.3, (int)5.8 ) << "," << Max<int>( 'a', 'y' ) << "," << Max<char>( 95, 121 ) << endl;
	return(0);
}
