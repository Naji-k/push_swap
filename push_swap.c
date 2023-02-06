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
	while (stack->data != vars->array[size] && stack != tail)
	{
		stack = stack->next;
		level++;
		if (stack->data == vars->array[size])
			return (level);
	}
	return (level);
}

static int	pa_check_top(t_var_list *variable_list, int size)
{
	pa(variable_list);
	check_top_a(&variable_list);
	size--;
	return (size);
}

static int	b2a_highest_from_top_b(t_var_list *variable_list, t_indexing *vars,
		int level, int size)
{
	int	highest;

	highest = size - 1;
	while (level > 0)
	{
		rb(variable_list);
		level--;
		if (variable_list->stack_b->data == vars->array[highest - 1])
		{
			size = pa_check_top(variable_list, size);
			level--;
		}
	}
	size = pa_check_top(variable_list, size);
	return (size);
}

static int	b2a_highest_from_bottom_b(t_var_list *variable_list,
										t_indexing *vars,
										int level,
										int size)
{
	int	temp;
	int	highest;

	highest = size - 1;
	temp = size - level;
	while ((temp) > 0)
	{
		rrb(variable_list);
		temp--;
		if (variable_list->stack_b->data == vars->array[highest - 1])
			size = pa_check_top(variable_list, size);
	}
	size = pa_check_top(variable_list, size);
	return (size);
}

void	b2a(t_var_list *variable_list, t_indexing *vars)
{
	int	level;
	int	size;
	int	highest;

	size = stack_size(variable_list->stack_b);
	level = 0;
	while (variable_list->stack_b != NULL)
	{
		highest = size - 1;
		level = search_for_highest(variable_list->stack_b, vars, highest);
		if (level == 0)
		{
			if (variable_list->stack_b->data == vars->array[size - 1])
				size = pa_check_top(variable_list, size);
			else
				break ;
		}
		else if (level <= (size / 2))
			size = b2a_highest_from_top_b(variable_list, vars, level, size);
		else if (level > (size / 2))
			size = b2a_highest_from_bottom_b(variable_list, vars, level, size);
	}
}

void	check_top_a(t_var_list **variable_list)
{
	t_dll_stack	*head;
	t_dll_stack	*next;

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
		rra(variable_list);
	}
	else if (top > mid && top > bottom && mid < bottom)
		ra(variable_list);
	else if (mid > top && mid > bottom && bottom > top)
	{
		sa(variable_list);
		ra(variable_list);
	}
	else if (mid > top && top > bottom && mid > bottom)
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
		multi_rra(variable_list, size - level);
		pb(variable_list);
	}
	else if (level <= 2)
	{
		multi_ra(variable_list, level);
		pb(variable_list);
	}
}

void	random_five_num(t_var_list *variable_list, t_indexing *vars)
{
	push_smallest_number(variable_list, vars, 0);
	if (variable_list->size == 5)
		push_smallest_number(variable_list, vars, 1);
	random_three_num(variable_list, &variable_list->stack_a);
	pa(variable_list);
	pa(variable_list);
}

int	check_same_operations(t_list *lst)
{
	t_list	*curr;

	curr = lst;
	if (((ft_strncmp(curr->content, "ra\n", 2) == 0
				&& ft_strncmp(curr->next->content, "rb\n", 2) == 0))
		|| (ft_strncmp(curr->content, "rb\n", 2) == 0
			&& ft_strncmp(curr->next->content, "ra\n", 2) == 0))
	{
		return (1);
	}
	else if (((ft_strncmp(curr->content, "sa\n", 2) == 0
				&& ft_strncmp(curr->next->content, "sb\n", 2) == 0))
		|| (ft_strncmp(curr->content, "sb\n", 2) == 0
			&& ft_strncmp(curr->next->content, "sa\n", 2) == 0))
	{
		return (2);
	}
	else if (((ft_strncmp(curr->content, "rra\n", 3) == 0
				&& ft_strncmp(curr->next->content, "rrb\n", 3) == 0))
		|| (ft_strncmp(curr->content, "rrb\n", 3) == 0
			&& ft_strncmp(curr->next->content, "rra\n", 3) == 0))
	{
		return (3);
	}
	return (0);
}
