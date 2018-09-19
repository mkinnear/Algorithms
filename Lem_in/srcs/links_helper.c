/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:34:41 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/09 21:29:37 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"
#define COMP_OPTIONS (branch_a->links[i]->options_to < parent->options_to)

void	init_links(t_room **links, int size)
{
	int i;

	i = 0;
	while (i <= size)
	{
		links[i] = NULL;
		i++;
	}
}

void	sort_equal_nodes(t_room *parent, int index)
{
	int		i;
	t_room	*branch_a;
	t_room	*branch_b;

	branch_a = parent->links[index];
	branch_b = parent->links[index + 1];
	i = 0;
	if (branch_a->options_from > branch_b->options_from)
	{
		parent->links[index + 1] = branch_a;
		parent->links[index] = branch_b;
	}
	else if (branch_a->options_from == branch_a->options_from)
	{
		while (branch_a->links[i])
		{
			if (COMP_OPTIONS && branch_a->links[i]->cost == parent->cost)
			{
				parent->links[index + 1] = branch_a;
				parent->links[index] = branch_b;
				break ;
			}
			i++;
		}
	}
}

void	init_array(int *array, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		array[i] = -1;
		i++;
	}
}

int		contains_link(t_room *room, char *name)
{
	int i;

	i = 0;
	while (room->links[i])
	{
		if (ft_strcmp(room->links[i]->name, name) == 0)
			return (1);
		i++;
	}
	return (0);
}

int		count_links(char *name, char **map)
{
	int		count;
	int		i;
	char	**link;

	count = 0;
	link = NULL;
	i = 0;
	while (name && map[i])
	{
		if (get_type(map[i]) == LINK)
		{
			if ((ft_2dcount((link = ft_strsplit(map[i], '-')))))
			{
				if (ft_strcmp(name, link[0]) == 0)
					count++;
				else if (ft_strcmp(name, link[1]) == 0)
					count++;
			}
			ft_free2dsafe((void***)&link);
		}
		i++;
	}
	return (count);
}
