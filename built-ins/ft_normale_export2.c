/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normale_export2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:39:48 by aomman            #+#    #+#             */
/*   Updated: 2022/09/24 15:39:49 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

void	ft_normale_export2(t_var *var)
{
	char	**tmp;

	var->i = 0;
	while (g_var.env[var->i])
		var->i++;
	tmp = malloc(sizeof(char *) * (var->i + var->j + 1));
	var->i = 0;
	while (g_var.env[var->i])
	{
		tmp[var->i] = ft_strdup(g_var.env[var->i]);
		var->i++;
	}
	tmp[var->i++] = ft_strdup(var->s_cmd[var->j]);
	tmp[var->i] = NULL;
	var->i = 0;
	while (g_var.env[var->i])
		free (g_var.env[var->i++]);
	free (g_var.env);
	g_var.env = tmp;
}
