#include "sort.h"

/**
* max - finds maximum
* @a: array to be sorted
* @n: size of array
* @i: iterator
* @j: iterator
* @k: iterator
*
* Return: maximum
*/

int max(int *a, int n, int i, int j, int k)
{
	int m = i;

	if (j < n && a[j] > a[m])
		m = j;
	if (k < n && a[k] > a[m])
		m = k;
	return (m);
}

/**
* downheap - moves down heap
* @a: array to be sorted
* @n: size of array
* @i: iterator
*
* Return: void
*/

void downheap(int *a, int n, int i)
{
	int t;
	int j;

	while (1)
	{
	j = max(a, n, i, 2 * i + 1, 2 * i + 2);
	if (j == i)
	{
		break;
	}
	t = a[i];
	a[i] = a[j];
	a[j] = t;
	i = j;
	}
}

/**
* heap_sort - sorts an array of integers in ascending order
*               using the heap sort algorithm
* @array: array to be sorted
* @size: size of array
*
* Return: void
*/

void heap_sort(int *array, size_t size)
{
	size_t i;
	int t;

	for (i = (size - 2) / 2; (int)i >= 0; i--)
	{
		downheap(array, size, i);
	}
	for (i = 0; i < size; i++)
	{
		t = array[size - i - 1];
		array[size - i - 1] = array[0];
		array[0] = t;
		downheap(array, size - i - 1, 0);
		print_array(array, size);
	}
}
