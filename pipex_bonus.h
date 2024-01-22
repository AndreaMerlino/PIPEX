/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:59:46 by andreamerli       #+#    #+#             */
/*   Updated: 2024/01/22 12:42:27 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <stddef.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_pipex
{
	char	**split;
	char	*file1;
	char	*readbuffer;
	int		fdopen;
	int		fdopen2;
	int		**fdpipe;
	int		id1;
	int		id2;
	int		id3;
	int		a;
	int		b;
	int		c;
	int		d;
}	t_my_struct;

char	**ft_split(char const *s, char c);
char	*find_command_path(char *command, char **envp);
void	*ft_calloc(size_t count, size_t size);
void	parent_child_pipe_handler(int argc, char **argv, char **envp,
			t_my_struct *my_struct);
void	child_pipe_handler(int argc, char **argv, char **envp,
			t_my_struct my_struct);
void	pipe_handler(int argc, char **argv, char **envp,
			t_my_struct *my_struct);
void	parent_handler(int argc, t_my_struct *my_struct);
void	here_doc( char **argv);
void	file_opener(char **argv, t_my_struct *my_struct);
void	file_opener2(int argc, char **argv, t_my_struct *my_struct);
char	*ft_strlcpy(char *dst, char *src, int dstsize);
char	*ft_strlcat(char *dst, char *src, int dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		handle_error(char *errorMessage, char *str);
int		ft_printf(const char *p, ...);
int		ft_pstrlen(const char *s);
int		**create_pipes(int num_pipes);
#endif
