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

# include "libft.h"
# include "circular_doubly_ll.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_variable_list
{
	t_cdll_stack	*stack_a;
	t_cdll_stack	*stack_b;
	t_list			*stack_output;
	int				size;
}					t_var_list;

typedef struct s_indexing
{
	int				start;
	int				end;
	int				start_index;
	int				end_index;
	int				middle;
	int				offset;
	int				n;
	int				array[1000];
}					t_indexing;

void	random_five_num(t_var_list *variable_list,
			t_indexing *vars);
int		check_doubles(t_cdll_stack *stack, int num);
void	random_three_num(t_var_list *variable_list,
			t_cdll_stack **stack);
//actions
void	sa(t_var_list *variable_list);
void	sb(t_var_list *variable_list);
void	ra(t_var_list *variable_list);
void	rb(t_var_list *variable_list);
void	pa(t_var_list *variable_list);
void	pb(t_var_list *variable_list);
void	rra(t_var_list *variable_list);
void	rrb(t_var_list *variable_list);
void	rr(t_var_list *variable_list);
void	rrr(t_var_list *variable_list);
void	multi_ra(t_var_list *variable_list, int times);
int		multi_rra(t_var_list *variable_list, int times);
int		multi_rb(t_var_list *variable_list, int times);
int		multi_rrb(t_var_list *variable_list, int times);
void	check_top_b(t_cdll_stack **stack);
//arr
void	insert_arr(t_var_list *variable_list, t_indexing *list,
			int size);
void	print_array(int *arr, int size);
void	array_insertion_sort(int array[], int size);
//algorithm
void	cal_start_end(t_var_list *variable_list,
			t_indexing *list);
bool	in_range(int start, int end, t_cdll_stack *curr);
int		a2b(t_var_list *variable_list, t_indexing *list, int size);
void	insert_in_sorted_list(t_var_list *variable_list);
int		search_for_highest(t_cdll_stack *stack, t_indexing *vars,
			int size);
void	b2a(t_var_list *variable_list, t_indexing *vars);
void	check_top_a(t_var_list **variable_list);
void	write_error(char *error_str);
int		ft_atoi_overflow(char *str);
int		check_same_operations(t_list *lst);
int		parse_input(int argc, char **argv,
			t_var_list *variable_list);
void	sort_numbers(t_var_list *variable_list,
			t_indexing *vars);
void	sort_big_numbers(t_var_list *variable_list,
			t_indexing *vars);
void	write_error_exit(t_var_list *variable_list);
void	print_lst(t_list **lst);
void	push_smallest_number_2b(t_var_list *variable_list,
			t_indexing *vars,
			int i);
int		p2a_check_top_a(t_var_list *variable_list, int size);
int		b2a_highest_from_top_b(t_var_list *variable_list,
			t_indexing *vars,
			int level,
			int size);
int		b2a_highest_from_bottom_b(t_var_list *variable_list,
			t_indexing *vars,
			int level,
			int size);
void	free_all(t_var_list *variable_list);

#endif