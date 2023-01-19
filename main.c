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

int	main(int argc, char **argv)
{
	t_var_list	variable_list;
	int			num;
	int			i;
	int			size;

	variable_list.stack_a = NULL;
	//from home get segfault because this line was not exist~
	variable_list.stack_b = NULL;
	//from home get segfault because this line was not exist~
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			if (ft_isdigit(*argv[i]) || *argv[i] == '-' || *argv[i] == '+')
			{
				num = ft_atoi(argv[i]);
				if (check_doubles(variable_list.stack_a, num))
				{
					printf("doubles");
					return (0);
				}
				add_last(&variable_list.stack_a, num);
				i++;
			}
			else
			{
				printf("not digit!\n");
				return (0);
			}
		}
		size = stack_size(variable_list.stack_a);
		if (is_sorted(variable_list.stack_a))
		{
			printf("sorted\n");
			print_dll(variable_list.stack_a);
			return (0);
		}
		if (size <= 3)
		{
			print(variable_list.stack_a);
			random_three_num(&variable_list.stack_a);
			printf("print_stack(stack_a)\n");
			print(variable_list.stack_a);
			return (0);
		}
		else if (size < 6)
		{
			printf("\nrun random 5========\n");
			print_dll(variable_list.stack_a);
			// rra(&variable_list.stack_a);
			random_five_num(&variable_list);
		}
		else {
			printf("bigger than 5 size=%d\n",size);
			insert_arr(&variable_list,size);
			print_array(variable_list.array,size);

		}
		printf("\nmain.stack_a\n");
		print(variable_list.stack_a);
		printf("\nmain.stack_b\n");
		print(variable_list.stack_b);
		// pa(variable_list.stack_b,variable_list.stack_a);
		// pa(variable_list.stack_b,variable_list.stack_a);
		// print_stack(variable_list.stack_a);
		// random_five_num(&variable_list);
		// swap_stack(stack_a);
		// rrotate_stack(&variable_list.stack_a);
		// push_top_to_another(&stack_b, &stack_a);
		// swap_stack(variable_list.stack_a);
		// print_stack(stack_a);
		// printf("print_stack(stack_b)\n");
		// print_stack(stack_b);
		// push_top_to_another(&stack_a, &stack_b);
		// push_top_to_another(&stack_b, &stack_a);
		// printf("(stack_a)\n");
		// print_stack(variable_list.stack_a);
		// printf("(stack_b)\n");
		// print_stack(variable_list.stack_b);
		// printf("\nlargest=%d\n", find_largest_num(stack_a));
		// printf("\nsmallest=%d\n", find_smallest_num(stack_a));
	}
}

/* Debugging
		printf("debugging\n");
		sa(stack);
		print(*stack);
		printf("head=%d\ttail=%d head->p->p %d head->n=%d head->n->n=%d \n", (*head)->data,
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

*/
