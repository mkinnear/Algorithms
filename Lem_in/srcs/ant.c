/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 21:25:59 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/09 21:26:01 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

t_ant	*create_ant(int id)
{
	t_ant *ant;

	if (!(ant = (t_ant*)malloc(sizeof(t_ant))))
		return (NULL);
	ant->id = id;
	ant->arrived = FALSE;
	return (ant);
}

t_ant	**get_ants(char **map)
{
	int		j;
	int		i;
	t_ant	**ants;

	ants = NULL;
	j = 0;
	if (!map && !map[0])
		return (NULL);
	else
		i = ft_atoi(map[j]);
	ants = (t_ant **)malloc(sizeof(t_ant*) * i + 1);
	ants[i--] = NULL;
	while (i > -1)
	{
		ants[i] = create_ant(i + 1);
		i--;
	}
	return (ants);
}

void	add_moved_ant(int *ants, int current_id, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (ants[i] == -1)
		{
			ants[i] = current_id;
			break ;
		}
		i++;
	}
}

int		is_empty(t_room *room)
{
	int i;

	i = 0;
	while (room->ants[i])
		i++;
	if (i == 0)
		return (1);
	return (0);
}
