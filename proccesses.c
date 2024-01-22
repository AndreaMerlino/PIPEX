/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proccesses.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:34:49 by andreamerli       #+#    #+#             */
/*   Updated: 2024/01/18 11:34:52 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_handler1(char **argv, char **envp, int fdpipe[], int fdopen)
{
	char	**split;
	char	*file1;

	close(fdpipe[0]);
	dup2(fdopen, 0);
	close(fdopen);
	dup2(fdpipe[1], 1);
	close(fdpipe[1]);
	split = ft_split(argv[2], ' ');
	file1 = find_command_path(split[0], envp);
	execve(file1, split, envp);
}

void	pipe_handler2(char **argv, char **envp, int fdpipe[], int fdopen)
{
	char	**split;
	char	*file1;

	close(fdpipe[1]);
	dup2(fdpipe[0], 0);
	dup2(fdopen, 1);
	close(fdopen);
	close(fdpipe[0]);
	split = ft_split(argv[3], ' ');
	file1 = find_command_path(split[0], envp);
	execve(file1, split, envp);
}
