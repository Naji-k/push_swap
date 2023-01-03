// Selection sort in C

#include "push_swap.h"

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

t_stack	*ft_new(int content, int top)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->item = content;
	new_node->top = top;
	return (new_node);
}

void	ft_stack_add_front(t_stack **stack, t_stack *head)
{
	head->next = *stack;
	*stack = head;
}

void	print_stack(t_stack *s)
{
	printf("\t<<<Stack>>>\n");
	while (s != NULL)
	{
		printf("%d\t top=%d\n", s->item, s->top);
		s = s->next;
	}
}
int	find_largest_num(t_stack *head)
{
	int	max;

	max = INT_MIN;
	while (head != NULL)
	{
		if (max < head->item)
			max = head->item;
		head = head->next;
	}
	return (max);
}

int	find_smallest_num(t_stack *head)
{
	int	min;

	min = INT_MAX;
	while (head != NULL)
	{
		if (min > head->item)
			min = head->item;
		head = head->next;
	}
	return (min);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	swap_a(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	if (temp != NULL && temp->next != NULL)
		ft_swap(&temp->item, &temp->next->item);
}
int	main(int argc, char **argv)
{
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;
	t_stack *new_node;
	int num;
	int top = -1;

	if (argc > 1)
	{
		int i = 1;
		while (i < argc)
		{
			top++;
			num = ft_atoi(argv[i]);
			new_node = ft_new(num, top);
			printf("%d\n", new_node->item);
			ft_stack_add_front(&stack_a, new_node);
			i++;
		}
		print_stack(stack_a);
		swap_a(stack_a);
		print_stack(stack_a);
		// printf("\nlargest=%d\n", find_largest_num(stack_a));
		// printf("\nsmallest=%d\n", find_smallest_num(stack_a));
	}
}