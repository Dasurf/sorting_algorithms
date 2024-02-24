#include "sort.h"
#include <stdio.h>
/**
 *_calloc - A calloc function
 *@nmemb: the number of elemets
 *@size: bit size of each element
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
 * counting_sort - A counting sort method implementation
 * @array: the array to sort
 * @size: the array size
 */
void counting_sort(int *array, size_t size)
{
	int idx, max = 0, *counter = '\0', *temp = '\0';
	size_t i;

	if (size < 2 || array == '\0')
		return;
	/* to find max number */
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	counter = _calloc(max + 1, sizeof(int));
	temp = _calloc(size + 1, sizeof(int));
	/* to count the array elements */
	for (i = 0; i < size; i++)
		counter[array[i]]++;
	/* to get the accumulative values */
	for (idx = 1; idx <= max; idx++)
		counter[idx] += counter[idx - 1];
	print_array(counter, max + 1);
	/* to get the new array sorted */
	for (i = 0; i < size; ++i)
	{
		temp[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}
	/* to replace old array to new array sorted */
	for (i = 0; i < size; i++)
		array[i] = temp[i];
	free(temp);
	free(counter);
}
