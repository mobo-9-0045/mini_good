/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:49:27 by aomman            #+#    #+#             */
/*   Updated: 2022/09/11 18:55:42 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

int	ft_isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	return (0);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (fd, &str[i], 1);
		i++;
	}
}

char	*ft_strrchr(const char *str, int c)
{
	char	*s;
	int		i;

	s = (char *)str;
	i = 0;
	while (str[i] != '\0')
	{
		i = i + 1;
	}
	while (i >= 0)
	{
		if (s[i] == (char) c)
		{
			return (s + i);
		}
		i--;
	}
	return (0);
}

int	ft_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		string = malloc(sizeof(char));
	else if (len > ft_strlen(s))
		string = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		string = malloc(sizeof (char) * (len + 1));
	if (!string)
		return (NULL);
	while (s[i] && i < len && i + start < ft_strlen(s))
	{
		string[i] = s[start + i];
		i++;
	}
	string[i] = '\0';
	return (string);
}
