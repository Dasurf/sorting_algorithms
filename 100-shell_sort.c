#include "sort.h"

/**
*swap - swaps positions of two elements in an array
*@array: the array
*@item1: array element
*@item2: array element
*/
void swap(int *array, int item1, int item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}
/**
 * shell_sort - A function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @size: size of the array
 * @array: A list of numbers
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, idx = 0;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = 3 * gap + 1;
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
			for (idx = i; idx >= gap &&
			 (array[idx] < array[idx - gap]); idx -= gap)
				swap(array, idx, idx - gap);
		print_array(array, size);
		gap /= 3;
	}
}
