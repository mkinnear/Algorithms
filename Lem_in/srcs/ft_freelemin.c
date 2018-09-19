/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freelemin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:32:06 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/09 21:26:27 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void		ft_free2dsafee(void ***arr)
{
	int		i;
	void	**array;

	i = 0;
	array = *arr;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			array[i] = NULL;
			i++;
		}
		free(*arr);
		*arr = NULL;
	}
}

void		ft_freerooms(t_room **rooms)
{
	int i;

	i = 0;
	while (rooms[i])
	{
		free(rooms[i]->name);
		free(rooms[i]->links);
		free(rooms[i]->ants);
		rooms[i]->name = NULL;
		rooms[i]->links = NULL;
		rooms[i]->ants = NULL;
		free(rooms[i]);
		rooms[i] = NULL;
		i++;
	}
	free(rooms);
	rooms = NULL;
}

void		ft_freeants(t_ant ***all_ants)
{
	ft_free2dsafee((void***)all_ants);
	*all_ants = NULL;
}
