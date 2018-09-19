/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:22:57 by cramorok          #+#    #+#             */
/*   Updated: 2017/11/15 11:22:59 by cramorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinf(const t_string *str1, const t_string s2)
{
	char	*new;
	char	*s1;
	int		i[4];

	s1 = *str1;
	if (!s1 || !s2)
		return (NULL);
	i[1] = (int)ft_strlen(s1);
	i[2] = (int)ft_strlen(s2);
	i[3] = i[1] + i[2];
	i[0] = 0;
	new = (t_string)malloc(sizeof(char) * i[3] + 1);
	if (!new)
		return (NULL);
	while (i[0] <= i[3])
	{
		if (i[0] < i[1])
			new[i[0]] = s1[i[0]];
		else
			new[i[0]] = s2[i[0] - i[1]];
		i[0]++;
	}
	new[i[0]] = '\0';
	ft_strdel(&s1);
	return (new);
}
