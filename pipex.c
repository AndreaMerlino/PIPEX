/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:27:31 by andreamerli       #+#    #+#             */
/*   Updated: 2024/01/19 12:15:51 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_error(char *error_message)
{
	write(1, error_message, ft_pstrlen(error_message));
	exit(EXIT_FAILURE);
}

void	pathto(char *path, char **directories, char *command)
{
	int	i;

	i = 0;
	while (directories[i] != NULL)
	{
		ft_strlcpy(path, directories[i], ft_pstrlen(directories[i]) + 1);
		ft_strlcat(path, "/", 2);
		ft_strlcat(path, command, ft_pstrlen(command) + 1);
		i++;
		if (access(path, X_OK) == 0)
			break ;
	}
	if (directories[i] == NULL)
	{
		perror("Wrong command");
		free (path);
		free (directories);
		exit(EXIT_FAILURE);
	}
}

char	*find_command_path(char *command, char **envp)
{
	char	*path;
	int		i;
	char	**directories;
	char	*path_env;

	i = 0;
	path = NULL;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_env = envp[i] + 5;
			directories = ft_split(path_env, ':');
			if (directories == NULL)
				break ;
		}
		i++;
	}
	if (envp[0] == NULL)
		handle_error ("Path not found on this machine");
	path = ft_calloc(500, 1);
	pathto (path, directories, command);
	return (path);
}

int	main(int argc, char **argv, char **envp)
{
	struct s_pipex	my_struct;

	if (argc != 5)
		handle_error ("Number of arguments must be 5");
	my_struct.fdopen = open(argv[1], O_RDONLY);
	if (my_struct.fdopen == -1)
		return (ft_printf("no such file or directory: %s", argv[1]));
	if (pipe(my_struct.fdpipe) == -1)
		handle_error ("Problem in creating the pipe");
	my_struct.id1 = fork();
	if (my_struct.id1 == 0)
		pipe_handler1(argv, envp, my_struct.fdpipe, my_struct.fdopen);
	close(my_struct.fdopen);
	my_struct.fdopen = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	waitpid(my_struct.id1, NULL, 0);
	my_struct.id2 = fork();
	if (my_struct.id2 == 0)
		pipe_handler2(argv, envp, my_struct.fdpipe, my_struct.fdopen);
	close(my_struct.fdpipe[0]);
	close(my_struct.fdpipe[1]);
	waitpid(my_struct.id2, NULL, 0);
	close(my_struct.fdopen);
	return (0);
}
