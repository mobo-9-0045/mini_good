/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:06:43 by aomman            #+#    #+#             */
/*   Updated: 2022/10/31 20:06:46 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	error_msg(char *msg)
{
	char	*str;

	str = ft_strjoin("Minishell: syntax error near unexpected token ", msg);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	free(str);
	g_var.ex_code = 258;
}

void	display_msg(char *str)
{
	write (2, str, ft_strlen(str));
}

int	trow_err(int d_quote, int s_quote)
{
	if (d_quote % 2 != 0 || s_quote % 2 != 0)
	{
		write(2, "Minishell: syntax error near unexpected token\n", 47);
		g_var.ex_code = 258;
		return (0);
	}
	return (1);
}

void	raise_err(char err)
{
	write (2, "Minishell: syntax error near unexpected token ", 46);
	write (2, &err, 1);
	write (2, "\n", 1);
	g_var.ex_code = 258;
}
