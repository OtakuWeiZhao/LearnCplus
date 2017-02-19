#include <iostream>

using namespace std;

int main()
{
    int x = 56;  // 定义并初始化x 
    int& a = x;  // 声明a是x的引用,a和x的地址相同 
    int& r = a;  // 声明r是a的引用,r和a的地址相同 
    cout<<"x="<<x<<",&x="<<&x<<",a="<<a<<",&a="<<&a
    <<",r="<<r<<"&r="<<&r<<endl;
    r = 25;  //改变r,则a和x都同步变化
     cout<<"x="<<x<<",&x="<<&x<<",a="<<a<<",&a="<<&a
    <<",r="<<r<<"&r="<<&r<<endl;	
    return 0;
}
