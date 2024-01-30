/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:40:00 by ppitzini          #+#    #+#             */
/*   Updated: 2024/01/24 19:24:45 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check(char *s, int start, int len)
{
	if (start > ft_strlen(s))
		return (len = 0);
	if (len > ft_strlen(s) - start)
		return (len = ft_strlen(s) - start);
	return (len);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*ptr;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	size = check(s, start, len);
	ptr = malloc(size + 1);
	if (!ptr)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			ptr[j] = s[i];
			j++;
		}
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	*cmd_find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 1)
			return (envp[i]);
		i++;
	}
	return (NULL);
}

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->cmd1 = NULL;
	data->cmd2 = NULL;
	data->cmd_args = NULL;
	data->cmd_args2 = NULL;
	data->bowl = 0;
	return (data);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || !fd)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
