/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:33:59 by mkinnear          #+#    #+#             */
/*   Updated: 2017/12/09 21:27:35 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int		ft_return(int code, char ***values)
{
	ft_free2dsafe((void***)values);
	return (code);
}

int		get_type(char *line)
{
	int		i;
	int		j;
	char	**values;

	i = 0;
	j = 0;
	if (!(values = ft_split(line)))
		return (-1);
	if (values[0][0] == '#')
		return (ft_return(COMMENT, &values));
	else if (ft_2dcount(values) == 1 && ft_isalldigit(values[0]))
		return (ft_return(ANTCOUNT, &values));
	else if (ft_2dcount(values) == 1)
	{
		while (values[i][j] != '-')
			j++;
		if (values[i][j] == '-')
			return (ft_return(LINK, &values));
	}
	else if (ft_2dcount(values) == 3)
	{
		if (ft_isalldigit(values[1]) && ft_isalldigit(values[2]))
			return (ft_return(ROOM, &values));
	}
	return (ft_return(INVALID, &values));
}
