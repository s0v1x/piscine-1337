/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabiad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 21:18:20 by slabiad           #+#    #+#             */
/*   Updated: 2018/07/25 22:34:02 by slabiad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int i;
	int r;

	i = 1;
	r = 1;
	if (nb <= 1)
	{
		return (0);
	}
	while (i <= (nb / 2))
	{
		if (nb % i == 0 && !(i == 1))
		{
			r = 0;
			break ;
		}
		i++;
	}
	return (r);
}

int	ft_find_next_prime(int nb)
{
	int i;

	i = nb;
	if (ft_is_prime(nb) == 1)
	{
		return (nb);
	}
	else
	{
		while (ft_is_prime(i) != 1)
		{
			i++;
		}
		return (i);
	}
}
