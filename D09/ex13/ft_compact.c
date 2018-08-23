/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabiad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 13:31:16 by slabiad           #+#    #+#             */
/*   Updated: 2018/07/27 14:52:49 by slabiad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		decaler(char **tab, int length, int i)
{
	int		j;
	char	*f;

	j = i;
	while (j < length)
	{
		f = tab[j];
		tab[j] = tab[j + 1];
		tab[j + 1] = f;
		j++;
	}
}

int			ft_compact(char **tab, int length)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	while (i < length)
	{
		if (tab[i] == "0" && i < length - 1)
		{
			nb++;
			decaler(tab, length, i);
		}
		i++;
	}
	return (length - nb);
}
