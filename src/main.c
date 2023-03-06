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
	if (argc < 2)
		return (0);
	if (argc >= 2)
	{
		i = parse_input(argc, argv, &variable_list);
		variable_list.size = stack_size(variable_list.stack_a);
		insert_arr(&variable_list, &vars, variable_list.size);
		array_insertion_sort(vars.array, variable_list.size);
		if (!is_cdll_sorted(variable_list.stack_a))
			sort_numbers(&variable_list, &vars);
	}
	print_lst(&variable_list.stack_output);
	free_all(&variable_list);
}
