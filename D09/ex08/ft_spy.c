/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabiad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 08:55:03 by slabiad           #+#    #+#             */
/*   Updated: 2018/07/27 16:20:48 by slabiad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char		*no_space(int c, char *str)
{
	int		i;
	int		j;
	char	f;
	int		nb;

	i = 0;
	j = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && i < c - 1)
		{
			j = i;
			while (j < c)
			{
				f = str[j];
				str[j] = str[j + 1];
				str[j + 1] = f;
				j++;
			}
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

char		*to_low(char *str)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[count] != '\0')
		count++;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		else
			str[i] = str[i];
		i++;
	}
	return (str);
}

int			cmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	return (1);
}

int			in_list(char *str)
{
	if (cmp("president", str) || cmp("bauer", str) || cmp("attack", str))
		return (1);
	return (0);
}

int			main(int argc, char *argv[])
{
	int		i;
	int		c;

	i = 1;
	c = 0;
	while (i < argc)
	{
		c += in_list(to_low(no_space(argc, argv[i])));
		i++;
	}
	if (c > 0)
	{
		write(1, "Alert!!!\n", 9);
	}
	return (0);
}
