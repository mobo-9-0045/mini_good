/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:01:16 by aomman            #+#    #+#             */
/*   Updated: 2022/08/26 14:01:18 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

void	space_handler(char **s_cmd, int i, int n)
{
	if (i > 1)
		n = 1;
	while (s_cmd[i])
	{
		ft_putstr_fd(s_cmd[i], 1);
		if (s_cmd[i])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (n == 0)
		ft_putstr_fd("\n", 1);
}

void	ft_echo(t_var *var)
{
	int	i;
	int	j;
	int	n;

	if (!var->s_cmd[1])
	{
		ft_putstr_fd("\n", 1);
		return ;
	}
	i = 1;
	while (var->s_cmd[i] && var->s_cmd[i][0] == '-' && var->s_cmd[i][1] == 'n')
	{
		j = 1;
		while (var->s_cmd[i][j] == 'n')
			j++;
		if (var->s_cmd[i][j] != '\0')
			break ;
		i++;
	}
	n = 0;
	space_handler(var->s_cmd, i, n);
}
