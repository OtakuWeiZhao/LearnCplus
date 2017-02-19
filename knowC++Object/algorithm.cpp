#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
  double a[ ] = {1.1, 4.4, 3.3, 2.2}, b[4];
  // 正向输出数组a
  copy(a, a + 4, ostream_iterator<double>(cout," "));
  cout<<endl;
  // 逆向输出数组a
  reverse_copy(a, a + 4, ostream_iterator<double>(cout," "));
  cout<<endl;
  // 复制到数组b
  copy(a, a + 4, b);
  // 正向输出数组b
  copy(b, b + 4, ostream_iterator<double>(cout," "));
  cout<<endl;
  // 对数组a进行升幂排序
  sort(a, a + 4);
  // 输出数组a
  copy(a, a + 4, ostream_iterator<double>(cout," "));
  cout<<endl;
  // 将a的内容按逆向复制给数组b
  reverse_copy(a, a + 4, b);
  // 输出数组b
  copy(b, b + 4, ostream_iterator<double>(cout," "));
  cout<<endl;
  return 0;
}
