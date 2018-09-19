/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:25:38 by cramorok          #+#    #+#             */
/*   Updated: 2017/11/15 11:25:42 by cramorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_string	ft_strncpy(t_string dst, const t_string src, size_t n)
{
	size_t	i;
	size_t	src_length;

	i = 0;
	src_length = ft_strlen(src);
	while (i < n)
	{
		if (i < src_length)
			dst[i] = src[i];
		else
			dst[i] = '\0';
		i++;
	}
	return (dst);
}
