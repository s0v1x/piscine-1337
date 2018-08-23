/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factoriel.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabiad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:21:03 by slabiad           #+#    #+#             */
/*   Updated: 2018/07/26 15:31:26 by slabiad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int fac;
	int i;

	i = 1;
	fac = 1;
	if (nb < 0 || nb > 12)
	{
		return (0);
	}
	else
	{
		while (i <= nb)
		{
			fac = fac * i;
			i++;
		}
	}
	return (fac);
}
