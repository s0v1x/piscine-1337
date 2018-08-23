/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabiad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 01:06:09 by slabiad           #+#    #+#             */
/*   Updated: 2018/07/23 01:13:08 by slabiad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb(void)
{
	int x;
	int y;
	int z;

	x = 0;
	while (x++ <= 7)
	{
		y = x;
		while (y++ <= 8)
		{
			z = y;
			while (z++ <= 9)
			{
				ft_putchar(x - 1 + 48);
				ft_putchar(y - 1 + 48);
				ft_putchar(z - 1 + 48);
				if (x - 1 != 7)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
		}
	}
}
