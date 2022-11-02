/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:43:36 by aomman            #+#    #+#             */
/*   Updated: 2022/09/07 18:46:12 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cd(t_var *var)
{
	char	*path;
	int		i;

	i = 1;
	if (!var->s_cmd[i])
		path = ft_strdup(getenv("HOME"));
	else
		path = ft_strdup(var->s_cmd[i]);
	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(var->s_cmd[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		g_var.ex_code = 1;
		return ;
	}
	free (path);
	i = 0;
}
