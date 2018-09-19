/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:35:31 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/09 21:30:11 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int		move_mid(t_room **rooms, int *i, int *movedants, int len)
{
	t_room *room;

	if ((room = get_available_room(rooms[*i])))
	{
		if (ant_moved(movedants, rooms[*i]->ants[0]->id, len) == 0)
		{
			ant_to_room(rooms[*i]->ants[0], room);
			add_moved_ant(movedants, rooms[*i]->ants[0]->id, len);
			rooms[*i]->ants[0] = NULL;
			*i = -1;
			return (1);
		}
	}
	return (0);
}

int		move_ants(t_room **rooms, int len)
{
	int		i;
	int		result;
	int		moved;
	int		movedants[len];

	movedants[len] = -1;
	moved = 0;
	init_array(movedants, len);
	i = 0;
	result = 0;
	while (rooms[i])
	{
		if (rooms[i]->status == MID && !is_empty(rooms[i]))
		{
			if ((result = move_mid(rooms, &i, movedants, len)))
				moved = result;
		}
		else if (rooms[i]->status == START)
			if ((result = move_from_start(rooms, &i, movedants, len)))
				moved = result;
		i++;
	}
	return (moved);
}

int		move_from_start(t_room **rooms, int *i, int *movedants, int len)
{
	t_room	*room;
	int		j;

	j = 0;
	while (rooms[*i]->ants[j])
	{
		if ((room = get_available_room(rooms[*i])))
		{
			if (ant_moved(movedants, rooms[*i]->ants[0]->id, len) == 0)
			{
				ant_to_room(rooms[*i]->ants[j], room);
				add_moved_ant(movedants, rooms[*i]->ants[0]->id, len);
				remove_ant(rooms[*i], j);
				*i = -1;
				return (1);
			}
		}
		j++;
	}
	return (0);
}

void	ft_init_ants_n_rooms(t_room ***rooms, t_ant ***ants, char **map)
{
	*rooms = get_rooms(map);
	sort_rooms(*rooms);
	set_links(*rooms, map);
	set_all_costs(*rooms);
	calculate_options(*rooms);
	*ants = get_ants(map);
	load_ants(*ants, *rooms);
}
