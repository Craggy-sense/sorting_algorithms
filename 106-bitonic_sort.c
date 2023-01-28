#include "sort.h"

void compare_and_swap(int *a, int *b) {
    if (*a > *b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    int i, j, k;
    for (k = 2; k <= size; k = k*2)
    {
        for (j = k>>1; j > 0; j = j>>1)
        {
            for (i = 0; i < size; i++)
            {
                int ixj = i^j;
                if (ixj > i)
                {
                    if ((i & k) == 0 && array[i] > array[ixj])
                        compare_and_swap(&array[i], &array[ixj]);
                    if ((i & k) != 0 && array[i] < array[ixj])
                        compare_and_swap(&array[i], &array[ixj]);
                }
            }
            print_array(array, size);
        }
    }
}
