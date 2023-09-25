#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *arr, size_t size)
{
	size_t g, i, j;

	if (arr == NULL || size < 2)
		return;

	for (g = 1; g < (size / 3);)
		g = g * 3 + 1;

	for (; g >= 1; g /= 3)
	{
		for (i = g; i < size; i++)
		{
			j = i;
			while (j >= g && arr[j - g] > arr[j])
			{
				swap_ints(arr + j, arr + (j - g));
				j -= g;
			}
		}
		print_array(arr, size);
	}
}
