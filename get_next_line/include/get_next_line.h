/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nakanoun <nakanoun@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 14:26:46 by nakanoun      #+#    #+#                 */
/*   Updated: 2022/11/21 14:26:46 by nakanoun      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

char	*get_next_line(int fd);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_substr_free(char *s, int start, int len);
int		ft_strlen_i(char *s);
int		ft_strlcpy_i(char *dst, char *src, int dstsize);
int		ft_strlcat_i(char *dst, char *src, int dstsize);
char	*ft_strchr_gnl(char *str, int c);
void	mini_cut(char *mini);
char	*read_mini_buffer(int fd, char *mini_buffer, char *buffer);

#endif