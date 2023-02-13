/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 14:26:33 by nakanoun      #+#    #+#                 */
/*   Updated: 2022/11/21 14:26:33 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_i(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str_join;
	int		s1_len;
	int		s2_len;

	str_join = NULL;
	s1_len = 0;
	s2_len = 0;
	if (s1 != NULL)
		s1_len = ft_strlen_i(s1);
	if (s2 != NULL)
		s2_len = ft_strlen_i(s2);
	str_join = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str_join == NULL)
		return (free(s1), NULL);
	ft_strlcpy_i(str_join, s1, s1_len + 1);
	ft_strlcat_i(str_join, s2, s1_len + s2_len + 1);
	free(s1);
	return (str_join);
}

int	ft_strlcat_i(char *dst, char *src, int dstsize)
{
	int	len_dst;
	int	i;
	int	j;

	i = 0;
	j = 0;
	len_dst = ft_strlen_i(dst);
	if (len_dst >= dstsize)
		return (ft_strlen_i(src) + dstsize);
	while (dst[i])
		i++;
	while (j < dstsize - len_dst - 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen_i(src) + len_dst);
}

int	ft_strlcpy_i(char *dst, char *src, int dstsize)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (src[s])
		s++;
	if (dstsize == 0)
		return (s);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (s);
}
