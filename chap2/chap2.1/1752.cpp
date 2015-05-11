#include <stdio.h>

int main() {
	int tasks;
	scanf("%d", &tasks);
	while (tasks --) {
		int a;
		scanf("%d", &a);

		// exsitAns设为0表示还没有找到过解
		int exsitAns = 0;
		int minAnimals, maxAnimals;

		int rabbits;
		for (rabbits = 0; rabbits * 4 <= a; rabbits ++) {
			// 计算剩余腿的数量
			int restLegs = a - rabbits * 4;

			// 如果剩下的腿的数量是单数说明不合法
			if (restLegs % 2 == 1) continue;

			// 计算鸡的数量
			int chickens = restLegs / 2;

			// 计算总动物数
			int animals = rabbits + chickens;

			// 如果之前还没有过合法答案
			if (exsitAns == 0) {
				exsitAns = 1;
				maxAnimals = animals;
				minAnimals = animals;
			}
			else {
				// 否则同之前的答案进行比较
				if (animals > maxAnimals) maxAnimals = animals;
				if (animals < minAnimals) minAnimals = animals;
			}
		}

		// 按照题目要求输出答案
		if (exsitAns == 0) {
			printf("0 0\n");
		}
		else {
			printf("%d %d\n", minAnimals, maxAnimals);
		}
	}
	return 0;
}