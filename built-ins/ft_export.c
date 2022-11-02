/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:09:35 by aomman            #+#    #+#             */
/*   Updated: 2022/09/11 17:26:58 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

void	ft_sortenv(t_var *var)
{
	int		i;
	char	*tmp;

	var->i = 0;
	var->s_env = g_var.env;
	while (var->s_env[var->i])
		var->i++;
	i = var->i;
	var->i = 0;
	while (var->i < i)
	{
		var->j = 0;
		while (var->j < i)
		{
			if (ft_strcmp(var->s_env[var->j], var->s_env[var->j + 1]) > 0)
			{
				tmp = var->s_env[var->j];
				var->s_env[var->j] = var->s_env[var->j + 1];
				var->s_env[var->j + 1] = tmp;
			}
			var->j++;
		}
		var->i++;
	}
}

void	ft_print_sorted_env(t_var *var)
{
	var->i = 0;
	while (var->s_env[var->i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(var->s_env[var->i], 1);
		write (1, "\n", 1);
		var->i++;
	}
}

void	ft_export(t_var *var)
{
	if (!var->s_cmd[1])
	{
		ft_sortenv(var);
		ft_print_sorted_env(var);
	}
	else
	{
		if (check_digit (var) == 0)
			return ;
		normale_export(var);
	}
}
