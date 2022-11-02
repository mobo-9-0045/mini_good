/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:27:37 by aomman            #+#    #+#             */
/*   Updated: 2022/10/19 11:27:38 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

void	ft_close(void)
{
	if (g_var.p_fd)
		close(g_var.p_fd);
	g_var.p_fd = 0;
	while (wait(NULL) != -1)
		;
}

void	execution2(t_var *var, t_list *pipeline)
{
	ft_dup(var, pipeline);
	ft_execve(var);
}

t_var	*full_exec(t_list *pipeline, t_list *head, int *pid2)
{
	t_var	*var;

	var = initialise_var(pipeline);
	if (pipe(var->fd_cmd) == -1)
	{
		ft_putstr_fd("Error in pipe\n", 2);
		g_var.ex_code = 1;
	}
	if (!head->next)
		execution(var);
	else if (head->next)
		more_command(pipeline, var, pid2);
	if (g_var.p_fd)
		close(g_var.p_fd);
	g_var.p_fd = var->fd_cmd[0];
	close(var->fd_cmd[1]);
	return (var);
}

void	ft_while_pipe(t_list *pipeline, t_list *head)
{
	t_var	*var;
	int		*pid2;

	if (g_var.fil == 1)
		return ;
	g_var.n_node = ft_lstsize(pipeline);
	pid2 = malloc (sizeof(int) * g_var.n_node);
	while (pipeline)
	{
		var = full_exec(pipeline, head, pid2);
		if (pipeline->next)
			free(var);
		pipeline = pipeline->next;
	}
	ft_wait(var, pid2);
	free (var);
	free (pid2);
}
