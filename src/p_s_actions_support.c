/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_s_actions_support.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 13:46:24 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/02/07 13:46:24 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_dll(t_cdll_stack **head)
{
	t_cdll_stack	*temp;
	t_cdll_stack	*tail;

	if (head == NULL)
		return ;
	temp = (*head)->next;
	tail = (*head)->prev;
	if (temp == tail)
	{
		(*head) = temp;
		return ;
	}
	temp->next->prev = (*head);
	(*head)->next = temp->next;
	(*head)->prev = temp;
	temp->next = (*head);
	temp->prev = tail;
	(*head) = temp;
	tail->next = (*head);
}

void	rotate_dll(t_cdll_stack **head)
{
	t_cdll_stack	*tail;

	if (*head == NULL)
		return ;
	tail = (*head)->prev;
	tail = (*head);
	(*head) = (*head)->next;
	(*head)->prev = tail;
	tail->next = (*head);
}

void	rrotate_dll(t_cdll_stack **head)
{
	t_cdll_stack	*tail;
	t_cdll_stack	*tmp;

	if (*head == NULL)
		return ;
	tail = (*head)->prev;
	tmp = tail->prev;
	(*head) = tail;
	(*head)->prev = tmp;
	tmp->next = (*head);
	tail = tmp;
}

void	push_top_to_cdll(t_cdll_stack **dst, t_cdll_stack **src)
{
	if (*src != NULL)
	{
		cdll_insert_at_fist(dst, (*src)->data);
		del_first(src);
	}
	return ;
}

bool	is_cdll_sorted(t_cdll_stack *head)
{
	t_cdll_stack	*temp;

	if (head == NULL)
		return (true);
	temp = head;
	while (temp->next != head)
	{
		if (temp->data > temp->next->data)
			return (false);
		temp = temp->next;
	}
	return (true);
}
