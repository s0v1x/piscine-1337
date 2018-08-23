/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabiad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 20:52:28 by slabiad           #+#    #+#             */
/*   Updated: 2018/08/05 21:05:29 by slabiad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/functions.h"

int			parenthese(char **str)
{
	int		nb;
	int		signe;

	nb = 0;
	signe = 1;
	if ((*str)[0] == '+' || (*str)[0] == '-')
	{
		if ((*str)[0] == '-')
			signe = -1;
		*str = *str + 1;
	}
	if ((*str)[0] == '(')
	{
		*str = *str + 1;
		nb = add_subs(str);
		if ((*str)[0] == ')')
			*str = *str + 1;
		return (signe * nb);
	}
	while ((*str)[0] >= '0' && (*str)[0] <= '9')
	{
		nb = (nb * 10) + (*str)[0] - '0';
		*str = *str + 1;
	}
	return (signe * nb);
}

int			mult_div_mod(char **str)
{
	int		nb1;
	int		nb2;
	char	opera;

	nb1 = parenthese(str);
	while ((*str)[0] == '*' || (*str)[0] == '/' || (*str)[0] == '%')
	{
		opera = (*str)[0];
		*str = *str + 1;
		nb2 = parenthese(str);
		nb1 = operation(nb1, nb2, opera);
	}
	return (nb1);
}

int			add_subs(char **str)
{
	int		nb1;
	int		nb2;
	char	opera;

	nb1 = parenthese(str);
	while ((*str)[0] != '\0' && (*str)[0] != ')')
	{
		opera = (*str)[0];
		*str = *str + 1;
		if (opera == '+' || opera == '-')
			nb2 = mult_div_mod(str);
		else
			nb2 = parenthese(str);
		nb1 = operation(nb1, nb2, opera);
	}
	return (nb1);
}

char		*delete_esp(char *str)
{
	int		i;
	int		j;
	char	*str2;

	i = 0;
	j = 0;
	str2 = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			str2[j] = str[i];
			j++;
		}
		i++;
	}
	str2[j] = '\0';
	return (str2);
}

int			eval_expr(char *str)
{
	str = delete_esp(str);
	if (str[0] == '\0')
		return (0);
	return (add_subs(&str));
}
