/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/03 13:19:29 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/01/03 13:19:29 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
#include <limits.h>

typedef struct stack
{
	int				item;
	int				top;
	struct stack	*next;
}					t_stack;

t_stack				*ft_new(int content, int top);
void				ft_stack_add_front(t_stack **stack, t_stack *head);

void				print_stack(t_stack *s);

#endif