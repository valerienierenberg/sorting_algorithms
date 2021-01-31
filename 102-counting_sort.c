#include "sort.h"

/**
* counting_sort - sorts a doubly linked list in ascending order
*               using the counting sort algorithm
* @array: array to be sorted
* @size: size of array
*
* Return: void
*/

void counting_sort(int *array, size_t size)
{
int output[10];
int count[10];
int i;

/* Find the largest element of the array */
int max = array[0];

for (i = 1; i < (int)size; i++)
{
if (array[i] > max)
max = array[i];
}

/*
* The size of count must be at least (max+1) but
* we cannot declare it as int count(max+1) in C as
* it does not support dynamic memory allocation.
* So, its size is provided statically.

* Initialize count array with all zeros.
*/
for (i = 0; i <= max; ++i)
count[i] = 0;
/* Store the count of each element */
for (i = 0; i < (int)size; i++)
count[array[i]]++;
/* Store the cummulative count of each array */
for (i = 1; i <= max; i++)
count[i] += count[i - 1];
/* Find the index of each element of the original array in count array, and */
/* place the elements in output array */
for (i = (int)size - 1; i >= 0; i--)
{
output[count[array[i]] - 1] = array[i];
count[array[i]]--;
}

/* Copy the sorted elements into original array */
for (i = 0; i < (int)size; i++)
array[i] = output[i];
}
