/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   circular_doubly_linked_list.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 21:29:09 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/01/10 21:29:09 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include "circular_doubly_ll.h"
#include "libft.h"

t_cdll_stack	*new_circular_doubly(int data)
{
	t_cdll_stack	*new_node;

	new_node = (t_cdll_stack *)malloc(sizeof(t_cdll_stack));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

void	cdll_insert_at_fist(t_cdll_stack **head, int value)
{
	t_cdll_stack	*new_node;
	t_cdll_stack	*tail;

	new_node = new_circular_doubly(value);
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	tail = (*head)->prev;
	new_node->prev = tail;
	new_node->next = (*head);
	(*head)->prev = new_node;
	tail->next = new_node;
	(*head) = new_node;
	return ;
}

void	del_first(t_cdll_stack **head)
{
	t_cdll_stack	*temp;

	temp = (*head)->next;
	if (*head == NULL)
		return ;
	else if (*head == (*head)->prev)
	{
		free(*head);
		*head = NULL;
	}
	else if (temp == (*head)->prev)
	{
		temp->next = temp;
		temp->prev = temp;
		free(*head);
		(*head) = temp;
	}
	else
	{
		temp->prev = (*head)->prev;
		(*head)->prev->next = temp;
		free(*head);
		*head = temp;
	}
}

int	stack_size(t_cdll_stack *head)
{
	t_cdll_stack	*tail;
	int				count;

	count = 0;
	if (head == NULL)
		return (count);
	tail = head->prev;
	while (head != tail)
	{
		head = head->next;
		count++;
	}
	count++;
	return (count);
}

void	add_last(t_cdll_stack **head, int data)
{
	t_cdll_stack	*new_node;
	t_cdll_stack	*tail;

	new_node = new_circular_doubly(data);
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	tail = (*head)->prev;
	tail->next = new_node;
	new_node->next = (*head);
	new_node->prev = tail;
	(*head)->prev = new_node;
}

void	print_cdll(t_cdll_stack *head)
{
	t_cdll_stack	*tail;

	if (head == NULL)
	{
		printf("stack is empty!");
		return ;
	}
	tail = head->prev;
	while (head != tail)
	{
		printf("content: %d\n", head->data);
		head = head->next;
	}
	printf("content: %d\n", head->data);
}