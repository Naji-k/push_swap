/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/05 00:30:14 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/01/05 00:30:14 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

int	check_doubles(t_dll_stack *tail, int num)
{
	t_dll_stack	*temp;

	if (tail == NULL)
		return (0);
	temp = tail->next;
	while (tail)
	{
		if (num == temp->data)
			return (1);
		temp = temp->next;
		if (temp == tail->next)
			return (0);
	}
	return (0);
}

void	check_leaks(void)
{
	system("leaks -q push_swap");
}

void	print_lst(t_list **lst)
{
	t_list	*curr;

	while ((*lst) != NULL)
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
			free(curr->next);
			*lst = (*lst)->next->next;
			free(curr);
		}
		else
		{
			ft_putstr_fd(curr->content, 1);
			free(curr);
			*lst = (*lst)->next;
		}
	}
}

void	write_error(char *error_str)
{
	write(2, error_str, ft_strlen(error_str));
}

void	free_all(t_dll_stack **list)
{
	t_dll_stack	*temp;
	t_dll_stack	*tail;

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

void	free_exit(t_var_list *variable_list)
{
	free_all(&variable_list->stack_a);
	free_all(&variable_list->stack_b);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_var_list	variable_list;
	int			i;
	t_indexing	vars;

	// int			size;
	// int			num;
	variable_list.stack_a = NULL;
	variable_list.stack_b = NULL;
	// atexit(check_leaks);
	if (argc > 1)
	{
		// i = 1;
		i = parse_input(argc, argv, &variable_list);
		if (i == -1)
			return (0);
		// printf("i=%d\n", i);
		variable_list.size = stack_size(variable_list.stack_a);
		insert_arr(&variable_list, &vars, variable_list.size);
		array_insertion_sort(vars.array, variable_list.size);
		sort_numbers(&variable_list, &vars);
	}
	// 	print(variable_list.stack_a);
	// if (is_cdll_sorted(variable_list.stack_a))
	// 	printf("===sorted===\n");
	// else
	// 	printf("=NOT_sorted=\n");
	print_lst(&variable_list.stack_output);
	free_all(&variable_list.stack_a);
	free_all(&variable_list.stack_b);
}

/* Debugging
		printf("debugging\n");
		sa(stack);
		print(*stack);
		printf("head=%d\ttail=%d head->p->p %d head->n=%d head->n->n=%d \n",
				(*head)->data,
				(*head)->prev->data, (*head)->prev->prev->data,
				(*head)->next->data, (*head)->next->next->data);
				
		printf("head=%d\ttail=%d head->p->p %d head->n->n=%d\n", (*stack)->data,
				(*stack)->prev->data, (*stack)->prev->prev->data,
				(*stack)->next->next->data);
		printf("----------------------------------------------------------------\n");
		rra(stack);
		print(*stack);
		printf("head=%d\ttail=%d head->p->p %d head->n=%d\n", (*stack)->data,
				(*stack)->prev->data, (*stack)->prev->prev->data,
				(*stack)->next->data);


			printf("size = %d\toffset=%d\tstart=%ld\tend=%ld\n",
					variable_list.size,
					variable_list.offset,
					variable_list.start,
					variable_list.end);

				
*/
