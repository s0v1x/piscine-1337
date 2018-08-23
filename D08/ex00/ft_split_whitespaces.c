/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabiad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 22:11:25 by slabiad           #+#    #+#             */
/*   Updated: 2018/08/06 22:11:34 by slabiad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\0')
		return (1);
	else
		return (0);
}

int			sauv_char(char *str)
{
	int		i;
	int		l;

	if (*str == '\0')
		return (0);
	i = 0;
	l = 0;
	while (*str)
	{
		if (space(*str))
		{
			str++;
			l = 0;
		}
		else
		{
			if (l == 0)
				i++;
			l = 1;
			str++;
		}
	}
	return (i);
}

char		*nb_char(char *str, int *n)
{
	char	*word;
	int		i;
	int		start;
	int		end;

	i = *n;
	while (str[i] <= ' ')
		i++;
	start = i;
	while (str[i] > ' ')
		i++;
	end = i;
	*n = i;
	word = (char*)malloc(sizeof(char) * end - start);
	i = 0;
	while (start < end)
	{
		word[i] = str[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char		**ft_split_whitespaces(char *str)
{
	char	**res;
	int		n;
	int		i;

	res = (char**)malloc(sizeof(char*) * sauv_char(str) + 1);
	n = 0;
	i = 0;
	while (n < sauv_char(str))
	{
		res[n] = nb_char(str, &i);
		n++;
	}
	res[n] = 0;
	return (res);
}
