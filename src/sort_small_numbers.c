/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small_numbers.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 14:05:45 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/02/07 14:05:45 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	random_three_num(t_var_list *variable_list, t_cdll_stack **stack)
{
	int	bottom;
	int	top;
	int	mid;

	top = (*stack)->data;
	mid = (*stack)->next->data;
	bottom = (*stack)->prev->data;
	if (top > mid && bottom > top)
		sa(variable_list);
	else if (top > mid && mid > bottom && bottom < top)
	{
		sa(variable_list);
		rra(variable_list);
	}
	else if (top > mid && top > bottom && mid < bottom)
		ra(variable_list);
	else if (mid > top && mid > bottom && bottom > top)
	{
		sa(variable_list);
		ra(variable_list);
	}
	else if (mid > top && top > bottom && mid > bottom)
		rra(variable_list);
}

void	random_five_num(t_var_list *variable_list, t_indexing *vars)
{
	push_smallest_number_2b(variable_list, vars, 0);
	if (variable_list->size == 5)
		push_smallest_number_2b(variable_list, vars, 1);
	random_three_num(variable_list, &variable_list->stack_a);
	pa(variable_list);
	pa(variable_list);
}

void	push_smallest_number_2b(t_var_list *variable_list, t_indexing *vars,
		int i)
{
	t_cdll_stack	*temp;
	int				level;
	int				size;

	size = stack_size(variable_list->stack_a);
	level = 0;
	temp = variable_list->stack_a;
	while (temp->data != vars->array[i])
	{
		level++;
		temp = temp->next;
	}
	if (level > 2)
	{
		multi_rra(variable_list, size - level);
		pb(variable_list);
	}
	else if (level <= 2)
	{
		multi_ra(variable_list, level);
		pb(variable_list);
	}
}
