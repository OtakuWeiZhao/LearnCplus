# LearnCplus
##### 左值和右值
左值是指某个对象的表达式."左值"来源于赋值表达式"E1 = E2",其中左运算分量"E1"必须能被
计算和修改,左值表达式在赋值语句中既可以作为左操作数,也可以作为右操作数.某些运算符可以
产生左值,例如,如果"P"是一个指针类型的表达式"* P"就是一个左值表达式,它代表由P指向的对
象,并且通过"* p="来改变这个对象的值,同理,"&p"也是左值表达式,可以通过"&p="改变这个指
针的指向.

##### 将对象作为函数参数
将对象作为函数参数,是将实参对象的值传递给形参对象,这种传递是单向的.形参拥有实参的备份,
当在函数中改变形参的值时,改变的是这个备份中的值,不会影响原来实参的值.这种传值方式可以防
止被调用的函数改变参数的原始值.
```
void swap( string, string );  // 使用string类的对象作为函数参数
int main()
{
	string str1( "现在" ), str2( "过去" );  // 定义对象str1和str2
	swap( str1, str2 );  // 使用传值方式传递str1和str2的数据成员值
	cout << "返回后:str1 = " << str1 << " str2 = " << str2 << endl;
}


void swap( string s1, string s2 )  // string类的对象s1和s2作为函数参数
{
	string temp = s1; s1 = s2; s2 = temp;
	cout << "交换为:str1 = " << s1 << " str2 = " << s2 << endl;
}
```
输出结果如下:  
交换为: str1 = 过去 str2 = 现在  
返回后: str1 = 现在 str2 = 过去
