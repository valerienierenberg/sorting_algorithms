#include "sort.h"

/**
* bubble_sort - sorts an array of integers in ascending order
*               using the bubble sort algorithm
* @array: array to be sorted
* @size: size of array
*
* Return: void
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j, swap;

	if (array == NULL)
		return;

	for (i = 0 ; i < size - 1; i++) /* traverse thru all elements of array */
	{
		for (j = 0 ; j < size - i - 1; j++)
		{ /* size - i - 1 because we want to get to one before end of array */
		/* because index [j + 1] needs to exist, not be NULL for comparison */
			if (array[j] > array[j + 1])
			{ /* compare values starting with index 0 and index 1 */
				swap = array[j]; /* next three lines swap the two values */
				array[j] = array[j + 1];
				array[j + 1] = swap;
				print_array(array, size);
			}
		}
	}
}
