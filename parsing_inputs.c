/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing_inputs.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/01 14:12:24 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/02/01 14:12:24 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	check_overflow(int num1, int num2)
{
	if (num1 > 0 && num2 < 0)
		return (true);
	else if (num1 < 0 && num2 > 0)
		return (true);
	return (false);
}

int	ft_atoi_overflow(char *str)
{
	int	i;
	int	sign;
	int	num;
	int	num2;

	num = 0;
	sign = 1;
	i = 0;
	// while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
	// 	|| str[i] == '\r' || str[i] == ' ')
	// 	i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num2 = num;
		num = num * 10 + str[i] - '0';
		if (check_overflow(num * sign, num2 * sign))
		{
			write_error("over flow");
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	return (num * sign);
}

static bool	push_swap_check_valid_input(char *argv)
{
	int	i;

	i = 0;
	if (ft_isdigit(argv[i]))
		return (true);
	else if (argv[i] == '-' && ft_isdigit(argv[i + 1]))
		return (true);
	else if (argv[i] == '+' && ft_isdigit(argv[i + 1]))
		return (true);
	return (false);
}



int	parse_input(int argc, char **argv, t_var_list *variable_list)
{
	int	i;
	int	num;

	i = 1;
	while (i < argc)
	{
		if (push_swap_check_valid_input(argv[i]))
		{
			num = ft_atoi_overflow(argv[i]);
			if (check_doubles(variable_list->stack_a, num))
			{
				write_error("doubles\n");
				free_all(&variable_list->stack_a);
				return (-1);
			}
			add_last(&variable_list->stack_a, num);
			i++;
		}
		else
		{
			write_error("not digits\n");
			free_all(&variable_list->stack_a);
			return (-1);
		}
	}
	return (i - 1);
}
