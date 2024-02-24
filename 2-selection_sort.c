#include "sort.h"
/**
 * selection_sort - A function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @size: the size of the array
 * @array: the list of numbers
 */
void selection_sort(int *array, size_t size)
{
	size_t i, idx;
	int temp, swap, flag = 0;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		temp = i;
		flag = 0;
		for (idx = i + 1; idx < size; idx++)
		{
			if (array[temp] > array[idx])
			{
				temp = idx;
				flag += 1;
			}
		}
		swap = array[i];
		array[i] = array[temp];
		array[temp] = swap;
		if (flag != 0)
			print_array(array, size);
	}
}
