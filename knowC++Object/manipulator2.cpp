#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  cout<<setfill('*')
    // ʹ������ַ�ʱ,n����ʾλ����1ʱ�ŷ����������,����������
    <<setw(0)<<15<<endl  // 15
    <<setw(1)<<15<<endl  // 15
    <<setw(2)<<15<<endl  // 15
    <<setw(3)<<15<<endl  // *15
    <<setw(4)<<15<<endl;   // **15 
  cout<<setw(16)<<setfill('*')<<" "<<endl;  // ***************
  cout<<setiosflags(ios_base::right)
    <<setw(5)<<1
    <<setw(5)<<2
    <<setw(5)<<3<<endl;  // ****1****2****3
  cout<<resetiosflags(ios_base::right);
  cout<<setiosflags(ios_base::left)
    <<setw(5)<<1
    <<setw(5)<<2
    <<setw(5)<<3<<endl;  // 1****2****3****
}
