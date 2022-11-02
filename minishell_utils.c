/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:31:33 by aomman            #+#    #+#             */
/*   Updated: 2022/08/16 18:38:38 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	diff;
	int	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	diff = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (s1[i] != s2[i])
	{
		diff = s1[i] - s2[i];
		return (diff);
	}
	else
		return (0);
}
