/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:30:18 by cramorok          #+#    #+#             */
/*   Updated: 2017/11/15 11:30:20 by cramorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	k;

	if (!s)
		return (NULL);
	substr = (t_string)malloc(sizeof(char) * (len + 1));
	i = start;
	k = 0;
	if (!substr)
		return (NULL);
	if (len)
	{
		while (i <= (start + len) - 1)
		{
			substr[k] = s[i];
			i++;
			k++;
		}
	}
	substr[k] = '\0';
	return (substr);
}
