/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weighing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:36:17 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/09 21:31:59 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void	set_link_cost(t_room *room, int *set)
{
	int i;

	i = 0;
	while (room->links[i])
	{
		if (room->links[i]->cost == -1)
		{
			room->links[i]->cost = room->cost + 1;
			*set = 1;
		}
		i++;
	}
}

int		set_cost(t_room *room, t_room **rooms)
{
	int			i;
	int			set;
	static int	layer = 0;

	i = 0;
	set = 0;
	if (room->cost > -1)
	{
		set_link_cost(room, &set);
		while (room->links[i] && set)
		{
			if (layer <= 0)
			{
				layer++;
				set_cost(room->links[i], rooms);
			}
			else
			{
				layer = 0;
				return (set);
			}
			i++;
		}
	}
	return (set);
}

void	set_rest_of_rooms(t_room **rooms)
{
	int set;
	int i;

	set = 0;
	i = 0;
	while (1)
	{
		if (!rooms[i] && !set)
			break ;
		else if (rooms[i] == NULL)
		{
			i = 0;
			set = 0;
		}
		else if (rooms[i]->cost != -1)
			set = set_cost(rooms[i], rooms);
		i++;
	}
}

void	set_all_costs(t_room **rooms)
{
	int i;

	i = 0;
	while (rooms[i] && rooms[i]->status != END)
		i++;
	if (rooms[i]->status == END)
	{
		rooms[i]->cost = 0;
		set_cost(rooms[i], rooms);
	}
	set_rest_of_rooms(rooms);
}
