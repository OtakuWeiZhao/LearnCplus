#include <iostream>

using namespace std;

struct Point
{
private:
  double x, y;  //���ݳ�Ա
public:
  void Setxy(double a, double b)  // ��Ա����,���������������ݳ�Ա
  {
    x = a;
    y = b;
  }
  void Display()  // ��Ա����,��ָ����ʽ������ݳ�Ա��ֵ
  {
    cout<<x<<"\t"<<y<<endl;
  }
};
