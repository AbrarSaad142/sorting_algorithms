#include "sort.h"

/**
 * swap- a function to swap element.
 * @a: element we want to swap it.
 * @b: another element.
 * @array: we will sort it.
 * @size: size of array.
*/

void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}

/**
 * partition - a function partition the array.
 * @array: we will sort it.
 * @low: low index in the array.
 * @high: high index in the array.
 *  @size: size of array.
 * Return: return the array.
*/

int partition(int *array, size_t size, int low, int high)
{
	int i, j, pivot = array[high];

	for (i = j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap(array, size, &array[j], &array[i++]);
		}
	}
	swap(array, size, &array[i], &array[high]);
	return (i);
}

/**
 * quick_sort_algorithm - a function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: we will sort it.
 * @low: low index in the array.
 * @high: high index in the array.
 * @size: size of array.
*/

void quick_sort_algorithm(int *array, size_t size, int low, int high)
{
	int p;

	if (low < high)
	{
		p = partition(array, size, low, high);
		quick_sort_algorithm(array, size, low, p - 1);
		quick_sort_algorithm(array, size, p + 1, high);
	}
}

/**
 * quick_sort - a function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: we will sort it.
 * @size: size of array.
*/
void quick_sort(int *array, size_t size)
{
	quick_sort_algorithm(array, size, 0, size - 1);
}
