#include "sort.h"

/**
* selection_sort - sorts an array of integers in ascending order
*               using the selection sort algorithm
* @array: array to be sorted
* @size: size of array
*
* Return: void
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j, min, temp;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
/*		if (min == 1) */
/*			continue; */
		temp = array[min];
		array[min] = array[i];
		array[i] = temp;
		print_array(array, size);
	}
}
