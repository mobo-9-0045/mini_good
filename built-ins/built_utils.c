/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:00:15 by aomman            #+#    #+#             */
/*   Updated: 2022/09/24 18:00:16 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

// static int	check(int sin)
// {
// 	if (sin == 1)
// 		return (255);
// 	return (0);
// }

// int	ft_atoi(const char *str)
// {
// 	size_t				k;
// 	size_t				i;
// 	int					sin;
// 	unsigned long long	n;

// 	i = 0;
// 	n = 0;
// 	sin = 1;
// 	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
// 		i++;
// 	if (str[i] == '-')
// 	{
// 		sin = -1;
// 		i++;
// 	}
// 	else if (str[i] == '+')
// 		i++;
// 	k = i;
// 	while (str[i] >= '0' && str[i] <= '9')
// 		n = n * 10 + (str[i++] - 48);
// 	k = i - k;
// 	if (k > 19 || n >= 9223372036854775807)
// 		return (check(sin));
// 	n = n * sin;
// 	return ((int)n);
// }
