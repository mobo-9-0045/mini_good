/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_herdoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:05:53 by aomman            #+#    #+#             */
/*   Updated: 2022/10/31 20:05:55 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fill_in(int index, int n_limiter, int *fd, t_cmd *node)
{
	if (index == n_limiter - 1)
	{
		node->in = dup(fd[0]);
		close(fd[1]);
		close(fd[0]);
	}
	else
		(close(fd[1]), close(fd[0]));
}

void	ft_pipe(int *fd)
{
	if (pipe(fd) == -1)
	{
		display_msg("Pipe failture.\n");
		g_var.ex_code = 1;
	}
}

int	find_limiter(char *str, int fd[2])
{
	char	*buff;

	buff = readline("> ");
	if (!buff)
		return (0);
	if (ft_strcmp(buff, str))
	{
		write (fd[1], buff, ft_strlen(buff));
		write(fd[1], "\n", 1);
	}
	else
	{
		free(buff);
		return (0);
	}
	free(buff);
	return (1);
}

void	signale(int sig)
{
	if (sig == SIGINT)
	{
		write (1, "\n", 1);
		g_var.check_herdoc = 0;
		g_var.fil = 1;
		close(0);
	}
}

void	open_herdoc(t_list *pipeline)
{
	int		index;
	int		fd[2];
	int		n_p;
	int		tmp;

	g_var.check_herdoc = 1;
	while (pipeline)
	{
		index = 0;
		tmp = dup(0);
		n_p = count_d_pointer(((t_cmd *)pipeline->content)->limiter);
		(signal(SIGINT, SIG_IGN), signal(SIGINT, signale));
		while (index < n_p)
		{
			ft_pipe(fd);
			ft_while(pipeline, index, fd);
			fill_in(index, n_p, fd, ((t_cmd *)pipeline->content));
			index++;
		}
		(dup2(tmp, 0), pipeline = pipeline->next);
	}
}
