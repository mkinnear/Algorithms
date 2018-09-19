/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:33:45 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/09 21:27:00 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

#define FILE_NOT_FOUND -1
#define NO_MANDATORY_COMMENT -2
#define NO_POSSIBLE_SOLUTION -3
#define NO_ROOMS -5
#define NO_ANTS -6

int			ft_erros(int code)
{
	if (code == FILE_NOT_FOUND)
		ft_putendl("File not found\n");
	else if (code == NO_MANDATORY_COMMENT)
		ft_putendl("START or END comment not found\n");
	else if (code == NO_POSSIBLE_SOLUTION)
		ft_putendl("No solution found\n");
	else if (code == NO_ROOMS)
		ft_putendl("No rooms found\n");
	else if (code == NO_ANTS)
		ft_putendl("No ants found\n");
	return (0);
}

int			ft_comments_check(char **map)
{
	int		i;
	int		start;
	int		end;

	start = 0;
	end = 0;
	i = 0;
	while (map[i])
	{
		if (ft_strcmp(map[i], "##start") == 0)
			start = 1;
		else if (ft_strcmp(map[i], "##end") == 0)
			end = 1;
		i++;
	}
	if (start && end)
		return (1);
	else
		return (ft_erros(NO_MANDATORY_COMMENT));
}

int			ft_rooms_check(char **map)
{
	char	**values;
	int		i;
	int		rooms;

	rooms = 0;
	i = 0;
	while (map[i])
	{
		if ((values = ft_strsplit(map[i], ' ')))
		{
			if ((ft_2dcount(values)) == 3)
				if (ft_isalldigit(values[1]) && ft_isalldigit(values[2]))
					rooms++;
			ft_free2dsafe((void***)&values);
		}
		i++;
	}
	if (rooms == 0)
		return (ft_erros(NO_ROOMS));
	else if (rooms == 1)
		return (ft_erros(NO_POSSIBLE_SOLUTION));
	else
		return (1);
}

int			ft_ants_check(char **map)
{
	char	**values;
	int		i;

	i = 0;
	if (map && map[i])
	{
		if ((values = ft_strsplit(map[i], ' ')))
		{
			if (ft_2dcount(values) == 1)
			{
				if (ft_isalldigit(values[0]))
				{
					ft_free2dsafe((void***)&values);
					return (1);
				}
			}
			ft_free2dsafe((void***)&values);
		}
		i++;
	}
	return (ft_erros(NO_ANTS));
}

int			ft_validation(char **map)
{
	if (!ft_comments_check(map))
		return (0);
	if (!ft_rooms_check(map))
		return (0);
	if (!ft_ants_check(map))
		return (0);
	return (1);
}
