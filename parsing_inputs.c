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
	int i;
	int sign;
	int num;
	int num2;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
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
