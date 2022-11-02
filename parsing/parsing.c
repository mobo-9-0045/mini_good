/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:06:20 by hhamdy            #+#    #+#             */
/*   Updated: 2022/09/14 18:46:42 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	norm(void)
{
	signals();
	g_var.p_fd = 0;
	g_var.flag = 1;
}

void	parcing_function(void)
{
	char	*line;
	t_list	*pipeline;
	t_list	*tmp;

	while (1)
	{
		norm();
		line = readline("Minishell$ ");
		if (!line)
		{
			printf("exit\n");
			exit (g_var.ex_code);
		}
		if (ft_strlen(line))
			add_history(line);
		pipeline = error_handling(line, g_var.env);
		while (pipeline)
		{
			tmp = pipeline;
			pipeline = pipeline->next;
			free_struct(tmp);
			free(tmp);
		}
		free(line);
	}
}
