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
};  // 类定义以分号结束

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
	Point	A, B, *p;  // 声明对象和指针
	Point & RA = A;  // 声明对象RA引用对象A
	A.Setxy( 25, 55 );  // 使用成员函数为对象A赋值
	B	= A;  // 使用赋值运算符为对象B赋值
	p	= &B;  // 类Point的指针指向对象B
	p->Setxy( 112, 115 );  // 使用指针调用函数Setxy重新设置B的值
	print( p );  // 传递指针显示对象B的属性
	p->Display();  // 再次显示对象B的属性
	RA.Move( -80, 23 );  // 引用对象RA调用Move函数
	print( A );  // 验证RA与A同步变化
	print( &A );  // 直接传递A的地址作为指针参数
	return(0);
}
