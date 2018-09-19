/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:56:23 by cramorok          #+#    #+#             */
/*   Updated: 2017/11/15 10:56:30 by cramorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char*dest;
	char*source;
	int i;

	dest = (t_string)dst;
	source = (t_string)src;
	i = 0;
	while (i < (int)n)
	{
		dest[i] = source[i];
		if (dest[i] == c)
			return (&dest[i + 1]);
		i++;
	}
	return (NULL);
}
