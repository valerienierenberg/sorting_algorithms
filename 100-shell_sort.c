#include "sort.h"

/**
* shell_sort - sorts an array of integers in ascending order
*               using the shell sort algorithm
* @array: array to be sorted
* @size: size of array
*
* Return: void
*/


void shell_sort(int *array, size_t size)
{
	size_t i, j, interval = 1;
	int temp;

	if (size <= 1 || array == NULL)

	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			for (j = 1; j >= interval && array[j - interval] > temp; j = j - interval)
				array[j] = array[j - interval];
			array[j] = temp;
		}
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}
