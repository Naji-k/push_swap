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

# include "./libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

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
	t_list				*stack_output;
	int					size;
}						t_var_list;

typedef struct s_indexing
{
	int					start;
	int					end;
	int					start_index;
	int					end_index;
	int					middle;
	int					offset;
	int					n;
	int					array[1000];
}						t_indexing;

void	random_five_num(t_var_list *variable_list,
						t_indexing *vars);
void					rotate_stack(t_stack **stack);
void					rrotate_stack(t_stack **stack);
int						check_doubles(t_dll_stack *stack, int num);
void					push_top_to_another(t_stack **dst, t_stack **src);
void					swap_stack(t_stack *stack);
void					pop(t_stack **stack);
void					ft_swap(t_stack *a, t_stack *b);
void	random_three_num(t_var_list *variable_list,
						t_dll_stack **stack);
//Doubly linked list
t_dll_stack				*new_circular_doubly(int data);
void					add_last(t_dll_stack **head, int data);
void					del_first(t_dll_stack **head);
//actions
void					sa(t_var_list *variable_list);
void					sb(t_var_list *variable_list);
void					ra(t_var_list *variable_list);
void					rra(t_var_list *variable_list);
void					pa(t_var_list *variable_list);
void					pb(t_var_list *variable_list);
void					rb(t_var_list *variable_list);
void					rrb(t_var_list *variable_list);
void					rotate_dll(t_dll_stack **head);
void					rrotate_dll(t_dll_stack **head);
void					push_top_to_dll(t_dll_stack **dst, t_dll_stack **src);
void					print_dll(t_dll_stack *head);
int						multi_rra(t_var_list *variable_list, int times);
void					multi_ra(t_var_list *variable_list, int times);
int						multi_rrb(t_var_list *variable_list, int times);
int						multi_rb(t_var_list *variable_list, int times);
void					rr(t_dll_stack **stack_a, t_dll_stack **stack_b);
void					rrr(t_dll_stack **stack_a, t_dll_stack **stack_b);
void					check_top_b(t_dll_stack **stack);
void					cdll_insert_at_fist(t_dll_stack **head, int value);
void					swap_dll(t_dll_stack **head);
int						stack_size(t_dll_stack *tail);
bool					is_cdll_sorted(t_dll_stack *head);
void					print(t_dll_stack *head);

//arr
void					insert_arr(t_var_list *variable_list, t_indexing *list,
							int size);
void					print_array(int *arr, int size);
void					array_insertion_sort(int array[], int size);
void	cal_start_end(t_var_list *variable_list,
					t_indexing *list);
bool					in_range(int start, int end, t_dll_stack *curr);
int						a2b(t_var_list *variable_list, t_indexing *list,
							int size);

void					insert_in_sorted_list(t_var_list *variable_list);
int						search_for_highest(t_dll_stack *stack, t_indexing *vars,
							int size);
void					b2a(t_var_list *variable_list, t_indexing *vars);
void					b2A(t_var_list *var_list, t_indexing *vars);
int						find_highest_1(t_dll_stack *stack, t_indexing *vars,
							int size);
void					check_top_a(t_var_list **variable_list);
void					write_error(char *error_str);
int						ft_atoi_overflow(char *str);
int						A2B(t_var_list *variable_list, t_indexing *list,
							int size);
int						check_same_operations(t_list *lst);
int						parse_input(int argc, char **argv,
							t_var_list *variable_list);
void					free_all(t_dll_stack **list);
void	sort_numbers(t_var_list *variable_list,
					t_indexing *vars);
void	sort_big_numbers(t_var_list *variable_list,
						t_indexing *vars);
#endif