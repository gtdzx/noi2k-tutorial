Chap1.7 字符串
==================
作者：郭炜,摘自其编著《新标准C++程序设计》
时间：2015-07-14  

C++中，字符串有三种形式。这里只介绍两种。

第一种形式就是用双引号括起来的字符串常量，如"CHINA" ， "C++ program"。

第二种形式的字符串，存放于字符数组中。该字符数组中包含一个'\0’字符，代表字符串的结尾。C++中有许多用于处理字符串的函数，它们都可以用字符串常量或字符数组的名字作为参数。


字符串常量
--------------

字符串常量是由一对双引号括起的字符序列。例如： "CHINA"，"C program"， "$12.5" "a" 等都是合法的字符串常量。

一个字符串常量占据内存的字节数等于字符串中字符数目加1。多出来的那个字节位于字符串的尾部，存放的是字符‘\0’。 字符‘\0’的ASCII码就是0。C++中的字符串，不论是字符串常量，还是字符数组，都是以‘\0’结尾的。

提到字符串的长度时，是不将结尾的‘\0’计算在内的。



"" 也是合法的字符串常量。该字符串里没有字符，称为“空串”，空串仍然会占据一个字节的存储空间，就是用来存放代表结束位置的‘\0’。

如果字符串常量中包含双引号，则双引号应写为‘\"’。而‘\’字符在字符串中出现时，须连写两次，变成‘\\’。例如：

cout << "He said: \"I am a stu\\dent.\"";

该语句的输出结果是：

```
He said: "I am a stu\dent."
```


用一维数组存放字符串
-------------------

字符数组就是每个元素都是char类型的数组。例如：

char szString[10];

字符数组的每个元素占据一个字节。可以用字符数组来存放字符串，这种情况下数组中须包含一个‘\0’字符，代表字符串的结尾。因而字符数组的元素个数，应该不少于被存储字符串的字符数目加1。字符数组的内容，可以在初始化时设定，也可以用一些C++库函数进行修改，还可以用对数组元素赋值的办法任意改变其中的某个字符。

字符数组同样可以用cout输出，用cin也能读取字符串到字符数组。用cin将字符串读入字符数组时，cin会自动在字符数组中字符串的末尾加上‘\0’

下面通过一个例子程序来说明字符数组的用法: 

```cpp
1.	#include <iostream>
2.	#include <cstring> //包含字符串库函数的声明 
3.	using namespace std;
4.	int main() 
5.	{
6.		char title[] = "Prison Break";
7.		char hero[100] = "Michael Scofield";
8.		char prisonName[100];
9.		char response[100];
10.		cout << "What's the name of the prison in " << title << endl;
11.		cin >> prisonName;
12.		if( strcmp( prisonName, "Fox-River") == 0 )  
13.				cout << "Yeah! Do you love " << hero << endl;
14.		else {
15.				strcpy( response, "It seems you haven't watched it!\n");
16.				cout << response;
17.		}
18.		title [0] = 't';
19.		title [3] = 0;  //等效于  title [3] = '\0';
20.		 cout << title << endl;
21.	    return 0;
22.	}
```

该程序运行结果根据用户输入的内容有所不同，可以如下：

```
What's the name of the prison in Prison Break
Fox-River↙
Yeah! Do you love Michael Scofield
tri
```

也可以如下：

```
What's the name of the prison in Prison Break
Shark↙
It seems you haven't watched it!
tri
```

第6行: 定义了一个字符数组title，并进行初始化，使得其长度自动为13（字符串"Prison Break"中的字符个数再加上结尾的‘\0’） 。


第7行: 定义了一个有100个元素的字符数组hero，并将其前17个元素初始化为： “Micheal Scofield”再加上结尾的’\0’。

第11行: 等待用户输入监狱的名字，并将用户的输入存放到prisonName 数组中，cin会自动在输入的字符串末尾加上‘\0’。如果用户输入超过了99个字符，那么加上‘\0’后，就会发生数组越界的错误。要注意，用cin输入字符串时，输入的字符串中不能有空格，否则被读入的就只是空格前面的那部分。例如，如果在本程序运行时输入“Fox River”再敲回车，那么prisonName中就会存入“Fox”而不是“Fox River”。

如果想要将将用户输入的包含一个甚至多个空格的一整行，都当作一个字符串读入到prisonName中，那么第11行应改成：

cin.getline(prisonName,99);

此时如果用户输入“Fox River”然后敲回车，则prisonName中就会存放着“Fox River”。

cin是一个对象，getline是其 “成员函数”，具体什么叫“成员函数”，后面学到“类”的概念时再解释，这里只需要记住，调用对象的成员函数，写法就是“对象名.成员函数名”即可。getline函数原型如下：

getline(char buf[], int bufSize);

其功就是将用户键盘输入的一整行，当作一个字符串读入到内存缓冲区buf中，并且在末尾自动添加‘\0’。为避免缓冲区溢出，函数最多只会读入bufSize-1个字符，哪怕一行不止这么多个字符。该函数的返回值暂不介绍。

第15行: 调用字符串拷贝库函数strcpy将"It seems you haven't watched it!"拷贝到数组response中。该库函数在头文件cstring中声明，原型如下:

strcpy(char  dest[], const char src[]);

功能是将字符串sr拷贝到dest。src必须以‘\0’结尾。返回值暂不介绍。

使用字符串拷贝函数的时候一定要看看，目标缓冲区dest是否能装得下要拷贝的字符串。要特别注意，该拷贝函数会在目标缓冲区自动多加一个表示字符串结尾的‘\0’


第20行：由于在C++中对字符串进行处理时，碰到‘\0’就认为字符串结束了，因此，依据title的内存布局图，本条语句输出：

tri

