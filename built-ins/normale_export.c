/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normale_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:59:28 by aomman            #+#    #+#             */
/*   Updated: 2022/09/23 15:59:29 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

int	check_digit(t_var *var)
{
	var->i = 1;
	while (var->s_cmd[var->i])
	{
		if (ft_isalpha_e_u(var->s_cmd[var->i][0]) == 0)
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(var->s_cmd[var->i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			g_var.ex_code = 1;
			return (0);
		}
		var->i++;
	}
	return (1);
}

int	check_equal(t_var *var)
{
	var->j = 1;
	while (var->s_cmd[var->j])
	{
		if (ft_char(var->s_cmd[var->j], '=') == 0)
			return (0);
		var->j++;
	}
	return (1);
}

int	ft_getindex(t_var *var)
{
	int	i;
	int	i_env;

	i = ft_char(var->s_cmd[var->j], '=');
	if (i == 0)
		var->key_cmd = ft_strdup(var->s_cmd[var->j]);
	else
		var->key_cmd = ft_substr(var->s_cmd[var->j], 0, i);
	var->i = 0;
	while (g_var.env[var->i])
	{
		i_env = ft_char(g_var.env[var->i], '=');
		if (i_env == 0)
			var->key_env = ft_strdup(g_var.env[var->i]);
		else
			var->key_env = ft_substr(g_var.env[var->i], 0, i_env);
		if (ft_strcmp(var->key_env, var->key_cmd) == 0)
		{
			free (var->key_cmd);
			return (var->i);
		}
		free (var->key_env);
		var->i++;
	}
	return (-1);
}

void	ft_overload(t_var *var, int index)
{
	free (g_var.env[index]);
	var->key_env = NULL;
	g_var.env[index] = ft_strdup(var->s_cmd[var->j]);
}

void	normale_export(t_var *var)
{
	int		index;

	var->j = 1;
	while (var->s_cmd[var->j])
	{
		index = ft_getindex(var);
		if (index != -1)
			ft_overload(var, index);
		else
			ft_normale_export2(var);
		var->j++;
	}
}
