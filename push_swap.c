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
	t_dll_stack	*temp;
	t_dll_stack	*headA;

	if (variable_list->stack_a == NULL)
	{
		pa(&variable_list->stack_a, &variable_list->stack_b);
		return ;
	}
	temp = variable_list->stack_a;
	headA = variable_list->stack_a;
	while (temp->next != headA && temp->data < variable_list->stack_b->data)
	{
		ra(&variable_list->stack_a);
		temp = temp->next;
	}
	pa(&variable_list->stack_a, &variable_list->stack_b);
	printf("here\n");
}

static void	print(t_dll_stack *head)
{
	t_dll_stack	*tail;

	tail = head->prev;
	while (head != tail)
	{
		printf("content: %d\n", head->data);
		head = head->next;
	}
	printf("content: %d\n", head->data);
}

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
	int	counter;
	int	size_a;

	pb(&variable_list->stack_b, &variable_list->stack_a);
	pb(&variable_list->stack_b, &variable_list->stack_a);
	print_dll(variable_list->stack_b);
	random_three_num(&variable_list->stack_a);
	printf("\n(finish 3 sort)\n");
	print_dll(variable_list->stack_a);
	counter = 0;
	if (variable_list->stack_b->data > variable_list->stack_a->prev->data)
	{
		pa(&variable_list->stack_a, &variable_list->stack_b);
		ra(&variable_list->stack_a);
	}

	insert_in_sorted_list(variable_list);
	// else if (variable_list->stack_b->data > variable_list->stack_a->prev->data)
	// {
	// 	pa(&variable_list->stack_a, &variable_list->stack_b);
	// 	// ra(&variable_list->stack_a);
	// }
	// printf("\nstack_a\n");
	// print_dll(variable_list->stack_a);
	// printf("\nstack_b\n");
	// print_dll(variable_list->stack_b);
}

