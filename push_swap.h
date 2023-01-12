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

# include "../printf/ft_printf.h"
# include <limits.h>
# include <stdio.h>

typedef struct stack
{
	int					item;
	int					top;
	struct stack		*next;
}						t_stack;

typedef struct dll_stack
{
	int					data;
	struct dll_stack	*next;
	struct dll_stack	*prev;
}						t_dll_stack;
typedef struct s_variable_list
{
	t_dll_stack			*stack_a;
	t_dll_stack			*stack_b;
}						t_var_list;

t_stack					*ft_new(int content, int top);
void					ft_stack_add_front(t_stack **stack, t_stack *head);
void					print_stack(t_stack *s);
int						ft_stack_size(t_stack *lst);
void					rotate_stack(t_stack **stack);
void					rrotate_stack(t_stack **stack);
int						check_doubles(t_dll_stack *stack, int num);
t_stack					*ft_lststack(t_stack *lst);
void					push_top_to_another(t_stack **dst, t_stack **src);
void					swap_stack(t_stack *stack);
void					pop(t_stack **stack);
void					ft_swap(t_stack *a, t_stack *b);
int						find_smallest_num(t_stack *head);
int						find_largest_num(t_stack *head);

void					random_three_num(t_dll_stack **stack);
void					sa(t_dll_stack **stack);
void					ra(t_dll_stack *stack);
void					rra(t_dll_stack *stack);
void					random_five_num(t_var_list *variable_list);
//Doubly linked list
t_dll_stack				*new_circular_doubly(int data);
t_dll_stack				*add_at_begin(t_dll_stack *tail, int data);
t_dll_stack				*add_last(t_dll_stack *tail, int data);
t_dll_stack				*del_first(t_dll_stack *tail);
t_dll_stack				*del_last(t_dll_stack *tail);
int						stack_size(t_dll_stack *head);
t_dll_stack				*insert_after(t_dll_stack *tail, int data, int pos);
t_dll_stack				*del_inter(t_dll_stack *tail, int pos);
//actions
t_dll_stack				*rotate_dll(t_dll_stack *tail);
t_dll_stack				*rrotate_dll(t_dll_stack *tail);
t_dll_stack				*swap_dll(t_dll_stack *tail);
void					push_top_to_dll(t_dll_stack **dst, t_dll_stack **src);
void					print_dll(t_dll_stack *tail);

#endif