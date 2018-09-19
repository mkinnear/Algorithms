/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weighing2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:36:29 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/09 21:32:25 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void	calculate_links_to(t_room **rooms)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (rooms[i])
	{
		while (rooms[i]->links[j])
		{
			if (rooms[i]->links[j]->cost < rooms[i]->cost)
				rooms[i]->options_to++;
			j++;
		}
		j = 0;
		i++;
	}
}

void	calculate_options(t_room **rooms)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (rooms[i])
	{
		while (rooms[i]->links[j])
		{
			if (rooms[i]->links[j]->cost > rooms[i]->cost)
				rooms[i]->options_from++;
			j++;
		}
		j = 0;
		i++;
	}
	calculate_links_to(rooms);
}

void	sort_swap(t_room *room, int *i, int *flag)
{
	t_room *temp;

	temp = room->links[*i];
	room->links[*i] = room->links[*i + 1];
	room->links[*i + 1] = temp;
	*flag = 1;
	(*i)--;
}

void	sort_links(t_room *room)
{
	int		i;
	int		flag;
	t_room	*neighbour;
	t_room	*neighbour2;

	flag = 1;
	i = 0;
	while (flag)
	{
		flag = 0;
		while (room->links[i + 1])
		{
			neighbour = room->links[i];
			neighbour2 = room->links[i + 1];
			if (neighbour->cost > neighbour2->cost)
				sort_swap(room, &i, &flag);
			else if (neighbour->cost < room->cost)
				if (neighbour->cost == neighbour2->cost)
					sort_equal_nodes(room, i);
			i++;
		}
		i = 0;
	}
}
