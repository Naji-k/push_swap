/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_s_algorithms.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 14:15:41 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/02/07 14:15:41 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_arr(t_var_list *variable_list, t_indexing *list, int size)
{
	t_cdll_stack	*current;
	int				i;

	current = variable_list->stack_a;
	i = 0;
	while (i < size)
	{
		list->array[i] = current->data;
		current = current->next;
		i++;
	}
	list->array[i] = current->data;
}

void	array_insertion_sort(int array[], int size)
{
	int	i;
	int	key;
	int	j;

	i = 1;
	while (i < size)
	{
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key)
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

	offset = list->offset;
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
	if (list->start_index < 4)
		list->start_index = 0;
	if (list->end_index > variable_list->size - 4)
		list->end_index = variable_list->size - 4;
	list->start = list->array[list->start_index];
	list->end = list->array[list->end_index];
}

bool	in_range(int start, int end, t_cdll_stack *curr)
{
	if (curr == NULL)
		return (0);
	return (curr->data >= start && curr->data <= end);
}

int	number_in_chunk_level(t_cdll_stack *stack, t_indexing *vars)
{
	int				level;
	t_cdll_stack	*tail;

	level = 0;
	tail = stack->prev;
	while (stack != tail)
	{
		stack = stack->next;
		level++;
		if (in_range(vars->start, vars->end, stack))
			return (level);
	}
	return (level);
}
