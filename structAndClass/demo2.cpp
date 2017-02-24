#include <iostream>

using namespace std;

struct Point
{
private:
  double x, y;  //数据成员
public:
  void Setxy(double a, double b)  // 成员函数,用来重新设置数据成员
  {
    x = a;
    y = b;
  }
  void Display()  // 成员函数,按指定格式输出数据成员的值
  {
    cout<<x<<"\t"<<y<<endl;
  }
};
