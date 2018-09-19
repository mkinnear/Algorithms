/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:23:22 by cramorok          #+#    #+#             */
/*   Updated: 2017/11/15 11:23:24 by cramorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(t_string dst, t_string src, size_t size)
{
	int i;
	int dst_len;
	int append_len;

	i = 0;
	dst_len = (int)ft_strlen(dst);
	append_len = (int)size - dst_len - 1;
	if ((int)size < dst_len)
		return (ft_strlen(src) + size);
	while (i < (append_len))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + (int)ft_strlen(src));
}
