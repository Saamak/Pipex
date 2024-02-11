/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_verifs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:25:03 by ppitzini          #+#    #+#             */
/*   Updated: 2024/02/11 22:20:27 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*cmd_get(t_data *data, char *cmd, char **commands_path)
{
	char	*tested_path;
	char	*cmd_slashed;

	if (data->bowl == 0)
	{
		data->cmd_args = ft_split(cmd, ' ');
		cmd_slashed = ft_strjoin("/", data->cmd_args[0]);
		tested_path = test_cmd(data, cmd_slashed, commands_path);
		data->bowl = 1;
	}
	else if (data->bowl == 1)
	{
		data->cmd_args2 = ft_split(cmd, ' ');
		cmd_slashed = ft_strjoin("/", data->cmd_args2[0]);
		tested_path = test_cmd(data, cmd_slashed, commands_path);
	}
	return (tested_path);
}

char	*test_cmd(t_data *data, char *cmd_slashed, char **commands_path)
{
	char	*test;
	int		i;

	i = 0;
	while (commands_path[i])
	{
		test = ft_strjoin_two(commands_path[i], cmd_slashed);
		if (access(test, X_OK) == 0)
			return (test);
		else
			free(test);
		i++;
	}
	free(cmd_slashed);
	if (data->bowl == 0)
		data->cmd1_wrong = 1;
	else
		data->cmd2_wrong = 1;
	return (NULL);
}

char	*ft_strjoin_two(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		len_all;
	int		j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len_all = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	result = malloc(sizeof(char) * len_all + 1);
	if (result == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}
