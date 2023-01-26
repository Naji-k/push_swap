/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_big_num.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 00:39:00 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/01/19 00:39:00 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_arr(t_var_list *variable_list, t_indexing *list, int size)
{
	t_dll_stack	*tail;
	t_dll_stack	*current;
	int			i;

	// int			*arr = list->array;
	// if (!list->array)
	// {
	// 	printf("malloc fails\n\n");
	// 	return ;
	// }
	tail = variable_list->stack_a->prev;
	current = variable_list->stack_a;
	i = 0;
	while (i < size)
	{
		// arr[i++] = current->data;
		list->array[i] = current->data;
		current = current->next;
		i++;
	}
	// arr[i] = current->data;
	list->array[i] = current->data;
	// list->array = arr;
}

void	print_array(int *arr, int size)
{
	int	i;

	i = 0;
	printf("array= ");
	while (i < size)
		printf("%d ", arr[i++]);
}

void	insertionSort(int array[], int size)
{
	int	i;
	int	key;
	int	j;

	i = 1;
	while (i < size)
	{
		key = array[i];
		j = i - 1;
		// Compare key with each element on the left of it until an element smaller than
		// it is found.
		// For descending order, change key<array[j] to key>array[j].
		while (j >= 0 && array[j] > key) //key=array[i]=array[j+1]
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
		i++;
	}
}

void	cal_start_end(t_var_list *variable_list, t_indexing *list)
{
	int	offset;

	// printf("B_middle = %d\tB_start_index=%d\tB_end_index=%d\toffset=%d\n",
	// 		list->middle,
	// 		list->start_index,
	// 		list->end_index,
	// 		list->offset);
	offset = list->offset;
	// printf("list->array[variable_list->size - 1]=%d\n",
	// 		list->array[variable_list->size - 1]);
	// if (list->end != list->array[variable_list->size - 1])
	// {
		if (list->end_index == 0)
		{
			list->start_index = list->middle - offset;
			list->end_index = list->middle + offset;
		}
		else
		{
			list->start_index = list->start_index - offset;
			list->end_index = list->end_index + offset;
		}
	// }
	if (list->start_index < 0)
		list->start_index = 0;
	if (list->end_index > variable_list->size - 1)
		list->end_index = variable_list->size - 1;
	list->start = list->array[list->start_index];
	list->end = list->array[list->end_index];
	// printf("middle = %d\tstart_index=%d\tend_index=%d\n", list->middle,
	// 		list->start_index, list->end_index);
}

bool	in_range(int start, int end, t_dll_stack *curr)
{
	if (curr == NULL)
	{
		// printf("----------------\n");
		// exit(0);
		return (0);
	}
	return (curr->data >= start && curr->data <= end);
}

int	a2b(t_var_list *variable_list, t_indexing *list, int size)
{
	int	start;
	int	end;
	int	mid;
	int	moved;
	int	chunk;

	moved = 0;
	start = list->start;
	end = list->end;
	mid = list->array[list->middle];
	chunk = list->offset * 2;
	if (size < (list->offset * 2))
		chunk = size;
	// size = stack_size(variable_list->stack_a);
	// printf("size_inside_a2b=%d\n", size);
	// printf("size = %d\toffset=%d\tstart=%d\tend=%d\n",
	// 		variable_list->size,
	// 		list->offset,
	// 		list->start,
	// 		list->end);
	// printf("\tshould_move=%d\t and size=%d\tmoved=%d\n", chunk, size, moved);
	while (chunk > 0 && variable_list->stack_a != NULL)
	{
		while (in_range(start, end, variable_list->stack_a))
		{
			size--;
			chunk--;
			moved++;
			pb(variable_list);
			if (variable_list->stack_b->data < mid)
				rb(&variable_list->stack_b);
		}
		if (variable_list->stack_a == NULL)
		{
			// printf("==========\n");
			return (0);
		}
		while (in_range(start, end, variable_list->stack_a->prev))
		{
			size--;
			rra(&variable_list->stack_a);
			pb(variable_list);
			moved++;
			chunk--;
			if (variable_list->stack_b->data < mid)
				rb(&variable_list->stack_b);
		}
		ra(&variable_list->stack_a);
		// size--;
	}
	return (moved);
}
/* 
void	sort_big_numbers(t_var_list *variable_list, t_indexing *list)
{
	int offset;
	cal_start_end(variable_list, list);
	// printf("size = %d\toffset=%d\tstart=%d\tend=%d\n",
	// 		variable_list->size,
	// 		list->offset,
	// 		list->start,
	// 		list->end);
	// offset = a2b(variable_list);
	// print_array(list->array,variable_list->size);
} */