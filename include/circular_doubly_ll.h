/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   circular_doubly_ll.h                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 15:04:11 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/02/08 15:04:11 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCULAR_DOUBLY_LL_H
# define CIRCULAR_DOUBLY_LL .H

# include "libft.h"
# include <stdbool.h>

typedef struct s_cdll_stack
{
	int					data;
	struct s_cdll_stack	*next;
	struct s_cdll_stack	*prev;
}						t_cdll_stack;

t_cdll_stack			*new_circular_doubly(int data);
void					add_last(t_cdll_stack **head, int data);
void					del_first(t_cdll_stack **head);
void					print_dll(t_cdll_stack *head);
void					cdll_insert_at_fist(t_cdll_stack **head, int value);
void					print_cdll(t_cdll_stack *head);
int						stack_size(t_cdll_stack *tail);
bool					is_cdll_sorted(t_cdll_stack *head);
void					free_cdll(t_cdll_stack **list);
void					swap_dll(t_cdll_stack **head);
void					rotate_dll(t_cdll_stack **head);
void					rrotate_dll(t_cdll_stack **head);
void					push_top_to_cdll(t_cdll_stack **dst,
							t_cdll_stack **src);

#endif