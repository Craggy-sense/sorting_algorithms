#include "sort.h"

/**
 * quick_sort_hoare - function that sorts an array of integers in ascending
 * order using the quick sort algorithm with Hoare partition scheme
 * @array: array of int to sort
 * @size: size of the array
 * Return: Nothing void
 */
void quick_sort_hoare(int *array, size_t size)
{
    int pivot;
    size_t i, j;

    if (size < 2)
        return;

    pivot = array[size - 1];
    i = -1;
    j = size;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            break;

        array[i] ^= array[j];
        array[j] ^= array[i];
        array[i] ^= array[j];
        print_array(array, size);
    }

    quick_sort_hoare(array, j);
    quick_sort_hoare(array + j, size - j);
}
