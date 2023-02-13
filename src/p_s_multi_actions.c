/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_s_multi_actions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 13:56:40 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/02/07 13:56:40 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	multi_rb(t_var_list *variable_list, int times)
{
	while (times > 0)
	{
		rb(variable_list);
		times--;
	}
	return (times);
}

int	multi_rrb(t_var_list *variable_list, int times)
{
	while (times > 0)
	{
		rrb(variable_list);
		times--;
	}
	return (times);
}

void	multi_ra(t_var_list *variable_list, int times)
{
	while (times > 0)
	{
		ra(variable_list);
		times--;
	}
}

int	multi_rra(t_var_list *variable_list, int times)
{
	while (times > 0)
	{
		rra(variable_list);
		times--;
	}
	return (times);
}
