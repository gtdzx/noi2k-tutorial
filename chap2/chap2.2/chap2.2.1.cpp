#include <stdio.h>

int jiecheng(int n) {
	if (n == 0) return 1;
	if (n > 0) return jiecheng(n - 1) * n;
}

int main() {
	int n;
	scanf("%d", &n);
	if (n < 0) printf("错误的输入\n");
	else printf("%d\n", jiecheng(n));
}