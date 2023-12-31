#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>


void recursive_qsort(int *, ssize_t, ssize_t, size_t);
ssize_t lomute_partition(int *, ssize_t, ssize_t, size_t);
void swap(int *, int *);

/**
 * quick_sort -  a function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 *
 * Description: implemented using Lomuto partitioning scheme
 * means that the pivot element is the last one
 *
 * @array: array to be sorted
 * @size: number of elements in array
*/
void quick_sort(int *array, size_t size)
{
	/* stop recursion */
	if (array == NULL || size <= 1)
		return;

	recursive_qsort(array, 0, size - 1, size);
}

/**
 * recursive_qsort -  entry point to our alog
 *
 * @arr: array to be sorted
 * @lower: start index of array to be sorted
 * @upper: end index of array to be sorted
 * @size: size of array for printing purposes
*/
void recursive_qsort(int *arr, ssize_t lower, ssize_t upper, size_t size)
{
	ssize_t correct_pivot;

	if (lower < upper)
	{
		correct_pivot = lomute_partition(arr, lower, upper, size);
		recursive_qsort(arr, lower, correct_pivot - 1, size);
		recursive_qsort(arr, correct_pivot + 1, upper, size);
	}
}

/**
 * lomute_partition -  partitioning the array
 *
 * @arr: array to be partitioned
 * @lb: start index of array to be partitioned
 * @up: end index of array to be partitioned
 * @size: size of array for printing purposes
 *
 * Return: returns the correct position of pivot element
*/
ssize_t lomute_partition(int *arr, ssize_t lb, ssize_t up, size_t size)
{
	ssize_t pivot, start, idx;

	pivot = up;
	start = lb - 1;

	for (idx = lb; idx <= up - 1; idx++)
	{
		if (arr[idx] <= arr[pivot])
		{
			start++;
			if (start != idx)
			{
				swap((arr + start), (arr + idx));
				print_array(arr, size);
			}
		}
	}
	if ((start + 1) != up)
	{
		swap((arr + start + 1), (arr + up));
		print_array(arr, size);
	}
	return (start + 1);
}

/**
 * swap - swapping two elementes
 *
 * @first: first element
 * @second: second element
*/
void swap(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}
