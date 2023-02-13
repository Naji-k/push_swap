/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_numbers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 18:31:31 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/02/06 18:31:31 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_numbers(t_var_list *variable_list, t_indexing *vars)
{
	int	size;

	size = variable_list->size;
	if (variable_list->size == 2)
	{
		if (variable_list->stack_a->data > variable_list->stack_a->next->data)
			ra(variable_list);
	}
	else if (variable_list->size == 3)
		random_three_num(variable_list, &variable_list->stack_a);
	else if (variable_list->size < 6)
		random_five_num(variable_list, vars);
	else
	{
		if (variable_list->size <= 10)
			vars->n = 5;
		else if (variable_list->size < 150)
			vars->n = 8;
		else
			vars->n = 18;
		vars->middle = size / 2;
		vars->offset = (size / vars->n);
		sort_big_numbers(variable_list, vars);
	}
}

void	sort_big_numbers(t_var_list *variable_list, t_indexing *vars)
{
	int	size;

	vars->start_index = 0;
	vars->end_index = 0;
	vars->start = 0;
	vars->end = 0;
	size = variable_list->size;
	while (size > 3)
	{
		cal_start_end(variable_list, vars);
		size -= a2b(variable_list, vars, size);
	}
	random_three_num(variable_list, &variable_list->stack_a);
	b2a(variable_list, vars);
}
