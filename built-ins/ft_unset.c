/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:08:13 by aomman            #+#    #+#             */
/*   Updated: 2022/09/18 18:11:12 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

int	ft_error(t_var *var)
{
	int	i;

	i = 1;
	while (var->s_cmd[i])
	{
		if (!ft_isalpha_e_u(var->s_cmd[i][0]))
		{
			ft_putstr_fd("minishell : `", 2);
			ft_putstr_fd(var->s_cmd[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			g_var.ex_code = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_replace(t_var *var)
{
	int		index_env;
	int		i;

	index_env = ft_char(g_var.env[var->i], '=');
	var->key_env = ft_substr(g_var.env[var->i], 0, index_env);
	if (ft_strcmp(var->s_cmd[var->j], var->key_env) == 0
		|| ft_strcmp(var->s_cmd[var->j], g_var.env[var->i]) == 0)
	{
		i = var->i;
		free (g_var.env[var->i]);
		while (g_var.env[i])
		{
			g_var.env[i] = g_var.env[i + 1];
			i++;
		}
	}
	free (var->key_env);
}

void	ft_remove(t_var *var)
{
	var->j = 1;
	while (var->s_cmd[var->j])
	{
		var->i = 0;
		while (g_var.env[var->i])
		{
			ft_replace(var);
			var->i++;
		}
		var->j++;
	}
}

void	ft_unset(t_var *var)
{
	if (!var->s_cmd[1])
		return ;
	if (ft_error(var) == 1)
		return ;
	ft_remove(var);
}
