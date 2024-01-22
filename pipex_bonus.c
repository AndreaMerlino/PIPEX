/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:29:12 by andreamerli       #+#    #+#             */
/*   Updated: 2024/01/22 12:47:36 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	handle_error(char *error_message, char *str)
{
	write(2, error_message, ft_pstrlen(error_message));
	write(2, str, ft_pstrlen(str));
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
	if (directories[0] == NULL)
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
		handle_error ("Path not found on this machine", NULL);
	path = ft_calloc(500, 1);
	pathto (path, directories, command);
	return (path);
}

void	devo_stare_nelle_25_righe( t_my_struct *my_struct)
{
	unlink(".helper_tmp");
	my_struct->a++;
	my_struct->c++;
	waitpid(my_struct->id3, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	struct s_pipex	my_struct;

	my_struct.c = 3;
	my_struct.b = 0;
	my_struct.fdpipe = create_pipes(argc - 3);
	file_opener(argv, &my_struct);
	parent_child_pipe_handler(argc, argv, envp, &my_struct);
	while (my_struct.a < (argc - my_struct.d))
	{
		my_struct.id3 = fork();
		if (my_struct.id3 != 0)
		{
			close (my_struct.fdpipe[my_struct.b][0]);
			close (my_struct.fdpipe[my_struct.b][1]);
			my_struct.b++;
		}
		if (my_struct.id3 == 0)
			child_pipe_handler(argc, argv, envp, my_struct);
		devo_stare_nelle_25_righe(&my_struct);
	}
	file_opener2(argc, argv, &my_struct);
	pipe_handler(argc, argv, envp, &my_struct);
	parent_handler(argc, &my_struct);
	return (0);
}
