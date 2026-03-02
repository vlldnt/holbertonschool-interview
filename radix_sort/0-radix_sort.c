#include "sort.h"

void counting_sort_digit(int *array, size_t size, int signif,
						int *sorted);

/**
* radix_sort - sorts an array of integers in ascending order using
*               LSD Radix sort (assumes non-negative values)
* @array: array of ints to sort
* @size: size of the array
*/
void radix_sort(int *array, size_t size)
{
	int *sorted;
	int max_value = 0;
	int signif = 1;
	size_t idx;

	if (!array || size < 2)
		return;
	/* find the maximum value to know the number of digits */
	for (idx = 0; idx < size; idx++)
		if (array[idx] > max_value)
			max_value = array[idx];
	sorted = malloc(size * sizeof(int));
	if (!sorted)
		return;
	while (max_value / signif > 0)
	{
		counting_sort_digit(array, size, signif, sorted);
		print_array(array, size);
		signif *= 10;
	}
	free(sorted);
}

/**
* counting_sort_digit - stable counting sort by digit (helper)
* @array: input array
* @size: number of elements
* @signif: current digit position (1, 10, 100...)
* @sorted: temporary buffer for sorted output
*/
void counting_sort_digit(int *array, size_t size, int signif,
						int *sorted)
{
	int occurrences[10];
	size_t idx;
	int digit;

	/* reset all digit counters to 0 */
	for (idx = 0; idx < 10; idx++)
		occurrences[idx] = 0;

	/* count how many times each digit (0-9) appears */
	for (idx = 0; idx < size; idx++)
	{
		digit = (array[idx] / signif) % 10;
		occurrences[digit]++;
	}
	/* transform counts into cumulative positions */
	for (idx = 1; idx < 10; idx++)
		occurrences[idx] += occurrences[idx - 1];

	/* place elements in sorted order (reverse to keep stability) */
	for (idx = size; idx > 0; idx--)
	{
		digit = (array[idx - 1] / signif) % 10;
		sorted[--occurrences[digit]] = array[idx - 1];
	}
	/* copy sorted result back into original array */
	for (idx = 0; idx < size; idx++)
		array[idx] = sorted[idx];
}
