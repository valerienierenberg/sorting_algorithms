#include "sort.h"

/**
* swap - helper function to swap array
* @a: array to swap
* @b: array to be swapped to
*
* Return: void
*/

static void swap(unsigned int *a, unsigned int *b)
{
	unsigned int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
* rad_sort_u - sorts an array of integers in ascending order
*               using the radix sort algorithm
* @from: array to sort from
* @to: array to sort to
* @bit: size of arrays
*
* Return: void
*/
static void rad_sort_u(unsigned int *from, unsigned int *to, unsigned int bit)
{
	unsigned int *ll = from;
	unsigned int *rr = to - 1;

	if (!bit || to < from + 1)
		return;

	for (;;)
	{
		/* find left most with bit, and right most without bit, swap */
		while (ll < rr && !(*ll & bit))
			ll++;
		while (ll < rr &&  (*rr & bit))
			rr--;
		if (ll >= rr)
			break;
		swap(ll, rr);
	}

	if (!(bit & *ll) && ll < to)
		ll++;
	bit >>= 1;

	rad_sort_u(from, ll, bit);
	rad_sort_u(ll, to, bit);
}

/**
* radix_sort - sorts an array of integers in ascending order
*               using the radix sort algorithm
* @array: array to be sorted
* @size: size of array
*
* Return: void
*/
void radix_sort(int *array, size_t size)
{
	size_t i;
	unsigned int *x = (unsigned int *)array;

	for (i = 0; i < size; i++)
		x[i] ^= -2147483648;

	rad_sort_u(x, x + size, -2147483648);

	for (i = 0; i < size; i++)
		x[i] ^= -2147483648;

	print_array(array, size);
}
