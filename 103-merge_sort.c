#include "sort.h"

/**
* merge - merges
* @a: array to be sorted
* @n: size of array
* @m: merge
*
* Return: void
*/

void merge(int *a, int n, int m)
{
	int i, j, k;
	int *x = malloc(n * sizeof(int));

	for (i = 0, j = m, k = 0; k < n; k++)
	{
		x[k] = j == n      ? a[i++]
			: i == m      ? a[j++]
			: a[j] < a[i] ? a[j++]
			:               a[i++];
	}
	for (i = 0; i < n; i++)
	{
		a[i] = x[i];
	}
	free(x);
}

/**
* merge_sort - sorts an array of integers in ascending order
*               using the merge sort algorithm
* @array: array to be sorted
* @size: size of array
*
* Return: void
*/

void merge_sort(int *array, size_t size)
{
	int m;

	if ((int)size < 2)
		return;
	m = (int)size / 2;
	merge_sort(array, m);
	merge_sort(array + m, (int)size - m);
	printf("Merging...\n");
	printf("[left]: ");
	printf("%d\n", array[m]);
	printf("[right]: ");
	printf("%d\n", array[m]);
	merge(array, (int)size, m);
	printf("[Done]: ");
	print_array(array, size);
}
