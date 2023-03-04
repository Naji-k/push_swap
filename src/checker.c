/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 14:48:52 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/02/09 14:48:52 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "p_s_checker.h"
#include "push_swap.h"
#include <stdio.h>

void	check_leaks(void)
{
	system("leaks checker");
}

int	main(int argc, char **argv)
{
	t_var_list	variable_list;
	int			i;

	variable_list.stack_a = NULL;
	variable_list.stack_b = NULL;
	variable_list.stack_output = NULL;
	if (argc >= 2)
	{
		i = parse_input(argc, argv, &variable_list);
		if (i == 1)
			write_error_exit(&variable_list);
		read_operation(&variable_list);
		if (is_cdll_sorted(variable_list.stack_a)
			&& (variable_list.stack_b == NULL))
		{
			ft_putstr_fd("OK\n", 1);
			free_all(&variable_list);
		}
		else
		{
			ft_putstr_fd("KO\n", 1);
			free_all(&variable_list);
		}
	}
	return (0);
}

int	read_operation(t_var_list *variable_list)
{
	char	*line;
	int		i;
	int		cal_l;

	cal_l = 0;
	i = 0;
	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		cal_l = calculate_line(line);
		apply(cal_l, variable_list);
		i++;
		free(line);
	}
	return (i);
}

int	calculate_line(char *line)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (line[i] != '\n')
	{
		if (line[0] == 'r' && line[1] == 'b')
			res += 1;
		res += line[i];
		i++;
	}
	return (res);
}

void	apply(int operation, t_var_list *variable_list)
{
	static const t_push_swap_actions_list	action_list[] = {
	['s' + 'a'] = sa,
	['s' + 'b'] = sb,
	['r' + 'a'] = ra,
	['r' + 'd'] = rb,
	['p' + 'a'] = pa,
	['p' + 'b'] = pb,
	['r' + 'r' + 'a'] = rra,
	['r' + 'r' + 'b'] = rrb,
	['r' + 'r' + 'r'] = rrr,
	['r' + 'r'] = rr,
	};

	if (action_list[operation])
		action_list[operation](variable_list);
}
