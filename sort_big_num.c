/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_big_num.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 00:39:00 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/01/19 00:39:00 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_arr(t_var_list *variable_list, int size)
{
	t_dll_stack	*tail;
	t_dll_stack	*current;
	int			arr[size];
	int			i;

	tail = variable_list->stack_a->prev;
	current = variable_list->stack_a;
	i = 0;
	while (current != tail)
	{
		arr[i] = current->data;
		i++;
		current = current->next;
	}
	arr[++i] = current->data;
	variable_list->array = arr;
}

void	print_array(int *arr, int size)
{
	int i = 0;
	printf("array= ");
	while (i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
}