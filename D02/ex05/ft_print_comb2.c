/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabiad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 01:15:41 by slabiad           #+#    #+#             */
/*   Updated: 2018/07/23 01:26:37 by slabiad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = -1;
	while (a++ < 98)
	{
		b = a;
		while (b++ < 99)
		{
			if (a != b)
			{
				ft_putchar((a / 10) + 48);
				ft_putchar((a % 10) + 48);
				ft_putchar(' ');
				ft_putchar((b / 10) + 48);
				ft_putchar((b % 10) + 48);
				if (!(a == 98 && b == 99))
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
		}
	}
}
