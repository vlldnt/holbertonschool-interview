#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @array: The array containing the integers
 * @size: Size of the array
 * @a: Pointer to first integer
 * @b: Pointer to second integer
 */
void swap(int *array, size_t size, int *a, int *b)
{
	int temp;

	if (a != b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
		print_array(array, size);
	}
}

/**
 * sift_down - Performs sift-down operation on a heap
 * @array: The array representing the heap
 * @size: Total size of the array
 * @root: Index of the root of the subtree to sift down
 * @heap_size: Current size of the heap
 */
void sift_down(int *array, size_t size, size_t root, size_t heap_size)
{
	size_t largest, left, right;

	largest = root;
	left = 2 * root + 1;
	right = 2 * root + 2;

	if (left < heap_size && array[left] > array[largest])
		largest = left;

	if (right < heap_size && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap(array, size, &array[root], &array[largest]);
		sift_down(array, size, largest, heap_size);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *             using the Heap sort algorithm (sift-down)
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	/* Build max heap */
	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, size, &array[0], &array[i]);
		sift_down(array, size, 0, i);
	}
}
