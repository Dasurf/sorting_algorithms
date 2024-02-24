#include "sort.h"
#include <stdio.h>
/**
 * swap_int - Function that changes two values in ascending
 * or descending order
 * @arr: the array
 * @item1: item one
 * @item2: item two
 * @order: 1: ascending order, 0 descending order
 */
void swap_int(int arr[], int item1, int item2, int order)
{
	int temp;

	if (order == (arr[item1] > arr[item2]))
	{
		temp = arr[item1];
		arr[item1] = arr[item2];
		arr[item2] = temp;
	}
}
/**
 * merge - A function that sort bitonic sequences recursively
 * in both orders
 * @arr: the array
 * @low: the first element
 * @n_elem: the element's number
 * @order: 1: ascending order, 0 descending order
 */
void merge(int arr[], int low, int n_elem, int order)
{
	int mid, i;

	if (n_elem > 1)
	{
		mid = n_elem / 2;
		for (i = low; i < low + mid; i++)
			swap_int(arr, i, i + mid, order);
		merge(arr, low, mid, order);
		merge(arr, low + mid, mid, order);
	}
}
/**
 * bitonicSort - the bitonic sort algorithm implementation
 * @arr: the array
 * @low: the first element
 * @n_elem: the number of elements
 * @order: 1: ascending order, 0 descending order
 * @size: the array length
 */
void bitonicSort(int arr[], int low, int n_elem, int order, int size)
{
	int mid;

	if (n_elem > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", n_elem, size);
			print_array(&arr[low], n_elem);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", n_elem, size);
			print_array(&arr[low], n_elem);
		}
		mid = n_elem / 2;
		bitonicSort(arr, low, mid, 1, size);
		bitonicSort(arr, low + mid, mid, 0, size);
		merge(arr, low, n_elem, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", n_elem, size);
			print_array(&arr[low], n_elem);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", n_elem, size);
			print_array(&arr[low], n_elem);
		}
	}
}
/**
 * bitonic_sort - A func that prepares the terrain to bitonic
 * sort algorithm
 * @array: the array
 * @size: the array length
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (size < 2 || !array)
		return;
	bitonicSort(array, 0, size, order, size);
}
