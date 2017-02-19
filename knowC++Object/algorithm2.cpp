#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

int main() {
  double a[] = {1.1, 4.4, 3.3, 2.2};
  sort(a, a + 4); //升幂排序
  copy(a, a + 4, ostream_iterator<double>(cout," "));
  cout<<endl;
  sort(a, a + 4, greater<double>()); // 降幂排序
  copy(a, a + 4, ostream_iterator<double>(cout," "));
  cout<<endl;
  // x是指针,它的数据类型是double
  double *x = find(a, a + 4, 4.4); // 查找
  if( x == a + 4) cout<<"没有值为4.4的数组元素";
  // 用运算符"*"输出查找的内容
  else cout<<"有值为"<<*x<<"的数组元素";
  cout<<endl;
  x = find(a, a + 4, 8); // x是double类型的指针
  if ( x == a + 4) cout<<"没有值为8的数组元素";
  else cout<<"有值为"<<*x<<"的数组元素";
  return 0;
}
