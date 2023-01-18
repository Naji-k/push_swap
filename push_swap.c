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

int	insert_in_sorted_list(t_var_list *variable_list)
{
	int	counter;

	counter = 0;
	if (variable_list->stack_b != NULL
		&& variable_list->stack_b->data > variable_list->stack_a->prev->data)
	{ //if headB > tailA
		pa(&variable_list->stack_a, &variable_list->stack_b);
		ra(&variable_list->stack_a);
		print(variable_list->stack_a);
	}
	else if (variable_list->stack_b != NULL
			&& variable_list->stack_b->data < variable_list->stack_a->data)
	{
		pa(&variable_list->stack_a, &variable_list->stack_b);
	}
	while (variable_list->stack_b != NULL
		&& variable_list->stack_b->data > variable_list->stack_a->data)
	{
		ra(&variable_list->stack_a);
		counter++;
		if (variable_list->stack_b->data < variable_list->stack_a->next->data)
			pa(&variable_list->stack_a, &variable_list->stack_b);
		if (variable_list->stack_b == NULL)
			return (counter);
	}
	return (counter);
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
	print(variable_list->stack_b);
	random_three_num(&variable_list->stack_a);
	printf("\n(finish 3 sort)\n");
	print(variable_list->stack_a);
	insert_in_sorted_list(variable_list);


	printf("out of sort 5\n");
	print(variable_list->stack_a);
	if (is_sorted(variable_list->stack_a))
		printf("sorted");
	else
		printf("NOT_sorted");
	// insert_in_sorted_list(variable_list);
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
