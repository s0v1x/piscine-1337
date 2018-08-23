/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slabiad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 13:37:48 by slabiad           #+#    #+#             */
/*   Updated: 2018/07/27 15:37:20 by slabiad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef	int ft_bool;
#define TRUE 1
#define FALSE 0
#define OPEN 1
#define CLOSE 0
#define EXIT_SUCCESS 0

typedef	struct	s_door
{
	int state;
}				t_door;
ft_bool is_door_close(t_door *door);
ft_bool is_door_open(t_door *door);
ft_bool close_door(t_door *door);
ft_bool open_door(t_door *door);
