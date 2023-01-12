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

t_dll_stack	*del_first(t_dll_stack *tail)
{
	t_dll_stack	*temp;

	if (tail == NULL)
		return (tail);
	temp = tail->next;
	if (temp == tail)
	{
		free(tail);
		tail = NULL;
		return (tail);
	}
	tail->next = temp->next;
	temp->next->prev = tail;
	free(temp);
	return (tail);
}

int	stack_size(t_dll_stack *head)
{
	int			count;
	t_dll_stack	*curr;

	count = 0;
	curr = head;
	while (curr != NULL)
	{
		count++;
		curr = curr->next;
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

t_dll_stack	*add_last(t_dll_stack *tail, int data)
{
	t_dll_stack	*new_node;
	t_dll_stack	*temp;

	new_node = new_circular_doubly(data);
	if (tail == NULL)
		return (new_node);
	temp = tail->next;
	new_node->next = temp;
	new_node->prev = tail;
	tail->next = new_node;
	temp->prev = new_node;
	tail = new_node;
	return (tail);
}

t_dll_stack	*rotate_dll(t_dll_stack *tail)
{
	t_dll_stack	*temp;

	temp = tail->next;
	if (tail == NULL)
		return (tail);
	return (temp);
}
t_dll_stack	*rrotate_dll(t_dll_stack *tail)
{
	t_dll_stack	*temp;

	temp = tail->prev;
	if (tail == NULL)
		return (tail);
	return (temp);
}


t_dll_stack	*swap_dll(t_dll_stack *tail)
{
	t_dll_stack	*temp;
	t_dll_stack	*temp2;

	if (tail == NULL)
		return (tail);
	temp = tail->next;
	temp2 = temp->next;
	if (temp2 == tail)
		return (temp);
	temp = temp2;
	temp2 = temp;
	return (tail);
}

void	push_top_to_dll(t_dll_stack **dst, t_dll_stack **src)
{
	t_dll_stack *head_src;

	if (*src != NULL)
	{
		head_src = (*src)->next;
		*dst = add_at_begin(*dst,head_src->data);
		*src = del_first((*src));
	}

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

void	print_dll(t_dll_stack *tail)
{
	t_dll_stack	*temp;

	if (tail == NULL)
		printf("No element is the list\n");
	else
	{
		temp = tail->next;
		while (temp)
		{
			printf("%d\n", temp->data);
			temp = temp->next;
			if (temp == tail->next)
				return ;
		}
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

/* 
int	main(void)
{
	t_dll_stack	*tail;
	t_dll_stack *tail_b = NULL;

	tail = NULL;
	// Insert 6.  So linked list becomes 6->NULL
	tail = add_last(tail, 4);
	// Insert 7 at the beginning. So linked list becomes
	// 7->6->NULL
	tail = add_at_begin(tail, 1);
	tail = insert_after(tail, 8, 2);
	// Insert 1 at the beginning. So linked list becomes
	// 1->7->6->NULL
	// tail = add_at_begin(tail, 10);
	// // Insert 4 at the end. So linked list becomes
	// // 1->7->6->4->NULL
	// tail = add_last(tail, 4);
	// // Insert 8, after 7. So linked list becomes
	// // 1->7->8->6->4->NULL
	// tail = insert_after(tail, 3, 1);
	printf("Created DLL is:\n");
	// printf("stack_size= %d\n", stack_size(head));
	print_dll(tail);
	// tail = del_inter(tail, 4);
	// swap_list(tail);
	printf("\nafter push\n");
	push_top_to_dll(&tail_b,&tail);
	push_top_to_dll(&tail_b,&tail);
	push_top_to_dll(&tail_b,&tail);

	// tail = rrotate_dll(tail);
	// printf("\nafter delete\n");
	// tail = del_first(tail);
	print_dll(tail);
	printf("\nstackB\n");

	print_dll(tail_b);
	// printf("\nafter delete last\n");
	// tail = del_last(tail);
	// print_dll(tail);
	return (0);
}
 */