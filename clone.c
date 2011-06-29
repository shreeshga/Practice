#include <stdio.h>

void dupes(int a[], int n)
{
	int i,j;
	for (i = 0; i < n; i++) {
		while (a[a[i]] != a[i]) {
			int tmp = a[i];
			a[i] = a[tmp];
			a[tmp] = tmp;
	for (j = 0; j < n; j++)
		printf("%d ", a[j]);
	printf("\n");
	}
	}
	for (i = 0; i < n; i++)
	if (a[i] != i)
		printf("%d ", a[i]);

	printf("\n");
}

int main()
{
	int x[] = {1, 2, 3, 1, 3, 0, 6};
	dupes(x, sizeof x / sizeof x[0]);
	return 0;
}

