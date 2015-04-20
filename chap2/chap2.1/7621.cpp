#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int a, b, c;
	int lineNumber = 0;
	for (c = 0; c <= n / 5; c ++)
		for (b = 0; b <= n / 2; b ++)
			for (a = 0; a <= n; a ++) {
				if (a * 1 + b * 2 + c * 5 == n) {
					lineNumber ++;
					printf("%03d%12d%12d%12d\n", lineNumber, a, b, c);
				}
			}
	return 0;
}