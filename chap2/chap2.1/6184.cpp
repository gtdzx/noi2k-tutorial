#include <stdio.h>

int a[2000];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int i, j;
	int ans = 0;
	for (i = 0; i < n; i ++) scanf("%d", &a[i]);
	for (i = 0; i < n; i++)
		for (j = i; j < n; j++) {
			if (a[i] + a[j] == k) {
				// 判断成功，说明答案应为yes
				ans = 1;
			}
		}
	if (ans == 1) {
		printf("yes\n");
	}
	else {
		printf("no\n");
	}
	return 0;
}