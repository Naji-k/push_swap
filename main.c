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
			if (curr->next != NULL && (((strcmp(curr->content, "ra\n") == 0
						&& strcmp(curr->next->content, "rb\n") == 0))
				|| (strcmp(curr->content, "rb\n") == 0
					&& strcmp(curr->next->content, "ra\n") == 0)))
			{
				ft_putstr_fd("rr\n", 1);
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
int	main(int argc, char **argv)
{
	t_var_list	variable_list;
	int			num;
	int			i;
	int			size;
	t_indexing	vars;

	variable_list.stack_a = NULL;
	variable_list.stack_b = NULL;
	// atexit(check_leaks);
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			if (ft_isdigit(*argv[i]) || *argv[i] == '-' || *argv[i] == '+')
			{
				num = ft_atoi_overflow(argv[i]);
				if (check_doubles(variable_list.stack_a, num))
				{
					write_error("doubles");
					return (0);
				}
				add_last(&variable_list.stack_a, num);
				i++;
			}
			else
			{
				write_error("not digit!\n");
				return (0);
			}
		}
		variable_list.size = stack_size(variable_list.stack_a);
		size = variable_list.size;
		insert_arr(&variable_list, &vars, size);
		array_insertion_sort(vars.array, size);
		if (is_cdll_sorted(variable_list.stack_a))
		{
			return (0);
		}
		else if (size <= 3)
		{
			random_three_num(&variable_list, &variable_list.stack_a);
		}
		else if (size < 6)
		{
			random_five_num(&variable_list, &vars);
		}
		else
		{
			if (size <= 10)
				vars.n = 5;
			else if (size < 150)
				vars.n = 8;
			else
				vars.n = 18;
			vars.middle = size / 2;
			vars.offset = (size / vars.n);
			vars.start_index = vars.end_index = 0;
			vars.start = vars.end = 0;
			while (size > 3)
			{
				cal_start_end(&variable_list, &vars);
				size -= a2b(&variable_list, &vars, size);
			}
			random_three_num(&variable_list, &variable_list.stack_a);
			b2a(&variable_list, &vars);
		}
	}
	// 	if (is_cdll_sorted(variable_list.stack_a))
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
