/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_last_content.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 23:13:59 by nakanoun      #+#    #+#                 */
/*   Updated: 2023/02/06 23:13:59 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_last_content(t_list **lst, char *content)
{
	t_list	*new_node;
	t_list	*curr;

	curr = NULL;
	new_node = ft_lstnew(content);
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	curr = ft_lstlast(*lst);
	curr->next = new_node;
}
