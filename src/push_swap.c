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

void	write_error_exit(t_var_list *variable_list)
{
	write(STDERR_FILENO, "Error\n", 6);
	if (variable_list != NULL)
	{
		free_cdll(&variable_list->stack_a);
		free_cdll(&variable_list->stack_b);
	}
	exit(EXIT_SUCCESS);
}

void	print_lst(t_list **lst)
{
	t_list	*curr;

	while (*lst != NULL)
	{
		curr = (*lst);
		if (curr->next != NULL && check_same_operations(curr) != 0)
		{
			if (check_same_operations(curr) == 1)
				ft_putstr_fd("rr\n", 1);
			else if (check_same_operations(curr) == 2)
				ft_putstr_fd("ss\n", 1);
			else if (check_same_operations(curr) == 3)
				ft_putstr_fd("rrr\n", 1);
			*lst = (*lst)->next->next;
			free(curr->next);
			free(curr);
		}
		else
		{
			ft_putstr_fd(curr->content, 1);
			*lst = (*lst)->next;
			free(curr);
		}
	}
	free(*lst);
}

void	free_cdll(t_cdll_stack **list)
{
	t_cdll_stack	*temp;
	t_cdll_stack	*tail;

	if (*list == NULL)
		return ;
	tail = (*list)->prev;
	while (*list != tail)
	{
		temp = *list;
		(*list) = (*list)->next;
		free(temp);
	}
	free(*list);
	*list = NULL;
}

void	free_all(t_var_list *variable_list)
{
	t_list	*tmp;

	free_cdll(&variable_list->stack_a);
	free_cdll(&variable_list->stack_b);
	if (variable_list->stack_output != NULL)
	{
		while (variable_list->stack_output != NULL)
		{
			tmp = variable_list->stack_output;
			variable_list->stack_output = variable_list->stack_output->next;
			free(tmp);
		}
	}
}
