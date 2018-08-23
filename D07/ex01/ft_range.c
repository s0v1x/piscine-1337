/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabiad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 17:32:29 by slabiad           #+#    #+#             */
/*   Updated: 2018/08/04 17:47:39 by slabiad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *res;
	int i;
	int l;

	i = 0;
	if (min >= max)
		return (0);
	l = max - min;
	res = malloc(sizeof(int) * l);
	while (i < l)
	{
		res[i] = min + i;
		i++;
	}
	return (res);
}
