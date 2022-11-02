/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 00:57:41 by aomman            #+#    #+#             */
/*   Updated: 2022/08/18 02:54:24 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(t_var *var)
{
	var->pwd_path = malloc(1024);
	getcwd(var->pwd_path, 1024);
	if (!var->pwd_path)
	{
		ft_putstr_fd("path not valid\n", 2);
		g_var.ex_code = 1;
		return ;
	}
	printf("%s\n", var->pwd_path);
	free (var->pwd_path);
}
