/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabiad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 03:57:11 by slabiad           #+#    #+#             */
/*   Updated: 2018/08/05 20:39:44 by slabiad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strcat(char *dest, char *src)
{
	int		i;
	int		length;

	i = 0;
	length = 0;
	while (dest[length])
		length++;
	dest[length] = '\n';
	length++;
	while (src[i])
	{
		dest[length] = src[i];
		length++;
		i++;
	}
	dest[length] = '\0';
	return (dest);
}

char		*ft_concat_params(int argc, char **argv)
{
	char	*res;
	int		i;

	i = 2;
	res = (char*)malloc(sizeof(char) * argc);
	if (argc > 1)
	{
		res = argv[1];
		while (i < argc)
		{
			ft_strcat(res, argv[i]);
			i++;
		}
		i = 0;
		while (res[i])
			i++;
	}
	res[i] = '\0';
	return (res);
}
