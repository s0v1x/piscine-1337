/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabiad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 22:25:15 by slabiad           #+#    #+#             */
/*   Updated: 2018/07/29 22:27:14 by slabiad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	match(char *s1, char *s2)
{
	if (!*s1 && !*s2)
	{
		return (1);
	}
	else if (*s1 == '*' && *s2 == '*')
	{
		return (match(s1 + 1, s2));
	}
	else if (!*s1 && *s2 == '*')
	{
		return (match(s1, s2 + 1));
	}
	else if (*s1 != '*' && *s1 == *s2)
	{
		return (match(s1 + 1, s2 + 1));
	}
	else if (*s1 && *s2 && *s2 == '*')
	{
		return (match(s1, s2 + 1) || match(s1 + 1, s2));
	}
	else
	{
		return (0);
	}
}

int	nmatch(char *s1, char *s2)
{
	int		count;
	int		i;
	char	cmatch;

	cmatch = 0;
	count = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		if (match(s1 + i++, s2) != cmatch)
			cmatch = !cmatch;
		if (cmatch == 1)
			count++;
	}
	return (count);
}
