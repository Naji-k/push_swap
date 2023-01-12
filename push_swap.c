/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 20:56:36 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/01/12 20:56:36 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	random_three_num(t_dll_stack **stack)
{
	int bottom;
	int top;
	int mid;

	bottom = (*stack)->data;
	top = (*stack)->next->data;
	mid = (*stack)->next->next->data;
	if (top > mid && bottom > top)
		sa(stack);
	else if (top > mid && mid > bottom && bottom < top)
	{
		sa(stack);
		rra(*stack);
	}
	else if (top > mid && top > bottom && mid < bottom)
		ra(*stack);
	else if (mid > top && mid > bottom && bottom > top)
	{
		sa(stack);
		ra(*stack);
	}
	else
		rra(*stack);
}