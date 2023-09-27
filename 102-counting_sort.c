#include "sort.h"
#include <stdio.h>
#include <stdlib.h>



/**
 * counting_sort - sorts an array of integers of some size (without comparison)
 *
 * Description:
 * --> Assuming that array will contain only numbers >= 0
 * ... no engative values handled here (no normalization)
 *
 * --> Expected to print counting array once it is set up
 *
 * --> This array is of size k + 1 where 'k' is the largest number in array
 * ... so, k is considered given
 * 
 * Notes:
 * --> we could improve the algo by minimizing countArray to have only
 * ... size of range not to start from 0 always (see below)
 * 
 * --> Could we improve the algo by directly update input array
 * ... without needing to create a copied sortedArray??
 *
 * @array: array to be sorted
 * @size: size of array
*/
void counting_sort(int *array, size_t size)
{
	int k;
	size_t i;
	int *countArray, *sortedArray;

	if (array == NULL || size < 2)
		return;

	/* getting the largest number in the array */
	k = array[0];
	for (i = 0; i < size; i++)
		if (array[i] > k)
			k = array[i];

	/* initialzing countingArray with zeros */
	countArray = (int *)malloc(sizeof(int) * (k + 1));
	for (i = 0; i < (size_t)(k + 1); i++)
		countArray[i] = 0;

	/* counting frequencies of elements using countingArray */
	for (i = 0; i < size; i++)
		countArray[array[i]]++;

	/* updating countArray with actual indices in sortedArray */
	for (i = 1; i < (size_t)(k + 1); i++)
		countArray[i] += countArray[i - 1];
	print_array(countArray, (size_t)(k + 1));

	/* building sortedArray to store elements in sorted way */
	sortedArray = (int *)malloc(sizeof(int) * size);
	for (i = size - 1; (int)i >= 0; i--) /* starting from end to maintain stability */
		sortedArray[--countArray[array[i]]] = array[i];

	/* copying sortedArray to input array */
	for (i = 0; i < size; i++)
		array[i] = sortedArray[i];

	free(countArray);
	free(sortedArray);
}
