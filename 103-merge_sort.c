#include "sort.h"
#include <stdio.h>
/**
 *_calloc - A calloc function
 *@nmemb: the number of elements
 *@size: the bit size of each element
 *Return: returns pointer to memory assignment
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i = 0;
	char *p;

	if (size == 0 || nmemb == 0)
		return ('\0');
	p = malloc(nmemb * size);
	if (p == '\0')
		return ('\0');
	for (i = 0; i < (nmemb * size); i++)
		p[i] = '\0';
	return (p);
}
/**
 *merge - A function that makes a merge
 *@arr: one from start to mid
 *@temp: temporary array used in merge, created outside to
 *optimize reducing the system calls
 *@start: the first element position
 *@mid: the array middle
 *@end: the last element position
 **/
void merge(int *arr, int *temp, int start, int mid, int end)
{
	/*  the sizes and temporary arrays */
	int left_size = mid - start + 1, size_right = end - mid;
	int *array_left, *array_right;
	/* counters */
	int left, right, i = 0;

	array_left = &temp[0];
	array_right = &temp[size_right];
	for (left = 0; left < left_size; left++)
		array_left[left] = arr[start + left];
	for (right = 0; right < size_right; right++)
		array_right[right] = arr[mid + 1 + right];
	left = 0, right = 0, i = start;
	/* merging the temp arrays into main array*/
	while (right < size_right && left < left_size)
	{
		if (array_left[left] <= array_right[right])
			arr[i] = array_left[left], left++;
		else
			arr[i] = array_right[right], right++;
		i++;
	}
	/* merging the remaining left array into the main array*/
	while (left_size > left)
		arr[i] = array_left[left], left++, i++;
	/* merging the remaining right array into the main array*/
	while (size_right > right)
		arr[i] = array_right[right], right++, i++;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array_left, left);
	printf("[right]: ");
	print_array(array_right, right);
	printf("[Done]: ");
	print_array(&arr[start], left + right);
}
/**
 *mergesort - A function that sorts an array of integers
 *in ascending order using the Merge sort algorithm
 *@array: the array of integers
 *@temp: the temp array used in merge, created outside to
 *optimize reducing the system calls
 *@start: the first element position
 *@end: the last element position
 *Return: returns void
 */
void mergesort(int *array, int *temp, int start, int end)
{
	int mid;

	mid = (start + end) / 2;
	if ((start + end) % 2 == 0)
		mid--;
	if (mid >= start)
	{
		mergesort(array, temp, start, mid);
		mergesort(array, temp, mid + 1, end);
		merge(array, temp, start, mid, end);
	}
}
/**
 *merge_sort - A function that sorts an array of integers
 *in ascending order using the Merge sort algorithm
 *@size: the size of the list
 *@array: the array of integers
 *Return: returns void
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (size < 2 || !array)
		return;
	temp = _calloc(size, sizeof(int));
	mergesort(array, temp, 0, size - 1);
	free(temp);
}
