#include <iostream>
using namespace std;
/*不需要->int指明返回类型的时候：函数体只包含一条返回语句
Lambda没有返回值，

如果不用&c传引用包含，则C在函数体内是只读的，无法改变。*/
int main()
{  
   int c = 10;
   auto fun = [&c](int a, int b) ->int { c++; return a+b+c;};


   cout<<fun(5,5)<<endl;
   cout<<c<<endl;
}