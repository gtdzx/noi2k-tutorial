Chap 1 编程基础
============
作者：李文新、gtdzx  
时间：2015-1-31
  
认识C程序
-------------
```cpp
#include<stdio.h>
int main()
{
    printf("Hello World!");
    return 0;
}
```
运行上面的程序，会输出一行文字：  
Hello World!  

下面我们来逐行解释这个程序：
###1. #include
C语言本身提供了非常丰富的函数库。我们可以直接使用这些**标准库函数**，来完成一些常见的功能：例如输入输出、三角函数运算、字符串处理等。这些函数被分门别类的放在不同的**头文件**中，例如向显示器输出的函数```printf```就被放在```stdio.h```这个头文件中。想要使用这些函数，我们需要预先把相应的头文件"包含"到程序中来，**#include**命令就是完成把后面"<>"中的头文件包含进程序这一功能的。  
在上面的程序中，我们需要```#include<stdio.h>```，以便使用```printf```向显示器输出文字。

###2. main函数
```int main()```是一个固定的写法，它叫做**main函数**，作用是标识程序从这里开始执行。每一个程序都应该有唯一的main函数。```int main()```后面紧跟着一个左大括号，表示main函数的开始，它同程序结尾的右大括号是成对出现的，所有在这对括号之间的语句都将被执行。

###3. printf
```printf``` 的作用是向显示器输出文字。它是C语言本身提供的标准库函数之一，被放在```stdio.h```中。双引号之间的内容是要输出的文字。

###4. return 0
这个程序返回一个0。习惯上程序返回0表示程序正常结束，没有异常。



