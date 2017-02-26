#include <iostream>
#include <string>

using namespace std;

void change( const string & );


void change( const string &s )
{
	string s2 = s + "NO!";
		 cout << s2 << endl;
}


int main()
{
	string str( "Can you change it?" );
	change( str );


	cout << str << endl;
	return(0);
}
