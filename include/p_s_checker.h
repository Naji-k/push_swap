/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_s_checker.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/09 21:35:11 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/02/09 21:35:11 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef void	(*t_push_swap_actions_list)(t_var_list *variable_list);
int				read_operation(t_var_list *variable_list);
void			apply(int operation, t_var_list *variable_list);
int				calculate_line(char *line);