/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabiad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 16:42:54 by slabiad           #+#    #+#             */
/*   Updated: 2018/07/27 08:47:29 by slabiad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_hour(int hour)
{
	return ((hour >= 12 && hour <= 23) ? " P.M." : " A.M.");
}

void	ft_takes_place(int hour)
{
	if (hour < 0 || hour > 23)
		return ;
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	printf("%d.00", ((hour % 12 == 0) ? 12 : (hour % 12)));
	printf("%s", ft_hour(hour));
	printf(" AND ");
	hour++;
	printf("%d.00", ((hour % 12 == 0) ? 12 : (hour % 12)));
	printf("%s", ft_hour(hour));
	printf("\n");
}
