/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_s_actions.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 15:24:02 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/01/10 15:24:02 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_var_list *variable_list)
{
	swap_dll(&variable_list->stack_a);
	ft_lstadd_last_content(&variable_list->stack_output, "sa\n");
}

void	sb(t_var_list *variable_list)
{
	swap_dll(&variable_list->stack_b);
	ft_lstadd_last_content(&variable_list->stack_output, "sb\n");
}

void	pa(t_var_list *variable_list)
{
	if (variable_list->stack_b != NULL)
	{
		push_top_to_cdll(&variable_list->stack_a, &variable_list->stack_b);
		ft_lstadd_last_content(&variable_list->stack_output, "pa\n");
	}
}

void	pb(t_var_list *variable_list)
{
	if (variable_list->stack_a != NULL)
	{
		ft_lstadd_last_content(&variable_list->stack_output, "pb\n");
		push_top_to_cdll(&variable_list->stack_b, &variable_list->stack_a);
	}
}
