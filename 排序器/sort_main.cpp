#include <stdio.h>
#include <stdlib.h>
#include <search.h>

#define MAX_LEN 5
struct Fruit{
	double kilos;
	char name[15];
};

// 使qsort成为升序排序的比较函数s
int comparator(const void *elem1, const void *elem2) {
	double a = ((Fruit *)elem1)->kilos;
	double b = ((Fruit *)elem2)->kilos;
	return a > b ? 1 : (a < b ? -1 : 0);
}

int main() {
#define LEN 4
	Fruit fruitLst[LEN] = { {2.0, "pineapple"}, {3.0, "papaya"}, {1.7, "lemon"}, {0.5, "lychee"} };
	qsort(fruitLst, LEN, sizeof(Fruit), comparator);

	for (int i = 0; i < LEN; i++) {
		printf("fruit: %12s\t weight: %.2fkg\n", fruitLst[i].name, fruitLst[i].kilos);
	}
	putchar('\n');
	return 0;
}