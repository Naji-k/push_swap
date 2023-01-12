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
	t_dll_stack	*new_node;
	int			num;
	int			top;
	int			i;

	// variable_list.stack_a = stack_a;
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			if (ft_isdigit(*argv[i]) || *argv[i] == '-' || *argv[i] == '+')
			{
				num = ft_atoi(argv[i]);
				// new_node = new_circular_doubly(num);
				if (check_doubles(variable_list.stack_a, num))
				{
					printf("doubles");
					return (0);
				}
				variable_list.stack_a = add_at_begin(variable_list.stack_a,
														num);
				i++;
			}
			else
			{
				printf("not digit!\n");
				return (0);
			}
		}
		print_dll(variable_list.stack_a);
		// print_stack(variable_list.stack_a);
		random_three_num(&variable_list.stack_a);
		print_dll(variable_list.stack_a);
		// random_five_num(&variable_list);
		// swap_stack(stack_a);
		// rrotate_stack(&variable_list.stack_a);
		// push_top_to_another(&stack_b, &stack_a);
		// swap_stack(variable_list.stack_a);
		// printf("print_stack(stack_a)\n");
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
