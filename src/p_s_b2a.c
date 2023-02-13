/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_s_b2a.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 14:28:04 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/02/08 14:28:04 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_for_highest(t_cdll_stack *stack, t_indexing *vars, int size)
{
	int				level;
	t_cdll_stack	*tail;

	tail = stack->prev;
	level = 0;
	while (stack->data != vars->array[size] && stack != tail)
	{
		stack = stack->next;
		level++;
		if (stack->data == vars->array[size])
			return (level);
	}
	return (level);
}

void	b2a(t_var_list *variable_list, t_indexing *vars)
{
	int	level;
	int	size;
	int	highest;

	size = stack_size(variable_list->stack_b);
	level = 0;
	while (variable_list->stack_b != NULL)
	{
		highest = size - 1;
		level = search_for_highest(variable_list->stack_b, vars, highest);
		if (level == 0)
		{
			if (variable_list->stack_b->data == vars->array[size - 1])
				size = p2a_check_top_a(variable_list, size);
			else
				break ;
		}
		else if (level <= (size / 2))
			size = b2a_highest_from_top_b(variable_list, vars, level, size);
		else if (level > (size / 2))
			size = b2a_highest_from_bottom_b(variable_list, vars, level, size);
	}
}

int	p2a_check_top_a(t_var_list *variable_list, int size)
{
	pa(variable_list);
	check_top_a(&variable_list);
	size--;
	return (size);
}

int	b2a_highest_from_top_b(t_var_list *variable_list, t_indexing *vars,
		int level, int size)
{
	int	highest;

	highest = size - 1;
	while (level > 0)
	{
		rb(variable_list);
		level--;
		if (variable_list->stack_b->data == vars->array[highest - 1])
		{
			size = p2a_check_top_a(variable_list, size);
			level--;
		}
	}
	size = p2a_check_top_a(variable_list, size);
	return (size);
}

int	b2a_highest_from_bottom_b(t_var_list *variable_list,
								t_indexing *vars,
								int level,
								int size)
{
	int	temp;
	int	highest;

	highest = size - 1;
	temp = size - level;
	while ((temp) > 0)
	{
		rrb(variable_list);
		temp--;
		if (variable_list->stack_b->data == vars->array[highest - 1])
			size = p2a_check_top_a(variable_list, size);
	}
	size = p2a_check_top_a(variable_list, size);
	return (size);
}
