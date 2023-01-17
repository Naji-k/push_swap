// Selection sort in C

#include "push_swap.h"

// function to print an array

t_stack	*ft_new(int content, int top)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->item = content;
	new_node->top = top;
	return (new_node);
}

void	ft_stack_add_front(t_stack **stack, t_stack *head)
{
	head->next = *stack;
	*stack = head;
}

void	print_stack(t_stack *s)
{
	printf("\t<<<stack>>>\n");
	while (s != NULL)
	{
		printf("%d\t top=%d\n", s->item, s->top);
		s = s->next;
	}
}

/* int	find_largest_num(t_stack *head)
{
	int	max;
	int	index;

	index = 0;
	max = INT_MIN;
	// max = head->item;
	while (head != NULL)
	{
		if (max < head->item)
		{
			max = head->item;
			index = head->top;
		}
		head = head->next;
	}
	printf("M=%d\n", max);
	return (index);
}

int	find_smallest_num(t_stack *head)
{
	int	min;
	int	index;

	index = 0;
	min = INT_MAX;
	// min = head->item;
	while (head != NULL)
	{
		if (min > head->item)
		{
			min = head->item;
			index = head->top;
		}
		head = head->next;
	}
	printf("s=%d\n", min);
	return (index);
} */

t_stack	*ft_lststack(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	ft_stack_size(t_stack *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i + 1);
}

int	check_doubles(t_dll_stack *tail, int num)
{
	t_dll_stack	*temp;

	if (tail == NULL)
		return (0);
	temp = tail->next;
	while (tail)
	{
		if (num == temp->data)
			return (1);
		temp = temp->next;
		if (temp == tail->next)
			return (0);
	}
	return (0);
}

// void	random_three_num(t_stack **stack)
// {
// 	int	mid;
// 	int	bottom;

	/* 	int	top;
	top = (*stack)->item;
	mid = (*stack)->next->item;
	bottom = (*stack)->next->next->item;
	if (top > mid && bottom > top)
	{
		sa(*stack);
	}
	else if (top > mid && mid > bottom && bottom < top)
	{
		sa(*stack);
		rra(stack);
	}
	else if (top > mid && top > bottom && mid < bottom)
		ra(stack);
	else if (mid > top && mid > bottom && bottom > top)
	{
		sa(*stack);
		ra(stack);
	}
	else
		rra(stack); */
// }

/* void	random_five_num(t_var_list *variable_list)
{
	int	counter;
	int	size_a;

	push_top_to_another(&variable_list->stack_b, &variable_list->stack_a);
	ft_printf("pb\n");
	push_top_to_another(&variable_list->stack_b, &variable_list->stack_a);
	ft_printf("pb\n");
	random_three_num(&variable_list->stack_a);
	printf("(finish 3 sort)\n");
	print_stack(variable_list->stack_a);
	print_stack(variable_list->stack_b);
	counter = 0;
	//return back from topB to topA
	size_a = ft_stack_size(variable_list->stack_a);
	while (variable_list->stack_b)
	{
		while (variable_list->stack_b->item > variable_list->stack_a->item
			//
				&& variable_list->stack_b->item > variable_list->stack_a->next->item
			&& size_a > 0)
		{
			ra(&variable_list->stack_a);
			size_a--;
		}
		// push_top_to_another(&variable_list->stack_a,
		// 					&variable_list->stack_b);
		// ft_printf("pa\n");
		// ra(&variable_list->stack_a);
		if (variable_list->stack_b->item > variable_list->stack_a->item
			&& variable_list->stack_b->item < variable_list->stack_a->next->item)
		{
			ra(&variable_list->stack_a);
			push_top_to_another(&variable_list->stack_a,
								&variable_list->stack_b);
			ft_printf("pa\n");
			rra(&variable_list->stack_a);
		}
		else if (variable_list->stack_b->item < variable_list->stack_a->item)
		{
			push_top_to_another(&variable_list->stack_a,
								&variable_list->stack_b);
			ft_printf("pa\n");
		}
		// variable_list->stack_b = variable_list->stack_b->next;
	}
	print_stack(variable_list->stack_a);
}
 */