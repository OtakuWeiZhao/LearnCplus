#include <iostream>
#include <iomanip>

using namespace std;

const double PI = 3.141592;

int main() {
  cout<<PI<<endl  // 3.14159
    // 0���ڲ���,��ϵͳ����
    <<setprecision(0)<<PI<<endl  // 3
    // 1������ʾ��������
    <<setprecision(1)<<PI<<endl  // 3
    <<setprecision(2)<<PI<<endl  // 3.1
    <<setprecision(3)<<PI<<endl  // 3.14
    // ϵͳֻ���5λС��,��������7λ,��ȫ��С�����
    <<setprecision(7)<<PI<<endl;  // 3.141592
  int b = 100;
  cout<<"Dec:"<<dec<<b<<endl  // 100
    <<"Hex:"<<hex<<b<<endl  // 64
    <<"Oct:"<<oct<<b<<endl;  // 144
  cout<<b<<endl  // 144
    <<100<<endl  // 144
    <<"Input b =";
  cin>>b; // ����100 // Intput b = 100
  cout<<b<<endl; // �����˽������  // 144
  // �������Ϊ������������ǰ��ʾ"+"��
  cout<<dec<<setiosflags(ios_base::showpos)<<b<<endl; // +100
  cout<<"Input b =";
  cin>>b; // ����100  // Intput b = 100
  cout<<b<<endl; // ����ʮ�������
  // "+"������ֵ�����Ϊֹ
  cout<<resetiosflags(ios_base::showpos);  // +100
  cout<<b<<endl;  // 100
  return 0;
}
