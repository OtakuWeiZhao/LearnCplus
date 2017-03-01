#include <iostream>

using namespace std;

class Point {
private:
	int x, y;
public:
	void Setxy( int a, int b )
	{
		x	= a;
		y	= b;
	}


	void Move( int a, int b )
	{
		x	= x + a;
		y	= y + b;
	}


	void Display()
	{
		cout << x << "," << y << endl;
	}


	int Getx()
	{
		return(x);
	}


	int Gety()
	{
		return(y);
	}
};  // �ඨ���ԷֺŽ���

void print( Point *a )
{
	a->Display();
}


void print( Point &a )
{
	a.Display();
}


int main()
{
	Point	A, B, *p;  // ���������ָ��
	Point & RA = A;  // ��������RA���ö���A
	A.Setxy( 25, 55 );  // ʹ�ó�Ա����Ϊ����A��ֵ
	B	= A;  // ʹ�ø�ֵ�����Ϊ����B��ֵ
	p	= &B;  // ��Point��ָ��ָ�����B
	p->Setxy( 112, 115 );  // ʹ��ָ����ú���Setxy��������B��ֵ
	print( p );  // ����ָ����ʾ����B������
	p->Display();  // �ٴ���ʾ����B������
	RA.Move( -80, 23 );  // ���ö���RA����Move����
	print( A );  // ��֤RA��Aͬ���仯
	print( &A );  // ֱ�Ӵ���A�ĵ�ַ��Ϊָ�����
	return(0);
}
