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
	int			level;
	t_dll_stack	*tail;

	level = 0;
	while (variable_list->stack_b != NULL)
	{
		if (variable_list->stack_b != NULL
			&& variable_list->stack_b->data > variable_list->stack_a->prev->data)
		{ //if headB > tailA
			pa(&variable_list->stack_a, &variable_list->stack_b);
			ra(&variable_list->stack_a);
		}
		else if (variable_list->stack_b != NULL
				&& variable_list->stack_b->data < variable_list->stack_a->data)
			pa(&variable_list->stack_a, &variable_list->stack_b);
		else
		{
			tail = variable_list->stack_a->prev;
			while (variable_list->stack_b->data > variable_list->stack_a->data
				&& variable_list->stack_b != NULL)
			{
				ra(&variable_list->stack_a);
				level++;
			}
			pa(&variable_list->stack_a, &variable_list->stack_b);
			multi_rra(&variable_list->stack_a, level);
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
// static void	print(t_dll_stack *head)
// {
// 	t_dll_stack	*tail;

// 	tail = head->prev;
// 	while (head != tail)
// 	{
// 		printf("content: %d\n", head->data);
// 		head = head->next;
// 	}
// 	printf("content: %d\n", head->data);
// }

void	random_three_num(t_dll_stack **stack)
{
	int	bottom;
	int	top;
	int	mid;

	top = (*stack)->data;
	mid = (*stack)->next->data;
	bottom = (*stack)->prev->data;
	if (top > mid && bottom > top)
		sa(stack);
	else if (top > mid && mid > bottom && bottom < top)
	{
		sa(stack);
		rra(stack);
	}
	else if (top > mid && top > bottom && mid < bottom)
		ra(stack);
	else if (mid > top && mid > bottom && bottom > top)
	{
		sa(stack);
		ra(stack);
	}
	else if (mid > top && top > bottom && mid > bottom)
		rra(stack);
}

void	random_five_num(t_var_list *variable_list)
{
	pb(&variable_list->stack_b, &variable_list->stack_a);
	pb(&variable_list->stack_b, &variable_list->stack_a);
	random_three_num(&variable_list->stack_a);
	printf("\n(finish 3 sort)\n");
	printf("==================\n");
	insert_in_sorted_list(variable_list);
	if (is_sorted(variable_list->stack_a))
		printf("===sorted===\n");
	else
		printf("=NOT_sorted=\n");
}
