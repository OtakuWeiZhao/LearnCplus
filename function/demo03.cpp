#include <iostream>

using namespace std;

void swap( int[] );  // 数组形参使用"类型[]"的形式


void swap( int a[] )  // 数组名a,也就是指针名作为函数参数
{
	int temp = a[0]; a[0] = a[1]; a[1] = temp;
	cout << "交换为:a =" << a[0] << " b = " << a[1] << endl;
}


int main()
{
	int a[] = { 3, 8 };  // 定义数组a
	swap( a );  //传递数组名a,也就是指针名
	cout << "返回后:a =" << a[0] << " b = " << a[1] << endl;
	return(0);
}
