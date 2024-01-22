/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_opener_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:49:04 by andreamerli       #+#    #+#             */
/*   Updated: 2024/01/22 12:47:25 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	**create_pipes(int num_pipes)
{
	int	i;
	int	**pipes;

	i = 0;
	pipes = ft_calloc(num_pipes, sizeof(int *));
	while (i < num_pipes)
	{
		pipes[i] = ft_calloc(2, sizeof(int));
		if (pipe(pipes[i]) == -1)
		{
			perror("Failed to create a pipe");
			while (i > 0)
				free(pipes[--i]);
			return (NULL);
		}
		i++;
	}
	return (pipes);
}

void	file_opener(char **argv, t_my_struct *my_struct)
{
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		my_struct->d = 3;
		here_doc(argv);
		my_struct->fdopen = open(".helper_tmp", O_RDONLY);
	}
	else
	{
		my_struct->d = 2;
		my_struct->c = 2;
		my_struct->fdopen = open(argv[1], O_RDONLY);
		if (my_struct->fdopen < 0)
			handle_error("no such file or directory:", argv[1]);
	}
}

void	file_opener2(int argc, char **argv, t_my_struct *my_struct)
{
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		my_struct->fdopen2 = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND,
				0644);
	else
		my_struct->fdopen2 = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC,
				0644);
}
