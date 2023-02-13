/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_s_rotate_actions.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 14:00:18 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/02/07 14:00:18 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_var_list *variable_list)
{
	rotate_dll(&variable_list->stack_a);
	ft_lstadd_last_content(&variable_list->stack_output, "ra\n");
}

void	rb(t_var_list *variable_list)
{
	rotate_dll(&variable_list->stack_b);
	ft_lstadd_last_content(&variable_list->stack_output, "rb\n");
}

void	rra(t_var_list *variable_list)
{
	rrotate_dll(&variable_list->stack_a);
	ft_lstadd_last_content(&variable_list->stack_output, "rra\n");
}

void	rrb(t_var_list *variable_list)
{
	rrotate_dll(&variable_list->stack_b);
	ft_lstadd_last_content(&variable_list->stack_output, "rrb\n");
}

void	rr(t_var_list *variable_list)
{
	rotate_dll(&variable_list->stack_a);
	rotate_dll(&variable_list->stack_b);
	ft_lstadd_last_content(&variable_list->stack_output, "rr\n");
}
