/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:16:29 by cramorok          #+#    #+#             */
/*   Updated: 2017/11/15 11:16:32 by cramorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const t_string s, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
		return (&s[ft_strlen(s)]);
	if (ft_isascii(c))
	{
		while (s[i])
		{
			if (s[i] == c)
				return (&s[i]);
			i++;
		}
	}
	return (NULL);
}
