#include <iostream>

using namespace std;

struct Point
{
private:
  double x,y;  // ���ݳ�Ա
public:
  Point(){};  // �޲ι��캯��
  Point(double a, double b)  // �������������Ĺ��캯��
  {x = a; y = b;}
  void Setxy(double a, double b)  // ��Ա����,���������������ݳ�Ա
  {
    x = a;
    y = b;
  }
  void Display()  // ��Ա����,��ָ������������ݳ�Ա��ֵ
  {
    cout<<x<<"\t"<<y<<endl;
  }
};

int main()
{
  Point a;  // �������a
  Point b(18.5, 10.6);  // �������b������ʼֵ
  a.Setxy(10.6, 18.5);  // ���ñ���a�����ݳ�Ա
  a.Display();  // ��ʾ����a�����ݳ�Ա
  b.Display();  // ��ʾ����b�����ݳ�Ա
}
