#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the Shell sort algorithm, using the Knuth sequence
 * @array: the array 
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
    int interval = 1;
    int i, j, temp;

    while (interval <= size / 3)
        interval = interval * 3 + 1;

    while (interval > 0)
    {
        for (i = interval; i < size; i++)
        {
            temp = array[i];
            j = i;

            while (j >= interval && array[j - interval] > temp)
            {
                array[j] = array[j - interval];
                j -= interval;
            }

            array[j] = temp;
        }

        print_array(array, size);
        interval = (interval - 1) / 3;
    }
}
