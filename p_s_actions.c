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
	// ft_printf("sa\n");
}
void	sb(t_var_list *variable_list)
{
	swap_dll(&variable_list->stack_b);
	ft_lstadd_last_content(&variable_list->stack_output, "sb\n");
	// ft_printf("sb\n");
}

void	pa(t_var_list *variable_list)
{
	if (variable_list->stack_b != NULL)
	{
		push_top_to_dll(&variable_list->stack_a, &variable_list->stack_b);
		ft_lstadd_last_content(&variable_list->stack_output, "pa\n");
		// ft_printf("pa\n");
	}
}

void	pb(t_var_list *variable_list)
{
	if (variable_list->stack_a != NULL)
	{
		// ft_printf("pb\n");
		ft_lstadd_last_content(&variable_list->stack_output, "pb\n");
		push_top_to_dll(&variable_list->stack_b, &variable_list->stack_a);
	}
}

// void	ra(t_dll_stack **stack)
void	ra(t_var_list *variable_list)
{
	rotate_dll(&variable_list->stack_a);
	ft_lstadd_last_content(&variable_list->stack_output, "ra\n");
	// ft_printf("ra\n");
}

// void	multi_ra(t_dll_stack **stack, int times)
void	multi_ra(t_var_list *variable_list, int times)
{
	while (times > 0)
	{
		ra(variable_list);
		times--;
	}
}

// int	multi_rra(t_dll_stack **stack, int times)
int	multi_rra(t_var_list *variable_list, int times)
{
	while (times > 0)
	{
		rra(variable_list);
		times--;
	}
	return (times);
}

// int	multi_rb(t_dll_stack **stack, int times)
int	multi_rb(t_var_list *variable_list, int times)
{
	while (times > 0)
	{
		rb(variable_list);
		times--;
	}
	return (times);
}

// int	multi_rrb(t_dll_stack **stack, int times)
int	multi_rrb(t_var_list *variable_list, int times)
{
	while (times > 0)
	{
		rrb(variable_list);
		times--;
	}
	return (times);
}

// void	rb(t_dll_stack **stack)
void	rb(t_var_list *variable_list)
{
	rotate_dll(&variable_list->stack_b);
	ft_lstadd_last_content(&variable_list->stack_output, "rb\n");
	// ft_printf("rb\n");
}

// void	rra(t_dll_stack **stack)
void	rra(t_var_list *variable_list)
{
	rrotate_dll(&variable_list->stack_a);
	ft_lstadd_last_content(&variable_list->stack_output, "rra\n");
	// ft_printf("rra\n");
}

// void	rrb(t_dll_stack **stack)
void	rrb(t_var_list *variable_list)
{
	// rrotate_dll(stack);
	rrotate_dll(&variable_list->stack_b);
	ft_lstadd_last_content(&variable_list->stack_output, "rrb\n");
	// ft_printf("rrb\n");
}

void	rr(t_dll_stack **stack_a, t_dll_stack **stack_b)
{
	rotate_dll(stack_a);
	rotate_dll(stack_b);
	// ft_printf("rr\n");
}

void	rrr(t_dll_stack **stack_a, t_dll_stack **stack_b)
{
	rrotate_dll(stack_a);
	rrotate_dll(stack_b);
	// ft_printf("rrr\n");
}
