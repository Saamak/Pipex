/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:53:49 by ppitzini          #+#    #+#             */
/*   Updated: 2024/01/25 16:53:04 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipe_creation(char *infile, char *outfile, t_data *data, char **envp)
{
	int	pfd[2];
	int	fdin;
	int	fdout;
	int	pid;

	fdin = open(infile, O_RDONLY);
	if (fdin < 0)
		error_infile(data);
	dup2(fdin, 0);
	close(fdin);
	fdout = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(fdout, 1);
	close(fdout);
	if (pipe(pfd) == -1)
	{
		ft_printf("pipe failed");
		return (1);
	}
	pid = fork();
	if (pid < 0)
		pipe_error(data);
	pipe_creation_two(pid, pfd, data, envp);
	return (0);
}

int	pipe_creation_two(int pid, int pfd[], t_data *data, char **envp)
{
	if (pid == 0)
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
		close(pfd[0]);
		if (execve(data->cmd2, data->cmd_args2, envp) == -1)
		{
			ft_printf("wc failed");
			return (1);
		}
	}
	else
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
		close(pfd[1]);
		if (execve(data->cmd1, data->cmd_args, envp) == -1)
		{
			ft_printf("ls failed");
			return (1);
		}
	}
	return (0);
}

void	pipe_error(t_data *data)
{
	ft_printf("fork failed");
	free_all(data);
	exit(EXIT_FAILURE);
}
