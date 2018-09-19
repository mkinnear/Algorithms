/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:29:28 by cramorok          #+#    #+#             */
/*   Updated: 2017/11/15 11:29:30 by cramorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_string	ft_strrchr(const t_string str, int ch)
{
	int		i;
	char	*new_s;

	i = (int)ft_strlen(str);
	new_s = NULL;
	if (ft_isascii(ch))
	{
		while (i >= 0)
		{
			if (str[i] == ch)
			{
				new_s = &str[i];
				break ;
			}
			i--;
		}
	}
	return (new_s);
}
