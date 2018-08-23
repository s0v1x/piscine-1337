/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabiad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 20:48:39 by slabiad           #+#    #+#             */
/*   Updated: 2018/08/05 20:51:00 by slabiad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		operation(int n1, int n2, char op)
{
	if (op == '+')
		return (n1 + n2);
	else if (op == '-')
		return (n1 - n2);
	else if (op == '/')
		return (n1 / n2);
	else if (op == '*')
		return (n1 * n2);
	else if (op == '%')
		return (n1 % n2);
	return (0);
}
