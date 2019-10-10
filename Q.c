#include <stdio.h>

int main()
{
	int a[5];

	scanf("%d", &a[0]);
	scanf("%d", &a[1]);
	scanf("%d", &a[2]);
	a[3] = 7;
	a[4] = a[0];
	printf("%d\n", a[0]);
	printf("%d\n", a[3]);
	printf("%d\n", a[4]);
	return 0;
}
