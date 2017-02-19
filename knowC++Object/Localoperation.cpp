#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

int main(){
  double a[ ] = {1.1, 4.4, 3.3, 2.2},b[8] = {8};
  copy(a + 2, a + 4, ostream_iterator<double>(cout, " ")); // 输出a[2]和a[3]
  cout<<endl;
  reverse_copy(a + 1, a + 4, ostream_iterator<double>(cout, " ")); //输出a[3]~a[1]
  cout<<endl;
  copy(a, a + 4,&b[4]); // 将数组复制到数组b的尾部
  copy(b, b + 8, ostream_iterator<double>(cout, " ")); // 输出数组b
  cout<<endl;
  sort(a + 1, a + 3); // 对部分数组元素升幂排序
  copy(a, a + 4, ostream_iterator<double>(cout, " ")); // 输出数组a
  cout<<endl;
  sort(b, b + 6, greater<double>()); // 对部分数组元素降幂排序
  copy(b, b + 8, ostream_iterator<double>(cout, " ")); // 输出数组b
  cout<<endl;
  return 0;
}
