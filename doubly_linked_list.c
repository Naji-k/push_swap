/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   doubly_linked_list.c                               :+:    :+:            */
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
	new_node->data = data;
	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}
void	insertBegin(t_dll_stack **head, int value)
{
	t_dll_stack	*new_node;
	t_dll_stack	*tail;

	// Pointer points to last Node
	new_node = new_circular_doubly(value);
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	tail = (*head)->prev;
	// setting up previous and next of new node
	new_node->prev = tail;
	new_node->next = (*head);
	(*head)->prev = new_node;
	tail->next = new_node;
	// Update next and previous pointers of start
	// and last.
	// Update start pointer
	(*head) = new_node;
	printf("new=%d \thead=%d\ttail=%d\n", new_node->data, (*head)->data,
			tail->data);
	return ;
}

t_dll_stack	*add_at_begin(t_dll_stack *tail, int data)
{
	t_dll_stack	*new_node;
	t_dll_stack	*temp;

	new_node = new_circular_doubly(data);
	if (tail == NULL)
		tail = new_node;
	else
	{
		temp = tail->next;
		new_node->next = temp;
		new_node->prev = tail;
		temp->prev = new_node;
		tail->next = new_node;
	}
	return (tail);
}

void	*del_first(t_dll_stack **head)
{
	t_dll_stack	*tail;
	t_dll_stack	*temp;

	if (*head == NULL)
		return (0);
	tail = (*head)->prev;
	temp = (*head)->next;
	// if (tail == temp)
	// {
	// 	free(*head);
	// 	*head = tail;
	// 	return (0);
	// }
	if (temp->next == tail)
	{
		temp->next = tail;
		temp->prev = tail;
		tail->next = temp;
		tail->prev = temp;
		return (0);
	}
	tail->next = temp;
	temp->prev = tail;
	printf("del=%d \thead=%d\ttail=%d\n", (*head)->data, temp->data,
			tail->data);
	free(*head);
	(*head) = temp;
	return (0);
}

int	stack_size(t_dll_stack *tail)
{
	t_dll_stack	*temp;
	int			count;

	count = 0;
	if (tail == NULL)
		printf("No element is the list\n");
	else
	{
		temp = tail->next;
		while (temp)
		{
			temp = temp->next;
			count++;
			if (temp == tail->next)
				break ;
		}
	}
	return (count);
}

t_dll_stack	*insert_after(t_dll_stack *tail, int data, int pos)
{
	t_dll_stack	*new_node;
	t_dll_stack	*temp;

	new_node = new_circular_doubly(data);
	if (tail == NULL)
		return (new_node);
	temp = tail->next;
	while (pos > 1)
	{
		temp = temp->next;
		pos--;
	}
	// temp = add_last(temp, data);
	new_node->prev = temp;
	new_node->next = temp->next;
	new_node->next->prev = new_node;
	temp->next = new_node;
	if (temp == tail)
		tail = tail->next;
	return (tail);
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
	(*head)->prev = new_node;
}

void	rotate_dll(t_dll_stack **head)
{
	t_dll_stack	*temp;

	if (*head == NULL)
		return ;
	temp = (*head)->next;
	(*head) = temp;
}
static void	print(t_dll_stack *head)
{
	t_dll_stack	*tail;

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
	(*head) = tail;
	tmp = (*head)->prev;
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
	// t_dll_stack	*head_src;
	if (*src != NULL)
	{
		// head_src = (*src)->next;
		// *dst = add_at_begin(*dst,(*src)->data);
		insertBegin(dst, (*src)->data);
		del_first(src);
	}
	// printf("p_head=%d\t_tail=%d\n", (*dst)->data, (*dst)->prev->data);
}

t_dll_stack	*del_last(t_dll_stack *tail)
{
	t_dll_stack	*temp;

	if (tail == NULL)
		return (tail);
	temp = tail->next;
	if (tail == temp)
	{
		free(tail);
		tail = NULL;
		return (tail);
	}
	tail->prev->next = temp;
	temp->prev = tail->prev;
	free(tail);
	tail = temp->prev;
	return (tail);
}

void	print_dll(t_dll_stack *head)
{
	t_dll_stack	*temp;

	if (head == NULL)
		printf("No element is the list\n");
	else
	{
		temp = head;
		while (temp->next != head)
		{
			printf("%d\n", temp->data);
			temp = temp->next;
		}
		printf("%d\n", temp->data);
	}
}

t_dll_stack	*del_inter(t_dll_stack *tail, int pos)
{
	t_dll_stack	*temp;
	t_dll_stack	*temp2;

	if (tail == NULL)
		return (tail);
	temp = tail->next;
	while (pos > 1)
	{
		temp = temp->next;
		pos--;
	}
	temp2 = temp->prev;
	temp2->next = temp->next;
	temp->next->prev = temp2;
	free(temp);
	if (temp == tail)
		tail = temp2;
	return (tail);
}

int	find_largest_num(t_dll_stack *tail)
{
	int			max;
	int			index;
	t_dll_stack	*temp;

	index = 0;
	max = INT_MIN;
	// max = head->item;
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
}

bool	is_sorted(t_dll_stack *head)
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
/* 
int	main(void)
{
	t_dll_stack	*tail;
	t_dll_stack	*tail2;

	tail = NULL;
	tail2 = NULL;
	insertBegin(&tail, 1);
	insertBegin(&tail, 3);
	insertBegin(&tail, 2);
	// insertBegin(&tail, 4);
	print_dll(tail);
	printf("\nhead =====%d\n", tail->data);
	// swap_dll(&tail);
	// swap_dll(&tail);
	// print_dll(tail);
	// rrotate_dll(&tail);
	// rrotate_dll(&tail);
	// rrotate_dll(&tail);
	random_three_num(&tail);
	printf("\nhead =====%d\n", tail->data);
	print_dll(tail);
	// pb(&tail2, &tail);
	// pb(&tail2, &tail);
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