/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:35:41 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/09 21:30:42 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void	remove_ant(t_room *room, int index)
{
	int i;

	i = 0;
	while (room->ants[i])
	{
		if (i == index)
		{
			room->ants[index] = NULL;
			while (room->ants[i + 1])
			{
				room->ants[i] = room->ants[i + 1];
				i++;
			}
			room->ants[i] = NULL;
			i--;
		}
		i++;
	}
}

void	ft_putstep(char *roomname, int id)
{
	ft_putstr("L");
	ft_putnbr(id);
	ft_putstr("-");
	ft_putstr(roomname);
	ft_putchar(' ');
}

int		ant_to_room(t_ant *ant, t_room *room)
{
	int		i;

	i = 0;
	if (room->ants)
	{
		if (room->status == MID && room->ants[0] == NULL)
		{
			ft_putstep(room->name, ant->id);
			room->ants[0] = ant;
			room->ants[1] = NULL;
		}
		else if (room->status == START || room->status == END)
		{
			while (room->ants[i])
				i++;
			ft_putstep(room->name, ant->id);
			room->ants[i] = ant;
			i++;
			room->ants[i] = NULL;
		}
		return (1);
	}
	return (-1);
}

int		ant_moved(int *ants, int current_id, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (ants[i] == current_id)
			return (1);
		i++;
	}
	return (0);
}

int		ants_in_room(t_room *room)
{
	int i;

	i = 0;
	while (room->ants && room->ants[i])
	{
		i++;
	}
	return (i);
}
