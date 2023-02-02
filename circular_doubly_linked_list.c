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

t_dll_stack	*new_circular_doubly(int data)
{
	t_dll_stack	*new_node;

	new_node = (t_dll_stack *)malloc(sizeof(t_dll_stack));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

void	cdll_insert_at_fist(t_dll_stack **head, int value)
{
	t_dll_stack	*new_node;
	t_dll_stack	*tail;

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

void	del_first(t_dll_stack **head)
{
	t_dll_stack	*tail;

	tail = (*head)->prev;
	if (*head == NULL)
		return ;
	else if (*head == (*head)->next)
	{
		free(*head);
		*head = NULL;
	}
	else if ((*head)->next == tail)
	{
		(*head)->next->next = (*head)->next;
		(*head)->next->prev = (*head)->next;
		free(*head);
		(*head) = (*head)->next;
	}
	else
	{
		(*head)->next->prev = tail;
		tail->next = (*head)->next;
		free(*head);
		*head = (*head)->next;
	}
}

int	stack_size(t_dll_stack *head)
{
	t_dll_stack	*tail;
	int			count;

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

void	add_last(t_dll_stack **head, int data)
{
	t_dll_stack	*new_node;
	t_dll_stack	*tail;

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

void	rotate_dll(t_dll_stack **head)
{
	t_dll_stack	*tail;

	if (*head == NULL)
		return ;
	tail = (*head)->prev;
	tail = (*head);
	(*head) = (*head)->next;
	(*head)->prev = tail;
	tail->next = (*head);
}

void	print(t_dll_stack *head)
{
	t_dll_stack	*tail;

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

void	rrotate_dll(t_dll_stack **head)
{
	t_dll_stack	*tail;
	t_dll_stack	*tmp;

	if (*head == NULL)
		return ;
	tail = (*head)->prev;
	tmp = tail->prev;
	(*head) = tail;
	(*head)->prev = tmp;
	tmp->next = (*head);
	tail = tmp;
}

void	swap_dll(t_dll_stack **head)
{
	t_dll_stack	*temp;
	t_dll_stack	*tail;

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

void	push_top_to_dll(t_dll_stack **dst, t_dll_stack **src)
{
	if (*src != NULL)
	{
		cdll_insert_at_fist(dst, (*src)->data);
		del_first(src);
	}
	return ;
}

bool	is_cdll_sorted(t_dll_stack *head)
{
	t_dll_stack	*temp;

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

/* void	del_last(t_dll_stack *head)
{
	t_dll_stack	*temp;

	if (head == NULL)
		return ;
	temp = head->prev;
	if (head == temp)
	{
		free(head);
		head = NULL;
		return ;
	}
	head->prev = temp->prev;
	temp->prev->next = head;
	free(temp);
} */

/* int	find_largest_num(t_dll_stack *tail)
{
	int			max;
	int			index;
	t_dll_stack	*temp;

	index = 0;
	max = INT_MIN;
	temp = tail->next;
	while (temp)
	{
		if (max < temp->data)
		{
			max = temp->data;
			index++;
		}
		temp = temp->next;
		if (temp == tail)
			break ;
	}
	printf("Max=%d\n", max);
	return (index);
}

int	find_smallest_num(t_dll_stack *tail)
{
	int			min;
	int			index;
	t_dll_stack	*temp;
	t_dll_stack	*temp;

	index = 0;
	min = INT_MAX;
	// min = head->item;
	temp = tail->next;
	while (tail != NULL)
	{
		if (min > tail->data)
		{
			min = tail->data;
			index++;
		}
		tail = tail->next;
		if (temp == tail)
			break ;
	}
	printf("Min=%d\n", min);
	return (index);
} */
/* 
int	main(void)
{
	t_dll_stack	*tail;
	t_dll_stack	*tail2;

	tail = NULL;
	tail2 = NULL;
	// atexit(check_leaks);
	// tail = new_circular_doubly(4);
	add_last(&tail, 1);
	add_last(&tail, 3);
	add_last(&tail, 2);
	add_last(&tail, 5);
	del_last(tail);
	add_last(&tail, 4);
	// push_top_to_dll(&tail2,&tail);
	// push_top_to_dll(&tail2,&tail);
	// swap_dll(&tail);
	printf("head=%d\ttail=%d head->p->p %d head->n=%d head->n->n=%d \n",
			tail->data,
			tail->prev->data,
			tail->prev->prev->data,
			tail->next->data,
			tail->next->next->data);
	// rotate_dll(&tail);
	// rrotate_dll(&tail);
	print(tail);
	// in_range(0,15,tail);
	// printf(("stack_size= %d\n\n"),stack_size(tail));
	// printf("\nhead =====%d\n", tail->data);
	// exit(0);
	// swap_dll(&tail);
	// print_dll(tail);
	// rrotate_dll(&tail);
	// random_three_num(&tail);
	// printf("\nhead =====%d\n", tail->data);
	// print(tail);
	// pb(&tail2, &tail);
	// pb(&tail2, &tail);
	// del_first(&tail);
	// printf("\ndel1_head%d==head.next=%d=head.prev=%d\n", tail->data,
	// 		tail->next->data, tail->prev->data);
	// print(tail);
	// ra(&tail);
	// printf("\ndel2_head%d==head.next=%d=head.prev=%d\n", tail->data,
	// 		tail->next->data, tail->prev->data);
	// print(tail);
	// printf("debugging\n");
	// del_first(&tail);
	// ra(&tail);
	// exit(0);
	// del_first(&tail);
	// pa(&tail, &tail2);
	// printf("\ndel2_head%d==head.next=%d=head.prev=%d\n", tail->data,
	// 		tail->next->data, tail->prev->data);
	// print(tail);
	// printf("\ndel3_head%d==head.next=%d=head.prev=%d\n",
	// tail->data,tail->next->data, tail->prev->data);
	// print(tail);
	// print(tail2);
	// print(tail2);
	// printf("\ndel_head =====%d\n", tail->data);
	// print_dll(tail);
	// printf("\nstack2\n");
	// print_dll(tail2);
	// printf("\nstack1\n");
	// print_dll(tail);
	// pa(&tail, &tail2);
	// printf("\nstack1\n");
	// print_dll(tail);
	// printf("\nstack2\n");
	// print_dll(tail2);
	// printf("index of max=%d",find_largest_num(tail));
}
 */