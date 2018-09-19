/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:01:31 by cramorok          #+#    #+#             */
/*   Updated: 2017/11/15 11:01:33 by cramorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int	i;
	char*dest;
	char*source;

	i = 0;
	dest = (t_string)dst;
	source = (t_string)src;
	while (i < (int)n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}
