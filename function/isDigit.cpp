#include <iostream>

using namespace std;

inline int isnumber( char c )  // ����ε����������,�ή��ʹ��Ч��,���Լ���inline
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
