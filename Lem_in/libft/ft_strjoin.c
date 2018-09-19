/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:22:48 by cramorok          #+#    #+#             */
/*   Updated: 2017/11/15 11:22:49 by cramorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_string		ft_strjoin(const t_string s1, const t_string s2)
{
	char	*new;
	int		i;
	int		s1_len;
	int		s2_len;
	int		new_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = (int)ft_strlen(s1);
	s2_len = (int)ft_strlen(s2);
	new_len = s1_len + s2_len;
	i = 0;
	new = (t_string)malloc(sizeof(char) * new_len + 1);
	if (!new)
		return (NULL);
	while (i <= new_len)
	{
		if (i < s1_len)
			new[i] = s1[i];
		else
			new[i] = s2[i - s1_len];
		i++;
	}
	new[i] = '\0';
	return (new);
}
