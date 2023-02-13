/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_big_num_a2b.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 00:39:00 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/01/19 00:39:00 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_array(int *arr, int size)
{
	int	i;

	i = 0;
	printf("array= ");
	while (i < size)
		printf("%d ", arr[i++]);
}

int	a2b(t_var_list *variable_list, t_indexing *list, int size)
{
	int	mid;
	int	moved;
	int	chunk;

	moved = 0;
	mid = list->array[list->middle];
	chunk = list->offset * 2;
	if (size < (list->offset * 2))
		chunk = size;
	while (chunk > 0 && size > 3)
	{
		while (in_range(list->start, list->end, variable_list->stack_a))
		{
			size--;
			chunk--;
			moved++;
			pb(variable_list);
			if (variable_list->stack_b->data < mid)
				rb(variable_list);
		}
		ra(variable_list);
	}
	return (moved);
}

void	check_top_a(t_var_list **variable_list)
{
	t_cdll_stack	*head;
	t_cdll_stack	*next;

	if ((*variable_list)->stack_a != NULL)
	{
		head = (*variable_list)->stack_a;
		next = (*variable_list)->stack_a->next;
		if (next->data < head->data)
		{
			sa(*variable_list);
		}
	}
}
