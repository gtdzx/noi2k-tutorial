﻿Chap 1.8 多维数组
==================
作者：郭炜，摘自其编著《新标准C++程序设计》
时间：2015-07-12  

如果需要存储一个矩阵，并且希望只要给定行号和列号，就能立即访问到矩阵中的元素，该怎么办？一个直观的想法是矩阵的每一行都用一个一维数组来存放，那么矩阵有几行，就需要定义几个一维数组。这个办法显然很麻烦。C++语言支持 “二维数组”，能很好的解决这个问题。

如果我们写：

```
T a[N][M]; // 此处T可以是任何类型名，如char , double, int等。M、N 都是
		   //正整数，或值为正整数的常量表达式
```


那么，我们就定义了一个N行、M列的二维数组，这个数组的名字是a。a数组里有N×M个元素，每个元素都是一个类型为T的变量。这N×M个元素在内存里是一个挨一个连续存放的。a数组占用了一片连续的、大小总共为 N×M×sizeof(T)字节的存储空间。

表达式“sizeof(a)”的值就是整个数组的体积，即N×M×sizeof(T)。

a数组中的每个元素，都可以表示为：

```
数组名[行下标][列下标]
```

行下标和列下标都是从0开始的。

数组a[N][M] 每一行都有M个元素，第i行的元素就是a[i][0]、a[i][1]……a[i][M-1]。同一行的元素，在内存中是连续存放的。而第j列的元素的元素，就是a[0][j]、a[1][j]……a[N-1][j]。

a[0][0]是数组中地址最小的元素。如果a[0][0]存放在地址n，那么a[i][j](i,j为整数)存放的地址就是 n + i × M× sizeof(T) + j × sizeof(T)。

假设a[0][0]存放的地址是100，那么a[0][1]的地址就是104，以此类推。

二维数组的每一行，实际上都是一个一维数组。对上面的数组 int a[2][3]来说，a[0]，a[1]都可以看作是一个一维数组的名字，可以直接当一维数组使用。

二维数组用于存放矩阵特别合适。一个 N行M列的矩阵，恰好可以用一个N行M列的二维数组进行存放。
遍历一个二维数组，将其所有元素依次输出的代码如下：

```cpp
const ROW = 20;
const COL = 30;
int a[ROW][COL];
for( int i = 0; i < ROW ; ++i) {
		for( int j = 0; j < COL ; ++j )  
			cout << a[i][j] << " ";
		cout << endl;
}
```

面的代码将数组a的元素按行依次输出，即先输第0行的元素，然后再输出第1行的元素、第2行的元素……。

每行元素在输出里也占一行，元素之间用空格分隔。



