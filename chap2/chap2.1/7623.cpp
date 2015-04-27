#include <stdio.h>

int main() {
	int k, n1, n2, n3, n4, n5;
	scanf("%d%d%d%d%d%d", &k, &n1, &n2, &n3, &n4, &n5);
	int A, B, C, D, E, H;
	int ANSH = 10000, ANSA, ANSB, ANSC, ANSD, ANSE;
	for (A = 1; A <= k * 100; A ++)
		for (B = 1; B <= k * 100; B ++) {
			// 得到H、C、D、E的值
			H = A * n1 + B;
			C = H - B * n2;
			D = H - C * n3;
			E = H - D * n4;
			// 检查e式是否满足
			if (E * n5 + A != H) continue;
			// 检查C、D、E是否为负数
			if (C <= 0 || D <= 0 || E <= 0) continue;
			// 检查A、B、C、D、E是否有相等的情况
			if (A == B || A == C || A == D || A == E ||
				B == C || B == D || B == E ||
				C == D || C == E || 
				D == E)
				continue;
			// 检查H是否超过了k * 100
			if (H > k * 100) continue;

			// 同当前最优解进行比较
			if (H < ANSH) {
				ANSH = H;
				ANSA = A; ANSB = B; ANSC = C; ANSD = D; ANSE = E;
			}
		}
	if (ANSH == 10000) {
		printf("not found");
	}
	else{
		printf("%d %d %d %d %d %d", ANSH, ANSA, ANSB, ANSC, ANSD, ANSE);
	}
	return 0;
}