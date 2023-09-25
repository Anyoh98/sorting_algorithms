#include "sort.h"

/**
 * my_partition - Scans a partition of an array of integers using Lomuto
 * partition scheme
 * @array: Array of integers to be sorted
 * @low: Index in the array that marks the beginning of the partition
 * @high: Index in the array that marks the end of the partition
 * @size: The Number of elements in the array
 * Return: The pivot or new index
 */
int my_partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot, temp;

	pivot = array[high];
	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (array[i] != array[j])
				print_array(array, size);
			i++;
		}
	}
	temp = array[i];
	array[i] = array[high];
	array[high] = temp;
	if (array[i] != array[high])
	print_array(array, size);
	return (i);
}

/**
 * my_quicksort - Recursively iplemnts the quick sort
 * @array: Array of integers to be sorted
 * @low: Index in the array that marks the beginning of the partition
 * @high: Index in the array that marks the end of the partition
 * @size: No of elements in the array
 */
void my_quicksort(int *array, int low, int high, size_t size)
{
	int pivot_ind;

	if (low < high)
	{
		pivot_ind = my_partition(array, low, high, size);
		my_quicksort(array, low, pivot_ind - 1, size);
		my_quicksort(array, pivot_ind + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Lomuto
 * partition scheme.
 * @array: Array of integers to be sorted
 * @size: No of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	my_quicksort(array, 0, (int)size - 1, size);
}

