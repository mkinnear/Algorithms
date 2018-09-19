/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:06:51 by cramorok          #+#    #+#             */
/*   Updated: 2017/11/15 11:06:52 by cramorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int ch, size_t count)
{
	int	i;
	char*new_dest;

	new_dest = (t_string)dest;
	i = 0;
	while (i < (int)count)
	{
		new_dest[i] = ch;
		i++;
	}
	return (new_dest);
}
