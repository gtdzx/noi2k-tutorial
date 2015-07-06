#include <stdio.h>

void Move(int n, char a, char b, char c) {
	if (n > 1) Move(n - 1, a, c, b);
	printf("%c->%d->%c\n", a, n, b);
	if (n > 1) Move(n - 1, c, b, a);
}

int main() {
	int n;
	char a, b, c;
	scanf("%d %c %c %c", &n, &a, &b, &c);
	Move(n, a, b, c);
	return 0;
}