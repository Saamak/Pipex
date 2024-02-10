/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:53:46 by ppitzini          #+#    #+#             */
/*   Updated: 2024/01/25 16:53:14 by ppitzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define RED "\x1b[32m"
# define RESET "\x1b[0m"

# include <unistd.h>
# include <memory.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "ft_printf.h"

typedef struct s_data
{
	char	**cmd_args;
	char	**cmd_args2;
	char	*cmd1;
	char	*cmd2;
	int		bowl;
}	t_data;

char	*cmd_get(t_data *data, char *cmd, char **commands_path);
char	*cmd_find_path(char **envp);
char	*test_cmd(t_data *data, char *cmd_slashed, char **commands_path);
int		pipe_creation(char *infile, char *outfile, t_data *data, char **envp);
int		pipe_creation_two(int pid, int pfd[], t_data *data, char **envp);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(char *s);
char	**ft_split(char *s, char c);
int		count_words(char const *s, char c);
char	*ft_substr(char *s, int start, int len);
int		check(char *s, int start, int len);
void	ft_putstr_fd(char *s, int fd);
int		find_space(char *cmd);
t_data	*init_data(void);
char	*ft_strjoin_two(char const *s1, char const *s2);

void	error_argv(char **argvs);
void	argc_error(int argcs);
void	error_infile(t_data *data);
void	error_cmd_access(t_data *data, char **commands_path);
void	free_all(t_data *data);
void	free_cmds_path(char **commands_path);
void	pipe_error(t_data *data);

#endif
