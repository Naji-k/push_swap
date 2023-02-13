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

void	check_leaks(void)
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_var_list	variable_list;
	int			i;
	t_indexing	vars;

	variable_list.stack_a = NULL;
	variable_list.stack_b = NULL;
	variable_list.stack_output = NULL;
	if (argc > 1)
	{
		i = parse_input(argc, argv, &variable_list);
		if (i == -1)
			return (0);
		variable_list.size = stack_size(variable_list.stack_a);
		insert_arr(&variable_list, &vars, variable_list.size);
		array_insertion_sort(vars.array, variable_list.size);
		sort_numbers(&variable_list, &vars);
	}
	print_lst(&variable_list.stack_output);
	free_all(&variable_list.stack_a);
	free_all(&variable_list.stack_b);
}

/* Debugging
	// 	print_cdll(variable_list.stack_a);
	// if (is_cdll_sorted(variable_list.stack_a))
	// 	printf("===sorted===\n");
	// else
	// 	printf("=NOT_sorted=\n");
		printf("debugging\n");
		sa(stack);
		print_cdll(*stack);
		printf("head=%d\ttail=%d head->p->p %d head->n=%d head->n->n=%d \n",
				(*head)->data,
				(*head)->prev->data, (*head)->prev->prev->data,
				(*head)->next->data, (*head)->next->next->data);
				
		printf("head=%d\ttail=%d head->p->p %d head->n->n=%d\n", (*stack)->data,
				(*stack)->prev->data, (*stack)->prev->prev->data,
				(*stack)->next->next->data);
		printf("----------------------------------------------------------------\n");
		rra(stack);
		print_cdll(*stack);
		printf("head=%d\ttail=%d head->p->p %d head->n=%d\n", (*stack)->data,
				(*stack)->prev->data, (*stack)->prev->prev->data,
				(*stack)->next->data);


			printf("size = %d\toffset=%d\tstart=%ld\tend=%ld\n",
					variable_list.size,
					variable_list.offset,
					variable_list.start,
					variable_list.end);

				
*/
