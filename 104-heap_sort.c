#include "sort.h"
#include <stdio.h>

/**
 * swap_int - An utility function to swap to integers
 * @a: pointer to first integer
 * @b: pointer to second integer
 **/
void swap_int(int *a, int *b)
{
	int t = *a;

	*a = *b;
	*b = t;
}

/**
 * maxHeapify - The main function to heapify a Max Heap. The function
 * assumes that everything under given root (element at index i)
 * is already heapified
 * @array: the array
 * @size: the size of the array for print
 * @i: index of element
 * @n: size of the array to run
 */
void maxHeapify(int *array, size_t size, int i, size_t n)
{
	int largest = i;		 /* Initializes largest as root*/
	int left = 2 * i + 1;	 /* left = (i << 1) + 1*/
	int right = 2 * i + 2; /* right = (i + 1) << 1*/

	/* to see if left child of root exists and is greater than root*/
	if (array[left] > array[largest] && left < (int)n)
		largest = left;

	/**
	 * to eee if right child of root exists and is greater than
     *the largest so far
	 */
	if (array[right] > array[largest] && right < (int)n)
		largest = right;

	/* To change root, if need be*/
	if (largest != i)
	{
		swap_int(&array[i], &array[largest]);
		print_array(array, size);
		maxHeapify(array, size, largest, n);
	}
}

/**
 * heap_sort -  The main function to sort an array of given size
 * @array: the array to sort
 * @size: the size of the array
 **/
void heap_sort(int *array, size_t size)
{
	int i;
	/**
	 * Start from the bottommost and rightmost internal mode and heapify all
     * internal modes from bottom up
	 */
	if (size < 2 || array == '\0')
		return;

	for (i = (size - 2) / 2; i >= 0; --i)
		maxHeapify(array, size, i, size);

	/**
	* while heapsize > 1 repeat all following steps.
    * The last element in max heap will be the minimum element
	*/
	for (i = (size - 1); i > 0; --i)
	{
		/**
		* The largest item in Heap is stored at the root. Replace
		*it with the last item of the heap followed by reducing the
		*size of heap by 1.
		*/
		swap_int(&array[0], &array[i]);
		print_array(array, size);

		/* Finally, heapify the root of the tree.*/
		maxHeapify(array, size, 0, i);
	}
}
