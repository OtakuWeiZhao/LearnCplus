#include <iostream>

using namespace std;

int main()
{
    double * p;  // ����double��ָ�� 
    p = new double[3];  // ��������double�����ݵĴ洢�ռ� 
    for(int i = 0; i < 3; i++)  // �������i�ĳ�ʼֵΪ0 
      cin>>*(p+i);   // �����������ݴ����ַ 
    for(int i = 0; i < 3; i++)
      cout<<*(p+i)<<" ";  // ����ַ���������� 
    delete p; 
    return 0; 
} 
