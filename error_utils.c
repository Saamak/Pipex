/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:20:39 by ppitzini          #+#    #+#             */
/*   Updated: 2024/01/24 19:21:12 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	argc_error(int argcs)
{
	if (argcs != 5)
	{
		ft_putstr_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
}

void	error_argv(char **argvs)
{
	if (argvs[1][0] == '\0' || argvs[2][0] == '\0' ||
		argvs[3][0] == '\0' || argvs[4][0] == '\0')
	{
		ft_putstr_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	return ;
}

void	error_infile(t_data *data)
{
	ft_putstr_fd("Error : bad infile", 2);
	free_all(data);
	exit(EXIT_FAILURE);
}

void	error_cmd_access(t_data *data, char **commands_path)
{
	ft_printf("Error : accessing command: %s\n", strerror(errno));
	free_all(data);
	free_cmds_path(commands_path);
	exit(EXIT_FAILURE);
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	if (data->cmd_args != NULL)
	{
		while (data->cmd_args[i])
		{
			free(data->cmd_args[i++]);
		}
	}
	i = 0;
	if (data->cmd_args2 != NULL)
	{
		while (data->cmd_args2[i])
		{
			free(data->cmd_args2[i++]);
		}
	}
	free(data->cmd_args);
	free(data->cmd_args2);
	free(data->cmd1);
	free(data->cmd2);
	free(data);
}
