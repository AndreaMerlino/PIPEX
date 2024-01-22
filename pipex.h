/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:28:30 by andreamerli       #+#    #+#             */
/*   Updated: 2024/01/19 18:51:40 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stddef.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./ft_printf/ft_printf.h"

typedef struct s_pipex
{
	int	fdopen;
	int	fdpipe[2];
	int	id1;
	int	id2;
}	t_my_struct;

char	**ft_split(char const *s, char c);
char	*find_command_path(char *command, char **envp);
void	*ft_calloc(size_t count, size_t size);
void	pipe_handler1(char **argv, char **envp, int fdpipe[], int fdopen);
void	pipe_handler2(char **argv, char **envp, int fdpipe[], int fdopen);
char	*ft_strlcpy(char *dst, char *src, int dstsize);
char	*ft_strlcat(char *dst, char *src, int dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		handle_error(char *errorMessage);
int		ft_printf(const char *p, ...);
int		ft_pstrlen(const char *s);
#endif
