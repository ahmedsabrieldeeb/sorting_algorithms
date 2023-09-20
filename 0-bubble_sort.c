#include "sort.h"
#include <stdio.h>
#include <stdlib.h>



/**
 * bubble_sort - sorting an array of integers ascendingly
 *
 * @array: array to be sorted
 * @size: number of elements of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t pass, idx;
	int temp;

	for (pass = 1; pass < size; pass++)
	{
		for (idx = 0; idx < size - 1; idx++)
		{
			if (array[idx] <= array[idx + 1])
				continue;
			else
			{
				/* swap two elements */
				temp = array[idx];
				array[idx] = array[idx + 1];
				array[idx + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
