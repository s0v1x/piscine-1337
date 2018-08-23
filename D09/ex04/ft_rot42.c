/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabiad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 22:06:18 by slabiad           #+#    #+#             */
/*   Updated: 2018/07/27 08:50:43 by slabiad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char		position(char p)
{
	int		o;
	char	c;

	if (p >= 'a' && p <= 'z')
	{
		o = p - 97 + 42;
	}
	if (p >= 'A' && p <= 'Z')
	{
		o = p - 65 + 42;
	}
	while (o > 26)
	{
		o %= 26;
	}
	if (p >= 'a' && p <= 'z')
	{
		c = o + 97;
	}
	if (p >= 'A' && p <= 'Z')
	{
		c = o + 65;
	}
	return (c);
}

char		decode(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (position(c));
	}
	if (c >= 'A' && c <= 'Z')
	{
		return (position(c));
	}
	else
	{
		return (c);
	}
}

char		*ft_rot42(char *str)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	while (str[i] != '\0')
	{
		str[i] = decode(str[i]);
		i++;
	}
	return (str);
}
