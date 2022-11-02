/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:29:58 by aomman            #+#    #+#             */
/*   Updated: 2022/10/23 22:29:59 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

void	ft_while(t_list *pipeline, int index, int fd[2])
{
	while (g_var.check_herdoc)
	{
		if (!find_limiter((\
			(t_cmd *)pipeline->content)->limiter[index], fd))
			break ;
	}
}

void	ft_dup(t_var *var, t_list *pipeline)
{
	if (var->my_red && (g_var.fil == 0))
		ft_open_fd(var);
	if (var->in)
		(dup2(var->in, 0), close(var->in));
	else
	{
		if (g_var.p_fd)
			dup2(g_var.p_fd, 0);
	}
	if (var->out)
		(dup2(var->out, 1), close(var->out));
	if (var->fd_f)
		(dup2(var->fd_f, 1), close(var->fd_f));
	if (pipeline->next)
		dup2(var->fd_cmd[1], 1);
	close(var->fd_cmd[1]);
	close(var->fd_cmd[0]);
	if (g_var.p_fd)
		close(g_var.p_fd);
}

void	ft_execve(t_var *var)
{
	if (var->s_cmd && execve(var->cmd_path, var->s_cmd, g_var.env) == -1)
	{
		if (ft_isdir(var) == 0)
			exit (g_var.ex_code);
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(var->s_cmd[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		g_var.ex_code = 127;
		exit (g_var.ex_code);
	}
}

void	ft_wait(t_var *var, int *pid2)
{
	g_var.hld = 1;
	while (g_var.hld != -1)
	{
		g_var.hld = waitpid(-1, &var->status, 0);
		if (g_var.hld == pid2[g_var.n_node - 1])
		{
			if (WIFEXITED(var->status))
				g_var.ex_code = WEXITSTATUS(var->status);
			else if (WIFSIGNALED(var->status))
				g_var.ex_code = 128 + WTERMSIG(var->status);
		}
	}
	signals();
}

void	more_command(t_list *pipeline, t_var *var, int *pid2)
{
	if (var->my_red && (g_var.fil == 0))
		ft_open_fd(var);
	var->i = 0;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	pid2[var->i] = fork();
	if (pid2[var->i] == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		if (check_builtins(var) == 0)
		{
			ft_dup(var, pipeline);
			n_exec(var);
			exit (g_var.ex_code);
		}
		execution2(var, pipeline);
	}
	var->i++;
}
