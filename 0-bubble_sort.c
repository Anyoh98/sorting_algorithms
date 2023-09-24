#include "sort.h"
/**
 * bubble_sort - Function that sorts an array of integers using BS algo
 * @array: pointer to the array to be sorted
 * @size: size of the array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	size_t n = size;

	if (!array || n < 2)
		return;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, n);
			}
		}
	}
}
