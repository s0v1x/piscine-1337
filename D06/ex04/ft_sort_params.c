/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabiad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 18:30:52 by slabiad           #+#    #+#             */
/*   Updated: 2018/08/07 22:30:37 by slabiad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void				ft_putchar(char c);

int					ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if ((s1[i] == '\0' && s2[i] != '\0') || (s2[i] == '\0' && s1[i] != '\0'))
		return (s1[i] - s2[i]);
	return (0);
}

char				**ft_sort_params(int max, char **parms)
{
	int				i;
	int				j;
	char			*dt;

	i = 0;
	while (i < max)
	{
		j = i + 1;
		while (j < max)
		{
			if (ft_strcmp(parms[i], parms[j]) > 0)
			{
				dt = parms[i];
				parms[i] = parms[j];
				parms[j] = dt;
			}
			j++;
		}
		i++;
	}
	return (parms);
}

void				affich(int s, char **prm)
{
	int				i;
	int				j;
	char			**pr;

	i = 1;
	pr = ft_sort_params(s, prm);
	while (i < s)
	{
		j = 0;
		while (pr[i][j] != '\0')
		{
			ft_putchar(pr[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int					main(int argc, char **argv)
{
	affich(argc, argv);
	return (0);
}
