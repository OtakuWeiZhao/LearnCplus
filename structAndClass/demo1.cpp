#include <iostream>

using namespace std;

struct Point{
  void Setxy(double a, double b)  // ��Ա����,���������������ݳ�Ա
  {
    x = a;
    y = b;
  }

  void Display()  // ��Ա����,��ָ����ʽ������ݳ�Ա��ֵ
  {
    cout<<x<<"\t"<<y<<endl;
  }
    double x,y;
};
int main()
{
  Point a;  // �������a
  a.Setxy(10.6, 18.5);  // ���ö���a�����ݳ�Ա
  a.Display();  // ��ʾ����a�����ݳ�Ա
  cout<<a.x<< "\t"<<a.y<<endl;
  return 0;
}
