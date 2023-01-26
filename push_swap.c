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

void	insert_in_sorted_list(t_var_list *variable_list)
{
	int	level;

	level = 0;
	while (variable_list->stack_b != NULL)
	{
		if (variable_list->stack_a == NULL)
			pa(variable_list);
		if (variable_list->stack_b != NULL
			&& variable_list->stack_b->data > variable_list->stack_a->prev->data)
		{ //if headB > tailA
			// pa(&variable_list->stack_a, &variable_list->stack_b);
			pa(variable_list);
			check_top_b(&variable_list->stack_b);
			ra(&variable_list->stack_a);
		}
		else if (variable_list->stack_b != NULL
				&& variable_list->stack_b->data < variable_list->stack_a->data)
				//headB < headA
			pa(variable_list);
		else
		{
			while (variable_list->stack_b->data > variable_list->stack_a->data
				&& variable_list->stack_b != NULL)
			{
				ra(&variable_list->stack_a);
				level++;
			}

			pa(variable_list);
			check_top_b(&variable_list->stack_b);
		}
		level = multi_rra(&variable_list->stack_a, level);
	}
}

void	check_top_b(t_dll_stack **stack)
{//put the biggest on top
	t_dll_stack	*head;
	t_dll_stack	*next;

	if ((*stack) != NULL)
	{
		head = (*stack);
		next = (*stack)->next;
		if (next->data > head->data)
		{
			swap_dll(stack);
			ft_printf("sb\n");
		}
	}
}

int	top_level(t_dll_stack **stack, int key)
{
	int			i;
	t_dll_stack	*tail;
	t_dll_stack	*temp;

	i = 0;
	tail = (*stack)->prev;
	temp = (*stack);
	while ((temp != tail))
	{
		if (temp->data > key)
			return (i);
		i++;
		temp = temp->next;
	}
	return (i);
}

void	random_three_num(t_var_list *variable_list, t_dll_stack **stack)
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
		rra(stack);
	}
	else if (top > mid && top > bottom && mid < bottom)
		ra(stack);
	else if (mid > top && mid > bottom && bottom > top)
	{
		sa(variable_list);
		ra(stack);
	}
	else if (mid > top && top > bottom && mid > bottom)
		rra(stack);
}

void	random_five_num(t_var_list *variable_list)
{
	pb(variable_list);
	pb(variable_list);
	random_three_num(variable_list, &variable_list->stack_a);
	// printf("\n(finish 3 sort)\n");
	// printf("==================\n");
	insert_in_sorted_list(variable_list);
	if (is_sorted(variable_list->stack_a))
		printf("===sorted===\n");
	else
		printf("=NOT_sorted=\n");
}
