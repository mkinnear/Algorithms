/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:34:30 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/09 21:29:02 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"
#define NO_OF_LINKS (count_links(room->name, map))

char	**get_link(char *line)
{
	char	**array;
	char	**values;

	array = (char **)malloc(sizeof(char *) * 3);
	if ((values = ft_strsplit(line, '-')))
	{
		array[0] = ft_strdup(values[0]);
		array[1] = ft_strdup(values[1]);
		array[2] = NULL;
	}
	ft_free2dsafe((void***)&values);
	return (array);
}

void	set_link(t_room *room, t_room **rooms, char **map)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	room->links = NULL;
	room->links = (t_room **)malloc(sizeof(t_room*) * NO_OF_LINKS + 1);
	init_links(room->links, count_links(room->name, map));
	while (map[j])
	{
		if (get_type(map[j]) == LINK)
			ft_setlink_helper(map[j], rooms, room, &i);
		j++;
	}
	room->links[i] = NULL;
}

void	ft_setlink_helper(char *line, t_room **rooms, t_room *room, int *i)
{
	char	**values;
	int		index;

	if (ft_2dcount((values = ft_strsplit(line, '-'))))
	{
		if (values && values[0] && ft_strcmp(room->name, values[0]) == 0)
		{
			if ((index = index_of_room(rooms, values[1])) > -1)
			{
				if (contains_link(room, rooms[index]->name) == 0)
				{
					room->links[(*i)++] = rooms[index];
				}
			}
		}
		else if (values && values[1] && ft_strcmp(room->name, values[1]) == 0)
		{
			if ((index = index_of_room(rooms, values[0])) > -1)
				if (contains_link(room, rooms[index]->name) == 0)
					room->links[(*i)++] = rooms[index];
		}
		ft_free2dsafe((void***)&values);
	}
}

void	set_links(t_room **rooms, char **map)
{
	int i;

	i = 0;
	while (rooms[i])
	{
		set_link(rooms[i], rooms, map);
		i++;
	}
}
