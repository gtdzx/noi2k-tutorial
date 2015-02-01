Chap 1.1 输入输出
==================
作者：李文新、gtdzx  
时间：2015-2-1  

scanf与printf
--------------
一般我们写的程序都需要包含同用户交互的部分。有时需要从用户那里读入数据，即用户在程序运行过程中用键盘输入一些数据；有时需要把运行的结果显示在显示器上，即在程序运行过程中输出一些数据。这一节将介绍如何在程序中输入和输出数据。C语言提供了一些专门用户输入输出的函数来实现通过控制台(键盘、显示器)的数据输入输出。这些函数都包含在```stdio.h```中。  
其中最常用的是```scanf```和```printf```，scanf用于输入数据，printf用户输出数据。  

整数的输入输出
----------------

我们先来看一个整数输入输出的例子：
```cpp
#include<stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    printf("%d", a+1);
    return 0;
}
```
运行上面的程序，会等待我们输入一个整数。当我们用键盘输入一个整数，并回车之后，程序会把这个整数+1的值显示出来。  
输入：  
31  
输出：  
32
### 定义保存数据的变量
由于我们需要把用户输入的整数保存起来，所以先定义了一个**整型变量**a：
```cpp
int a;
```
### 输入整数
输入整数的语句是：
```cpp
scanf("%d", &a);
```
它的作用是从键盘读入一个整数，并把这个整数存放到变量a中。```"%d"```叫作**格式串**，```%d```表示读入的是一个整数；```&a```表示存在放变量a中，**注意变量前需要加```&```符号**。  

### 输出整数
我们已经见过```printf("Hello World!");```向显示器输出一段文字。这里我们使用```printf```输出一个整数。
```cpp
printf("%d", a+1);
```
```%d``` 表示这里输出的是一个整数。这个整数的值是后面的```a+1```。  

字符的输入输出
-----------------
除了整数以外，C语言中还有其他的基本数据类型，例如字符类型(用于保存一个字符'A', 'B', '?'等)char以及浮点数类型(通常我们说的小数)float和double。```scanf```和```printf```利用不同的格式串来输入和输出相应类型的数据。例如，使用```"%c"```输入和输出一个字符：
```cpp
#include<stdio.h>
int main()
{
    char c;
    scanf("%c", &c);
    printf("%c", c);
    return 0;
}
```
这个程序把我们输入的字符原样显示在显示器上。  
输入：  
X  
输出：  
X

为了保存一个字符类型的数据，我们需要定义一个字符类型的变量```char c;```。并且使用```%c```来输入和输出数据。

浮点数的输入输出
--------------------
C语言中保存浮点数(小数)的数据类型是float和double，其中double能保存的精度高于float。
在使用```scanf```输入时，float和double对应的格式串分别是```%f```和```%lf```。但是，**在使用```printf```输出时，float和double对应的格式串都是```%f```**，并且默认输出6位小数。  
```cpp
#include<stdio.h>
int main()
{
    float a;
    scanf("%f", &a);
    printf("%f", a*0.5);
    return 0;
}
```
这个程序把我们输入的小数乘以0.5之后输出在显示器上。  
输入：  
0  
输出：  
0.000000  
输入：  
3.14  
输出：  
1.570000  

double类型输入输出的方法类似，我们会在下一节详细介绍float同double的不同之处。
```cpp
#include<stdio.h>
int main()
{
    double a;
    scanf("%lf", &a);
    printf("%f", a*0.5);
    return 0;
}
```
### 控制浮点数的输出精度
在上面的程序中，我们发现```"%f"```默认输出6位小数。在很多情况下，我们需要控制小数点后输出的位数。例如当我们输出一个金额时，只要输出小数点后2位就可以了。我们可以使用形如```%[.precision]f```这样的格式串来控制输出的精度。C语言会自动四舍五入输出相应的位数。  
输出2位小数：
```cpp
#include<stdio.h>
int main()
{
    float a;
    scanf("%f", &a);
    printf("%.2f", a);
    return 0;
}
```
输入：  
3.1415926  
输出：  
3.14  
输入：  
1.576  
输出：  
1.58  

多数据输入输出
--------------------
### 输出更丰富的内容
我们知道```printf("Hello World!")```可以输出一段文字，```printf("%d")```可以输出一个整数。事实上我们可以多次调用```printf```把文字和整数一起输出。  
```cpp
#include<stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    printf("Hello World!");
    printf("%d", a);
    return 0;
}
```
输入：  
3  
输出：  
Hello World!3

注意3是紧接着!输出的，我们可以在他们直接加入空格：
```cpp
#include<stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    printf("Hello World! "); //注意这里多了个空格
    printf("%d", a);
    return 0;
}
```
输入：  
3  
输出：  
Hello World! 3

当我们需要换行显示时，我们可以加入换行符```\n```:
```cpp
#include<stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    printf("Hello World!\n"); 
    printf("%d", a);
    return 0;
}
```
输入：  
3  
输出：  
Hello World!  
3

我们可以两句```printf```写在一起，这样看起来更简洁：
```cpp
#include<stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    printf("Hello World!\n%d", a); 
    return 0;
}
```
输入：  
3  
输出：  
Hello World!  
3

对于```scanf```我们也可以有类似的写法。下面这个程序从键盘读入两个整数，输出两个整数的和以及差：
```cpp
#include<stdio.h>
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("a+b=%d a-b=%d\n", a+b, a-b); 
    return 0;
}
```
输入：  
3 5  
输出：  
a+b=8 a-b=-2
