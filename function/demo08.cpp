#include <iostream>

using namespace std;

int a[] = { 2, 4, 6, 8, 10, 12 }; /* ȫ������ */
int &index( int i ); /* �������õĺ���ԭ������ */


int &index( int i ) /* �������� */
{
	return(a[i]); /* ����ָ���±�������������� */
}


int main()
{
	index( 3 ) = 16; /* ��a[3]��Ϊ16 */
	cout << index( 3 ) << endl;     /* ���16 */
	return(0);
}
