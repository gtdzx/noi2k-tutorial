#include <stdio.h>

int calc(int a, int l) {
	if (a == 1) return 1;
	int s = 0, i;
	for (i = l; i <= a; i++) 
		if (a % i == 0)
			s += calc(a / i, i);
	return s;
}

int main() {
	int n;
	scanf("%d", &n);
	while (n --) {
		int a;
		scanf("%d", &a);
		int ans;
		ans = calc(a, 2);
		printf("%d\n", ans);
	}
	return 0;
}