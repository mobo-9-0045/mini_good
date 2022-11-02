/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:45:17 by aomman            #+#    #+#             */
/*   Updated: 2022/10/09 21:08:19 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../minishell.h"

int	ft_infile(t_var *var)
{
	var->in = open(var->my_red[var->i], O_RDONLY, 0444);
	if (var->in < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(var->my_red[var->i], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		g_var.ex_code = 1;
		return (1);
	}
	return (0);
}

int	ft_outfile(t_var *var)
{
	var->out = open(var->my_red[var->i], O_CREAT | O_RDWR, 0666);
	if (var->out < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(var->my_red[var->i], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		g_var.ex_code = 1;
	}
	return (0);
}

int	ft_append(t_var *var)
{
	var->fd_f = open(var->my_red[var->i], O_CREAT | O_APPEND | O_RDWR, 0644);
	if (var->fd_f < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(var->my_red[var->i], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		g_var.ex_code = 1;
	}
	return (0);
}

void	ft_open_fd(t_var *var)
{
	int	i;

	i = 0;
	while (var->my_red[var->i])
	{
		if (var->type[var->i] == 1)
		{
			if (ft_infile(var) == 1)
				break ;
		}
		else if (var->type[var->i] == 2)
		{
			if (ft_outfile(var) == 1)
				break ;
		}
		else if (var->type[var->i] == 3)
		{
			if (ft_append(var) == 1)
				break ;
		}
		else if (var->type[var->i] == 4)
			break ;
		var->i++;
	}
	return ;
}
