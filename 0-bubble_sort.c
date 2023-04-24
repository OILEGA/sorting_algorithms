#include "sort.h"

/**
 * num_swap - Swapping two numbers in an array.
 * @x: The Ist number to swap.
 * @y: The 2nd number to swap.
 */
void num_swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * bubble_sort - Bubble sort, sorts an array of integers in ascending order.
 * @array: represents an array of numbers to sort.
 * @size:  represents the size of the array.
 *
 * Description: After every swap, an array is been printed.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubble_to_sort = false;

	if (array == NULL || size < 2)
		return;

	while (bubble_to_sort == false)
	{
		bubble_to_sort = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				num_swap(array + i, array + i + 1);
				print_array(array, size);
				bubble_to_sort = false;
			}
		}
		len--;
	}
}
