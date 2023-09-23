#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * selection_sort -  a function that sorts an array of integers ascendingly
 *
 * @array: array to be sorted
 * @size: number of elements in array
*/
void selection_sort(int *array, size_t size)
{
	size_t pass, idx;
	int temp_swap, lowest, lowest_idx;

	if (array == NULL)
		return;

	for (pass = 0; pass < size - 1; pass++)
	{
		lowest = array[pass];
		for (idx = pass; idx < size; idx++)
		{
			if (array[idx] > lowest)
				continue;
			else
			{
				lowest = array[idx];
				lowest_idx = idx;
			}
		}
		temp_swap = array[pass];
		array[pass] = lowest;
		array[lowest_idx] = temp_swap;
		if (temp_swap == lowest)
			continue;
		else
			print_array(array, size);
	}
}
