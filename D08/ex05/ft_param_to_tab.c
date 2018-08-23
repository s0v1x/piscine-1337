/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabiad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 23:29:01 by slabiad           #+#    #+#             */
/*   Updated: 2018/08/07 23:34:14 by slabiad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_par.h"

char				*ft_strdup(char *src)
{
	int				i;
	int				src_length;
	char			*tmp;

	i = 0;
	src_length = 0;
	while (src[src_length])
		src_length++;
	tmp = (char*)malloc(sizeof(*tmp) * (src_length));
	if (tmp == NULL)
		return (NULL);
	while (i < src_length)
	{
		tmp[i] = src[i];
		i++;
	}
	tmp[src_length] = '\0';
	return (tmp);
}

int					ft_strlen(char *str)
{
	int				i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

t_stock_par			*ft_param_to_tab(int ac, char **av)
{
	int				i;
	t_stock_par		*param;

	if (!(param = (t_stock_par*)malloc(sizeof(t_stock_par) * (ac + 1))))
		return (0);
	i = 0;
	while (i < ac)
	{
		param[i].size_param = ft_strlen(av[i]);
		param[i].str = av[i];
		param[i].copy = ft_strdup(av[i]);
		param[i].tab = ft_split_whitespaces(av[i]);
		++i;
	}
	param[i].str = 0;
	return (param);
}
