/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:29:10 by cramorok          #+#    #+#             */
/*   Updated: 2017/11/15 11:29:12 by cramorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	s_len;
	int		i;

	i = 0;
	s_len = ft_strlen(little);
	if (!*little)
		return (char *)(big);
	while (big[i] && len > 0)
	{
		if (big[i] == *little && len >= s_len)
		{
			if (ft_strncmp(big + i, little, s_len) == 0)
				return (char *)(big + i);
		}
		len--;
		i++;
	}
	return (NULL);
}
