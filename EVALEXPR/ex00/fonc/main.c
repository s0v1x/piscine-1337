/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabiad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:15:19 by slabiad           #+#    #+#             */
/*   Updated: 2018/08/05 21:16:18 by slabiad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_putnbr(eval_expr(argv[1]));
		ft_putchar('\n');
	}
	return (0);
}