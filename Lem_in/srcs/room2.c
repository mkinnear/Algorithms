/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:36:03 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/09 21:31:30 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

t_room	**get_rooms(char **map)
{
	t_room	**rooms;

	if (!(rooms = (t_room**)malloc(sizeof(t_room*) * room_count(map) + 1)))
		return (NULL);
	ft_read_in_rooms(rooms, map);
	return (rooms);
}

void	ft_read_in_rooms(t_room **rooms, char **map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[j])
	{
		if (get_type(map[j]) == ROOM)
		{
			rooms[i++] = create_room(map[j]);
			if (ft_strcmp(map[j - 1], "##start") == 0 && i && j)
				rooms[i - 1]->status = START;
			else if (ft_strcmp(map[j - 1], "##end") == 0 && i && j)
				rooms[i - 1]->status = END;
			else
				rooms[i - 1]->status = MID;
		}
		j++;
	}
	rooms[i] = NULL;
}
