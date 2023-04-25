#include "sort.h"

void num_swap(int *x, int *y);
void max_heap(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * num_swap - Swaps two numbers in an array.
 * @x: The Ist number to swap.
 * @y: The 2nd number to swap.
 */
void num_swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	yb = tmp;
}

/**
 * max_heap - Turns a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heap(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		num_swap(array + root, array + large);
		print_array(array, size);
		max_heap(array, size, base, large);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the shift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heap(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		num_swap(array, array + i);
		print_array(array, size);
		max_heap(array, size, i, 0);
	}
