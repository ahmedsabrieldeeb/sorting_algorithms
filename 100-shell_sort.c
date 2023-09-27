#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void swap(int *first, int *second);


/**
  * shell_sort - shell sort using gap conecpt by knuth sequence
  *
  * Description:
  * --> shell sort is general case of insertion sort
  * ... when gap is equal to 1, it really becomes insertion sort
  *
  * --> Knuth sequence is:
  * ... n+1 = n * 3 + 1, whereas n is the size of array
  * ... 1, 4, 13, 40, 121, ...
  *
  * --> expected to print the array each time you decrease the interval
  *
  * @array: array to be sorted
  * @size: size of array
  */
void shell_sort(int *array, size_t size)
{
	size_t gap, idx, temp;

	if (array == NULL || size < 2)
		return;

	/* getting maximum value of gap to start algo with */
	gap = 1;
	while ((gap * 3 + 1) <= size)
		gap = gap * 3 + 1;

	/* iterating all gaps possible */
	while (gap >= 1)
	{
		idx = 0;
		/* sorting in range of allowed gap */
		while (idx < size && idx + gap < size)
		{
			/* sorting in forward direction */
			if (array[idx] > array[idx + gap])

				swap(array + idx, array + idx + gap);

			/* sorting in backward direction */
			temp = idx;
			while ((int)temp - (int)gap >= 0)
			{
				if (array[temp] < array[temp - gap])
					swap(array + temp, array + temp - gap);
				temp--;
			}
			idx++;
		}
		gap = (gap - 1) / 3; /* reduce gap based on knuth sequence */
		print_array(array, size);
	}
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
