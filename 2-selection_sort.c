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
	size_t i, j, min;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		/* first time through, for loop finds minimum value in entire array */
		/* next time thru, we only need to search for min in array[1...end] */
		/* ...and so on */
		{
			if (array[j] < array[min])
				min = j; /* after this for loop, min = min value of array */
		}
		if (i != min) /* if min isn't first posit of array, swap til it is */
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
