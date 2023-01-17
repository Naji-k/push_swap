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

void	sa(t_dll_stack **stack)
{
	swap_dll(stack);
	ft_printf("sa\n");
}

void	pa(t_dll_stack **dst, t_dll_stack **src)
{
	push_top_to_dll(dst, src);
	ft_printf("pa\n");
}

void	pb(t_dll_stack **dst, t_dll_stack **src)
{
	push_top_to_dll(dst, src);
	ft_printf("pb\n");
}

void	ra(t_dll_stack **stack)
{
	rotate_dll(stack);
	ft_printf("ra\n");
}

void	rb(t_dll_stack **stack)
{
	rotate_dll(stack);
	ft_printf("rb\n");
}

void	rra(t_dll_stack **stack)
{
	rrotate_dll(stack);
	ft_printf("rra\n");
}

void	rrb(t_dll_stack **stack)
{
	rrotate_dll(stack);
	ft_printf("rrb\n");
}
