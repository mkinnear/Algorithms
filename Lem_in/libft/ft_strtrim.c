/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:30:33 by cramorok          #+#    #+#             */
/*   Updated: 2017/11/15 11:30:34 by cramorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_lastindex(const char *s, int i)
{
	while (i > 0 && ft_isspace(s[i]))
		i--;
	return (i);
}

char		*ft_strtrim(char const *str)
{
	int		i[3];
	char	*new_str;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (str)
	{
		while (ft_isspace(str[i[0]]) && str[i[0]])
			(i[0])++;
		i[1] = ft_lastindex(str, ft_strlen(str) - 1);
		if (i[1] == 0)
			return (ft_strnew(0));
		if (!(new_str = ft_strnew((i[1] - i[0]) + 1)))
			return (NULL);
		while (i[0] <= i[1])
		{
			new_str[i[2]] = str[i[0]];
			(i[2])++;
			(i[0])++;
		}
		new_str[i[2]] = '\0';
		return (new_str);
	}
	return (NULL);
}
