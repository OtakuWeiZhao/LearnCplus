#include <iostream>

using namespace std;

int main()
{
    double * p;  // 声明double型指针 
    p = new double[3];  // 分配三个double型数据的存储空间 
    for(int i = 0; i < 3; i++)  // 定义对象i的初始值为0 
      cin>>*(p+i);   // 将输入是数据存入地址 
    for(int i = 0; i < 3; i++)
      cout<<*(p+i)<<" ";  // 将地址里的内容输出 
    delete p; 
    return 0; 
} 
