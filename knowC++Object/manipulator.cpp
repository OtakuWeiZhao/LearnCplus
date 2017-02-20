#include <iostream>
#include <iomanip>

using namespace std;

const double PI = 3.141592;

int main() {
  cout<<PI<<endl  // 3.14159
    // 0等于不设,由系统决定
    <<setprecision(0)<<PI<<endl  // 3
    // 1代表显示整数数字
    <<setprecision(1)<<PI<<endl  // 3
    <<setprecision(2)<<PI<<endl  // 3.1
    <<setprecision(3)<<PI<<endl  // 3.14
    // 系统只输出5位小数,必须设置7位,将全部小数输出
    <<setprecision(7)<<PI<<endl;  // 3.141592
  int b = 100;
  cout<<"Dec:"<<dec<<b<<endl  // 100
    <<"Hex:"<<hex<<b<<endl  // 64
    <<"Oct:"<<oct<<b<<endl;  // 144
  cout<<b<<endl  // 144
    <<100<<endl  // 144
    <<"Input b =";
  cin>>b; // 输入100 // Intput b = 100
  cout<<b<<endl; // 将按八进制输出  // 144
  // 输出设置为在正的数字面前显示"+"号
  cout<<dec<<setiosflags(ios_base::showpos)<<b<<endl; // +100
  cout<<"Input b =";
  cin>>b; // 输入100  // Intput b = 100
  cout<<b<<endl; // 将按十进制输出
  // "+"输出保持到这里为止
  cout<<resetiosflags(ios_base::showpos);  // +100
  cout<<b<<endl;  // 100
  return 0;
}
