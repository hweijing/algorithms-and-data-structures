#include <stdio.h>

void main() {
	int a[3] = { 1,100,10000 };

	// *p = a[0]，p = &a[0]。
	int* p = a;

	int i;

	// ++ 的优先级比 = 低，所以先计算 =。
	// * 和 ++ 的优先级相同，所以从右至左运算，先 ++，后 *。
	// 任何时候先把后 ++ 去掉，第二步看优先级是否高于 ++。
	i = *p++;

	// 输出 1 1 100。 
	printf("%d %d %d", a[0], i, *p);
}