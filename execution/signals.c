/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:00:36 by aomman            #+#    #+#             */
/*   Updated: 2022/10/19 12:00:37 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

void	handle(int sig)
{
	if (sig == SIGINT)
	{
		write (1, "\n", 1);
		g_var.ex_code = 1;
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	signals(void)
{
	if (signal(SIGINT, handle) == SIG_ERR)
		printf("Error is signal\n");
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		printf("Error is signal\n");
}
