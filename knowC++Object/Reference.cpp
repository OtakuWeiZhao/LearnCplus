#include <iostream>

using namespace std;

int main()
{
    int x = 56;  // ���岢��ʼ��x 
    int& a = x;  // ����a��x������,a��x�ĵ�ַ��ͬ 
    int& r = a;  // ����r��a������,r��a�ĵ�ַ��ͬ 
    cout<<"x="<<x<<",&x="<<&x<<",a="<<a<<",&a="<<&a
    <<",r="<<r<<"&r="<<&r<<endl;
    r = 25;  //�ı�r,��a��x��ͬ���仯
     cout<<"x="<<x<<",&x="<<&x<<",a="<<a<<",&a="<<&a
    <<",r="<<r<<"&r="<<&r<<endl;	
    return 0;
}
