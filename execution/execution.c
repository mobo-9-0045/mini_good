/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:59:50 by aomman            #+#    #+#             */
/*   Updated: 2022/10/09 20:57:29 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

int	ft_isdir(t_var *var)
{
	if (var->s_cmd[0][0] == '/')
	{
		if (access(var->s_cmd[0], F_OK) == 0)
		{
			ft_putstr_fd("minishell:", 2);
			ft_putstr_fd(var->s_cmd[0], 2);
			ft_putstr_fd(": is directory\n", 2);
			g_var.ex_code = 126;
			return (0);
		}
		else
		{
			ft_putstr_fd("minishell:", 2);
			ft_putstr_fd(var->s_cmd[0], 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			g_var.ex_code = 127;
			return (0);
		}
	}
	return (1);
}

t_var	*initialise_var(t_list *pars)
{
	t_var	*var;

	var = malloc(sizeof (t_var));
	var->i = 0;
	var->s_cmd = ((t_cmd *)pars->content)->arg;
	var->my_red = ((t_cmd *)pars->content)->red;
	var->type = ((t_cmd *)pars->content)->type;
	var->in = ((t_cmd *)pars->content)->in;
	var->out = ((t_cmd *)pars->content)->out;
	var->cmd_path = ((t_cmd *)pars->content)->cmd_path;
	g_var.n_node = ft_lstsize(pars);
	g_var.hld = 1;
	return (var);
}

void	child(t_var *var)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	if (var->in)
	{
		if (dup2(var->in, 0) == -1)
			exit (1);
		close(var->in);
	}
	if (var->out)
	{
		if (dup2(var->out, 1) == -1)
			exit (1);
		close(var->out);
	}
	if (var->fd_f)
		(dup2(var->fd_f, 1), close(var->fd_f));
	if (var->s_cmd && execve(var->cmd_path, var->s_cmd, g_var.env) == -1)
	{
		if (ft_isdir(var) == 0)
			exit (g_var.ex_code);
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(var->s_cmd[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit (127);
	}
}

void	exec(t_var *var)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	var->pid = fork();
	if (var->pid == 0)
		child(var);
	else
	{
		g_var.hld = waitpid(-1, &var->status, 0);
		if (WIFEXITED(var->status))
			g_var.ex_code = WEXITSTATUS(var->status);
		else if (WIFSIGNALED(var->status))
			g_var.ex_code = 128 + WTERMSIG(var->status);
		signals();
	}
}

void	execution(t_var *var)
{
	if (var->my_red && (g_var.fil == 0))
		ft_open_fd(var);
	if (!var->s_cmd)
	{
		close(var->fd_cmd[1]);
		return ;
	}
	if (check_builtins(var) == 0)
		n_exec(var);
	else if (check_builtins(var) == 1)
		exec(var);
	return ;
}
