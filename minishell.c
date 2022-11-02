/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:00:39 by aomman            #+#    #+#             */
/*   Updated: 2022/10/31 20:00:42 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	g_alloc(char **env)
{
	g_var.i = 0;
	while (env[g_var.i])
		g_var.i++;
	g_var.env = (char **)malloc(sizeof(char *) * (g_var.i + 1));
	g_var.i = 0;
	while (env[g_var.i])
	{
		g_var.env[g_var.i] = ft_strdup(env[g_var.i]);
		g_var.i++;
	}
	g_var.env[g_var.i] = 0;
	g_var.check_herdoc = 0;
	g_var.ex_code = 0;
}

int	main(int ac, char **av, char **env)
{
	g_alloc(env);
	(void)av;
	if (ac != 1 || !env)
		return (0);
	parcing_function();
}
