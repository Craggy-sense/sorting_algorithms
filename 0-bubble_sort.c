#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 * @array: array of int to sort
 * @size: size of the array
 * Return: Nothing void
 */

void bubble_sort(int *array, size_t size)
{
	size_t J, K;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (K = 1; K <= size; K++)
	{
		for (J = 0; J < size - 1; J++)
		{
			if (array[J] > array[J + 1])
			{
				tmp = array[J];
				array[J] = array[J + 1];
				array[J + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
