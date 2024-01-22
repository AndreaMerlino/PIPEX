/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:51:37 by andreamerli       #+#    #+#             */
/*   Updated: 2024/01/19 19:02:35 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 300
# endif

void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
int		newline(char *s);
int		ft_pstrlen(const char *s);
char	*ft_substr(char *s, int start, int len);
char	*ft_strlcpy(char *dst, char *src, int dstsize);
char	*ft_strlcat(char *dst, char *src, int dstsize);
#endif
