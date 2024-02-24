#include "sort.h"
#include <stdio.h>
/**
* getMax - An utility function to get the max value in arr[]
* @arr: the array
* @n: the size of the array
* Return: returns array
*/
int getMax(int *arr, int n)
{
	int i, max = arr[0];

	for (i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}

/**
* countSort - A function to count sort of arr[] according to
* the digit represented by exponent
* @arr: the array
* @n: the size of the array
* @exp: the exp is 10^i
* @output: the array to save the temporary values
*/
void countSort(int *arr, size_t n, int exp, int *output)
{
	int i;
	int count[10] = {0};

	/*To store count of occurrences in count[] */
	for (i = 0; i < (int)n; i++)
		count[(arr[i] / exp) % 10]++;

	/*
	* To change count[i] so that count[i] now contains
    * actual position of this digit in output[]
	*/
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	/*
	* Copy the output array to arr[], so that arr[] now
    * contains sorted numbers according to current digit
	*/
	for (i = 0; i < (int)n; i++)
		arr[i] = output[i];

	/*print_array(arr, n);*/
}

/**
* radix_sort - The main function that sorts arr[]
* of size n using Radix Sort
* @array: the array
* @size: the size of the array
*/
void radix_sort(int *array, size_t size)
{
	/* To find the maximum number to know number of digits */
	int exp, max = 0;
	int *output = '\0'; /* output array should be n(size) */

	if (size < 2 || array == '\0')
		return;

	max = getMax(array, size);
	output = malloc(size * sizeof(int));
	if (output == '\0')
		return;
	/*
	* Do the counting sort for every digit. Note: instead
    * of passing digit number, exp is passed. exp is 10^i
    * where i is current digit number
	*/
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}
