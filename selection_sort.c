// Selection sort in C

#include "../libft/libft.h"
#include <stdio.h>

// function to swap the the position of two elements
void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	selectionSort(int array[], int size)
{
	int	min_idx;

	for (int step = 0; step < size - 1; step++)
	{
		min_idx = step;
		for (int i = step + 1; i < size; i++)
		{
			// To sort in descending order, change > to < in this line.
			// Select the minimum element in each loop.
			if (array[i] < array[min_idx])
				min_idx = i;
		}
		// put min at the correct position
		swap(&array[min_idx], &array[step]);
	}
}
//insertionSort
void	insertionSort(int array[], int size)
{
	int	step;
	int	key;
	int	j;

	//   for (int step = 1; step < size; step++) {
	step = 1;
	while (step < size)
	{
		key = array[step];
		j = step - 1;
		// Compare key with each element on the left of it until an element smaller than
		// it is found.
		// For descending order, change key<array[j] to key>array[j].
		while (key < array[j] && j >= 0)
		{
			array[j + 1] = array[j];
			--j;
		}
		array[j + 1] = key;
		step++;
	}
}

// function to print an array
void	printArray(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d  ", array[i]);
	}
	printf("\n");
}

// driver code
int	main(int argc, char **argv)
{
	t_list *input;
	t_list *new_node;
	int num;
	if (argc > 1)
	{
		int i = 1;
		while (i < argc)
		{
			// if (ft_isdigit(*argv[i]))
			// {
				num = ft_atoi(argv[i]);
				new_node = ft_lstnew(num);
				ft_lstadd_back(&input, new_node);
				i++;
			// }
		}
		while (input)
		{
			printf("%d\n", input->content);
			input = input->next;
		}

		// int size = sizeof(argv) / sizeof(argv[1]);
		// //   selectionSort(data, size);
		// insertionSort(argv[1], size);
		// printf("Sorted array in Ascending Order:\n");
		// printArray(data, size);
	}
}