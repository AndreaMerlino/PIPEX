/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccesses_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:35:39 by andreamerli       #+#    #+#             */
/*   Updated: 2024/01/21 22:45:42 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc( char **argv)
{
	char	*str;
	int		fd;

	fd = open(".helper_tmp", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		perror("some problem occured with here_doc");
	while (1)
	{
		write(1, "heredoc> ", 9);
		str = get_next_line(0);
		if (str == NULL || ft_strncmp(str, argv[2], ft_pstrlen(argv[2])) == 0)
			break ;
		write(fd, str, ft_pstrlen(str));
		free(str);
	}
	free(str);
	close(fd);
}

void	parent_child_pipe_handler(int argc, char **argv, char **envp,
		t_my_struct *my_struct)
{
	my_struct->id1 = fork();
	if (my_struct->id1 == 0)
	{
		while (0 < (argc - (4 + my_struct->b)))
		{
			close (my_struct->fdpipe[(argc - (4 + my_struct->b))][0]);
			close (my_struct->fdpipe[(argc - (4 + my_struct->b))][1]);
			my_struct->b++;
		}
		close(my_struct->fdpipe[0][0]);
		dup2(my_struct->fdopen, 0);
		close(my_struct->fdopen);
		dup2(my_struct->fdpipe[0][1], 1);
		close(my_struct->fdpipe[0][1]);
		my_struct->split = ft_split(argv[my_struct->c], ' ');
		my_struct->file1 = find_command_path(my_struct->split[0], envp);
		if (execve(my_struct->file1, my_struct->split, envp) < 0)
			handle_error("execve failed wrong command: ", argv[my_struct->c]);
	}
	waitpid(my_struct->id1, NULL, 0);
	close(my_struct->fdopen);
	my_struct->a = 3;
	my_struct->c ++;
}

void	child_pipe_handler(int argc, char **argv, char **envp,
		t_my_struct my_struct)
{
	if (my_struct.a == 3)
	{
		dup2(my_struct.fdpipe[0][0], 0);
		dup2(my_struct.fdpipe[my_struct.a - 2][1], 1);
	}
	else
	{
		dup2(my_struct.fdpipe[my_struct.a - 3][0], 0);
		dup2(my_struct.fdpipe[my_struct.a - 2][1], 1);
	}
	my_struct.b = 0;
	while (0 <= (argc - (4 + my_struct.b)))
	{
		close (my_struct.fdpipe[(argc - (4 + my_struct.b))][0]);
		close (my_struct.fdpipe[(argc - (4 + my_struct.b))][1]);
		my_struct.b++;
	}
	my_struct.split = ft_split(argv[my_struct.c], ' ');
	my_struct.file1 = find_command_path(my_struct.split[0], envp);
	if (execve(my_struct.file1, my_struct.split, envp) < 0)
	{
		handle_error("execve failed wrong command: ", argv[my_struct.c]);
		exit(1);
	}
}

void	pipe_handler(int argc, char **argv, char **envp, t_my_struct *my_struct)
{
	my_struct->id2 = fork();
	if (my_struct->id2 != 0)
	{
		close(my_struct->fdpipe[my_struct->a - 3][0]);
		close(my_struct->fdpipe[my_struct->a - 3][1]);
	}
	else
	{
		dup2(my_struct->fdpipe[my_struct->a - 3][0], 0);
		dup2(my_struct->fdopen2, 1);
		close(my_struct->fdopen2);
		my_struct->b = 0;
		while (0 <= (argc - (4 + my_struct->b)))
		{
			close (my_struct->fdpipe[(argc - (4 + my_struct->b))][0]);
			close (my_struct->fdpipe[(argc - (4 + my_struct->b))][1]);
			my_struct->b++;
		}
		my_struct->split = ft_split(argv[argc - 2], ' ');
		my_struct->file1 = find_command_path(my_struct->split[0], envp);
		if (execve(my_struct->file1, my_struct->split, envp) < 0)
			handle_error("execve failed wrong command: ", argv[argc - 2]);
	}
}

void	parent_handler(int argc, t_my_struct *my_struct)
{
	my_struct->b = 0;
	while (0 <= (argc - (4 + my_struct->b)))
	{
		close (my_struct->fdpipe[(argc - (4 + my_struct->b))][0]);
		close (my_struct->fdpipe[(argc - (4 + my_struct->b))][1]);
		my_struct->b++;
	}
	waitpid(my_struct->id2, NULL, 0);
	close(my_struct->fdopen2);
}
