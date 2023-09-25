#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the Shell sort algorithm, using the Knuth sequence
 * @arr: array
 * @size: size of array
 */
void shell_sort(int *arr, size_t size)
{
	int num = 1;
	int i, j, x;

	while (num <= size / 3)
		num = num * 3 + 1;

	while (num > 0)
	{
		for (i = num; i < size; i++)
		{
			x = arr[i];
			j = i;

			while (j > num - 1 && arr[j - num] >= x)
			{
				arr[j] = arr[j - num];
				j -= num;
			}

			arr[j] = x;
		}
		num = (num - 1) / 3;
		
		print_array(arr, size);
		printf("\n");


	}
}
