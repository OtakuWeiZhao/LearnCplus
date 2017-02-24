#include <iostream>

using namespace std;

struct Point
{
private:
  double x,y;  // 数据成员
public:
  Point(){};  // 无参构造函数
  Point(double a, double b)  // 具有两个参数的构造函数
  {x = a; y = b;}
  void Setxy(double a, double b)  // 成员函数,用来重新设置数据成员
  {
    x = a;
    y = b;
  }
  void Display()  // 成员函数,按指定个数输出数据成员的值
  {
    cout<<x<<"\t"<<y<<endl;
  }
};

int main()
{
  Point a;  // 定义对象a
  Point b(18.5, 10.6);  // 定义对象b并赋初始值
  a.Setxy(10.6, 18.5);  // 设置变量a的数据成员
  a.Display();  // 显示变量a的数据成员
  b.Display();  // 显示变量b的数据成员
}
