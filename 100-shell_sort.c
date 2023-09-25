#include "sort.h"
/**
  * shell_sort - shell sort, knuth sequence
  * @array: array to be sorted
  * @size: size of array
  */
void shell_sort(int *arr, size_t size)
{
	size_t k, i, j;
	int tmp;

	k = 1;
	while (k < size)
		k = (k * 3) + 1;
	k = (k - 1) / 3;
	while (k > 0)
	{
		for (i = k; i < size; i++)
		{
			tmp = arr[i];
			for (j = i; j >= k && array[j - k] > tmp; j -= k)
				arr[i2] = arr[j - k];
			arr[i2] = tmp;
		}
		k = (k - 1) / 3;
		print_array(arr, size);
	}
}
