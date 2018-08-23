/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabiad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 20:46:31 by slabiad           #+#    #+#             */
/*   Updated: 2018/08/05 20:47:54 by slabiad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

char	*delete_esp(char *str);
int		parenthese(char **str);
int		add_subs(char **str);
int		mult_div_mod(char **str);
int		eval_expr (char *str);
int		operation(int n1, int n2, char op);
void	ft_putchar (char c);
int		ft_strlen (char *str);
void	ft_putnbr(int nb);

#endif
