#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

int main(){
  double a[ ] = {1.1, 4.4, 3.3, 2.2},b[8] = {8};
  copy(a + 2, a + 4, ostream_iterator<double>(cout, " ")); // ���a[2]��a[3]
  cout<<endl;
  reverse_copy(a + 1, a + 4, ostream_iterator<double>(cout, " ")); //���a[3]~a[1]
  cout<<endl;
  copy(a, a + 4,&b[4]); // �����鸴�Ƶ�����b��β��
  copy(b, b + 8, ostream_iterator<double>(cout, " ")); // �������b
  cout<<endl;
  sort(a + 1, a + 3); // �Բ�������Ԫ����������
  copy(a, a + 4, ostream_iterator<double>(cout, " ")); // �������a
  cout<<endl;
  sort(b, b + 6, greater<double>()); // �Բ�������Ԫ�ؽ�������
  copy(b, b + 8, ostream_iterator<double>(cout, " ")); // �������b
  cout<<endl;
  return 0;
}
