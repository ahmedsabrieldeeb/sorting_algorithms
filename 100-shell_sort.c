#include "sort.h"

void insertion_sort(int *, long int, long int, size_t);

/**
* shell_sort - shell sort algorithm
*
* @array: array to sort
* @size: size of array
*/
void shell_sort(int *array, size_t size)
{
	long int n = 1;
	long int i, k, tmp;

	if (size < 2)
		return;

	while (n < (long int)size / 3)
		n = n * 3 + 1;

	while (n > 0)
	{
		for (i = n; i < (long int) size; i++)
		{
			tmp = array[i];
			for (k = i; k >= n && array[k - n] > tmp; k = k - n)
				array[k] = array[k - n];
			array[k] = tmp;
		}
		print_array(array, size);
		n = (n - 1) / 3;
	}
}
