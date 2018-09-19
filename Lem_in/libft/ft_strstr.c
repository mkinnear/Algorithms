/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:30:05 by cramorok          #+#    #+#             */
/*   Updated: 2017/11/15 11:30:07 by cramorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *big, const char *little)
{
	int	len;

	len = ft_strlen(little);
	if (!*big && !*little)
		return ((char*)big);
	while (*big)
	{
		if (*big == *little || len == 0)
			if (ft_strncmp(big, little, len) == 0)
				return ((char *)big);
		big++;
	}
	return (NULL);
}
