/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:25:11 by cramorok          #+#    #+#             */
/*   Updated: 2017/11/15 11:25:13 by cramorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_string	ft_strncat(t_string s1, const t_string s2, size_t n)
{
	size_t	i;
	size_t	s1_length;
	size_t	len;

	len = n;
	i = 0;
	s1_length = ft_strlen(s1);
	while (s2[i] && (i < len))
	{
		s1[s1_length + i] = s2[i];
		i++;
	}
	s1[s1_length + i] = '\0';
	return (s1);
}
