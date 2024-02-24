#include "sort.h"
#include <sys/types.h>
/**
*swap_elem - swaps the positions of two elements into an array
*@array: the array
*@item1: the array element
*@item2: the array element
*/
void swap_elem(int *array, ssize_t item1, ssize_t item2)
{
	int temp;

	temp = array[item1];
	array[item1] = array[item2];
	array[item2] = temp;
}
/**
 *hoare_partition - hoare partition sorting scheme implementation
 *@array: the array
 *@first: the first array element
 *@last: the last array element
 *@size: size of the array
 *Return: returns the position of the last element sorted
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int current = first - 1, finder = last + 1;
	int pivot = array[last];

	while (1)
	{
		do {
			current++;
		} while (array[current] < pivot);
		do {
			finder--;
		} while (array[finder] > pivot);
		if (current >= finder)
			return (current);
		swap_elem(array, current, finder);
		print_array(array, size);
	}
}
/**
 *qs - the qucksort algorithm implementation
 *@array: the array
 *@first: the first array element
 *@last: the last array element
 *@size: the array size
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (last > first)
	{
		position = hoare_partition(array, first, last, size);
		qs(array, first, position - 1, size);
		qs(array, position, last, size);
	}
}
/**
 *quick_sort_hoare - prepares the terrain to quicksort algorithm
 *@array: the array
 *@size: the array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2 || !array)
		return;
	qs(array, 0, size - 1, size);
}
