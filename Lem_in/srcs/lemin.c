/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:34:11 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/09 21:28:29 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

t_room		*get_available_room(t_room *current)
{
	int i;

	i = 0;
	sort_links(current);
	while (current->links[i] && current->links[i]->cost < current->cost)
	{
		if (current->links[i]->status == END)
			return (current->links[i]);
		else if (current->links[i]->ants[0] == NULL)
			return (current->links[i]);
		i++;
	}
	return (NULL);
}

void		load_ants(t_ant **ants, t_room **rooms)
{
	int		i;
	int		j;
	int		antcount;

	i = 0;
	j = 0;
	antcount = ft_2dcount_gen((void**)ants);
	while (rooms[i])
	{
		melloc_ant_array(rooms[i], antcount);
		i++;
	}
	i = 0;
	while (rooms[i] && rooms[i]->status != START)
		i++;
	if (rooms[i]->status == START)
	{
		while (ants[j])
		{
			rooms[i]->ants[j] = ants[j];
			j++;
		}
	}
}

void		melloc_ant_array(t_room *room, int ant_count)
{
	if (room->status == END || room->status == START)
	{
		room->ants = (t_ant **)malloc(sizeof(t_ant*) * ant_count + 1);
		while (ant_count > -1)
		{
			room->ants[ant_count] = NULL;
			ant_count--;
		}
	}
	else
	{
		room->ants = (t_ant **)malloc(sizeof(t_ant*) * 2);
		room->ants[0] = NULL;
		room->ants[1] = NULL;
	}
}

void		lemin(char **map)
{
	t_room	**rooms;
	t_ant	**ants;
	int		antcount;

	if (ft_validation(map))
	{
		ft_init_ants_n_rooms(&rooms, &ants, map);
		antcount = ft_2dcount_gen((void**)ants);
		while (move_ants(rooms, antcount))
		{
			ft_putchar('\n');
		}
		ft_freeants(&ants);
		ft_freerooms(rooms);
	}
	else
		exit(0);
}

int			main(void)
{
	t_list	*lines;
	char	**map;
	char	*line;

	lines = NULL;
	while (get_next_line(0, &line))
	{
		ft_putendl(line);
		if (line)
			ft_lstadd_last_d(&lines, ft_strdup(line), ft_strlen(line));
		ft_strdel(&line);
	}
	ft_putchar('\n');
	map = ft_lst_to_2dstring(&lines);
	lemin(map);
	ft_free2dsafe((void***)&map);
	return (0);
}
