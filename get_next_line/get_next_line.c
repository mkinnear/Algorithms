/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 12:03:08 by mkinnear          #+#    #+#             */
/*   Updated: 2017/10/08 02:03:25 by mkinnear         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_cpy_contents(int const fd, char **holder)
{
	char	*buff;
	char	*temp;
	int		value;

	if (!(buff = (char *)malloc(sizeof(*buff) * (BUFF_SIZE + 1))))
		return (-1);
	value = read(fd, buff, BUFF_SIZE);
	if (value > 0)
	{
		buff[value] = '\0';
		temp = ft_strjoin(*holder, buff);
		free(*holder);
		*holder = temp;
	}
	free(buff);
	return (value);
}

int			get_next_line(const int fd, char **line)
{
	static char	*holder = NULL;
	char		*line_feed;
	int			value;

	if ((!holder && (holder = (char *)malloc(sizeof(*holder))) == NULL) ||
			!line || fd < 0 || BUFF_SIZE < 0)
		return (-1);
	line_feed = ft_strchr(holder, '\n');
	while (line_feed == '\0')
	{
		value = ft_cpy_contents(fd, &holder);
		if (value == 0)
		{
			if (ft_strlen(holder) == 0)
				return (0);
			holder = ft_strjoin(holder, "\n");
		}
		if (value < 0)
			return (-1);
		else
			line_feed = ft_strchr(holder, '\n');
	}
	*line = ft_strsub(holder, 0, ft_strlen(holder) - ft_strlen(line_feed));
	holder = ft_strdup(line_feed + 1);
	return (1);
}
