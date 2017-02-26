#include <iostream>

using namespace std;

inline int isnumber( char c )  // 若多次调用这个函数,会降低使用效率,所以加上inline
{
	return( (c >= '0' && c <= '9') ? 1 : 0);
}


int main()
{
	char c;
	cin >> c;
	if ( isnumber( c ) )
		cout << "You entered a digit";
	else cout << "You entered a non-digit";
}
