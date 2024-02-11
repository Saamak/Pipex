/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:59:13 by ppitzini          #+#    #+#             */
/*   Updated: 2024/02/11 23:31:58 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_cmds_path(char **commands_path)
{
	int	i;

	i = 0;
	if (commands_path != NULL)
	{
		while (commands_path[i])
			free(commands_path[i++]);
	}
	free(commands_path);
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	char	**commands_path;
	t_data	*data;

	argc_error(argc);
	error_argv(argv);
	data = init_data();
	commands_path = ft_split(cmd_find_path(envp), ':');
	data->cmd1 = cmd_get(data, argv[2], commands_path);
	data->cmd2 = cmd_get(data, argv[3], commands_path);
	if (data->cmd1_wrong == 1 && data->cmd2_wrong == 1)
		error_cmd_access(data, commands_path);
	free_cmds_path(commands_path);
	pipe_creation(argv[1], argv[4], data, envp);
	free_all(data);
	return (0);
}
