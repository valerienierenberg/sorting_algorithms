#include "sort.h"

/**
* bitonic_sort - sorts an array of integers in ascending order
*               using the bitonic sort algorithm
* @array: array to be sorted
* @size: size of array
*
* Return: void
*/

void bitonic_sort(int *array, size_t size)
{
	size_t i;
	size_t k = size;
	int temp;

	if (array == NULL)
		return;

	while (k > 0)
	{
		for (i = 0; i + k < k; i++)
		{
			if (array[i] > array[i + k])
			{
				temp = array[i];
				array[i] = array[i + k];
				array[i + k] = temp;
			}
		}
		k = k / 2;
	}

	for (i = 0; i < size; i++)
	{
		printf("Merging [%d/%d] (UP):\n", (int)i, (int)size);
		print_array(array, size);
	}
}
