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

int	search_for_highest(t_dll_stack *stack, t_indexing *vars, int size)
{
	int			level;
	t_dll_stack	*tail;

	tail = stack->prev;
	level = 0;
	// printf("h=%d\n", vars->array[size - 1]);
	// while (stack->data != vars->array[size - 1] && stack != tail)
	while (stack->data != vars->array[size] && stack != tail)
	{
		stack = stack->next;
		level++;
		if (stack->data == vars->array[size])
		{
			// printf("H=%d\n", stack->data);
			return (level);
		}
		// else if (stack->data == vars->array[size - 2])
		// 	return (level);
	}
	// while (temp2->data != vars->array[size - 1] && level < offset)
	// {
	// 	temp2 = temp2->next;
	// 	level++;
	// 	if (temp2->data == vars->array[size - 1])
	// 		return (-level);
	// }
	return (level);
}


void	b2a(t_var_list *variable_list, t_indexing *vars)
{
	int	level;
	int	size;
	int	highest;
	int temp;

	size = stack_size(variable_list->stack_b);
	level = 0;
	// printf("%d", search_for_highest(variable_list->stack_b, vars->array,
	// size));
	while (variable_list->stack_b != NULL)
	{
		highest = size - 1;
		level = search_for_highest(variable_list->stack_b, vars, highest);
		// printf("level_OUT=%d\n", level);
		// printf("======here=====\n");
		if (level == 0)
		{
			if (variable_list->stack_b->data == vars->array[size - 1])
			{
				pa(variable_list);
				check_top_a(&variable_list);
				size--;
			}
			else
				break ;
		}
		else if (level <= (size / 2))
		{
			// multi_rb(&variable_list->stack_b, level);
			while (level > 0)
			{
				// rb(&variable_list->stack_b);
				rb(variable_list);
				level--;
				if (variable_list->stack_b->data == vars->array[highest - 1])
				{
					pa(variable_list);
					check_top_a(&variable_list);
					level--;
					size--;
				}
			}
			pa(variable_list);
			check_top_a(&variable_list);
			size--;
		}
		else if (level > (size / 2))
		{
			temp = size - level;
			// printf("level=%d\tsize=%d", level, size);
			// multi_rrb(&variable_list->stack_b, size - level);
			while ((temp) > 0)
			{
				// rrb(&variable_list->stack_b);
				rrb(variable_list);
				temp--;
				if (variable_list->stack_b->data == vars->array[highest - 1])
				{
					pa(variable_list);
					check_top_a(&variable_list);
					size--;
				}
			}
			pa(variable_list);
			check_top_a(&variable_list);
			size--;
		}
	}
}

/* void	insert_in_sorted_list(t_var_list *variable_list)
{
	int	level;

	level = 0;
	while (variable_list->stack_b != NULL)
	{
		// make sure highest number is on top of stack b
		// also look for the next number
		// push highest - 1, call same function recursively
		// let the function finish and swap a in the old function
		if (variable_list->stack_a == NULL)
			pa(variable_list);
		if (variable_list->stack_b != NULL
			&& variable_list->stack_b->data > variable_list->stack_a->prev->data)
		{ //if headB > tailA
			// pa(&variable_list->stack_a, &variable_list->stack_b);
			pa(variable_list);
			// check_top_b(&variable_list->stack_b);
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
} */

// void	check_top_b(t_dll_stack **stack)
// {
// 	t_dll_stack	*head;
// 	t_dll_stack	*next;

// 	//put the biggest on top
// 	if ((*stack) != NULL)
// 	{
// 		head = (*stack);
// 		next = (*stack)->next;
// 		if (next->data > head->data)
// 		{
// 			swap_dll(stack);
// 			ft_printf("sb\n");
// 		}
// 	}
// }
void	check_top_a(t_var_list **variable_list)
{
	t_dll_stack	*head;
	t_dll_stack	*next;

	//put the smallest on top
	if ((*variable_list)->stack_a != NULL)
	{
		head = (*variable_list)->stack_a;
		next = (*variable_list)->stack_a->next;
		if (next->data < head->data)
		{
			sa(*variable_list);
		}
	}
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
		// rra(stack);
		rra(variable_list);
	}
	else if (top > mid && top > bottom && mid < bottom)
		// ra(stack);
		ra(variable_list);
	else if (mid > top && mid > bottom && bottom > top)
	{
		sa(variable_list);
		// ra(stack);
		ra(variable_list);
	}
	else if (mid > top && top > bottom && mid > bottom)
		// rra(stack);
		rra(variable_list);
}

void	push_smallest_number(t_var_list *variable_list, t_indexing *vars, int i)
{
	t_dll_stack	*temp;
	int			level;
	int			size;

	size = stack_size(variable_list->stack_a);
	level = 0;
	temp = variable_list->stack_a;
	while (temp->data != vars->array[i])
	{
		level++;
		temp = temp->next;
	}
	if (level > 2)
	{
		// multi_rra(&variable_list->stack_a, size - level);
		multi_rra(variable_list, size - level);
		pb(variable_list);
	}
	else if (level <= 2)
	{
		// multi_ra(&variable_list->stack_a, level);
		multi_ra(variable_list, level);
		pb(variable_list);
	}
}

void	random_five_num(t_var_list *variable_list, t_indexing *vars)
{
	push_smallest_number(variable_list, vars, 0);
	push_smallest_number(variable_list, vars, 1);
	// exit(0);
	// pb(variable_list);
	// pb(variable_list);
	random_three_num(variable_list, &variable_list->stack_a);
	pa(variable_list);
	pa(variable_list);
	// printf("\n(finish 3 sort)\n");
	// printf("==================\n");
	// insert_in_sorted_list(variable_list);
}
