/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:15:54 by cramorok          #+#    #+#             */
/*   Updated: 2017/11/15 11:15:56 by cramorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_space(int c)
{
	if ((c >= 7 && c <= 13) || c == 32)
		return (1);
	return (0);
}

t_string	*ft_split(t_string s)
{
	t_list	*letters;
	t_list	*words;
	int		i;
	int		count;

	if (s)
	{
		i = -1;
		letters = NULL;
		words = NULL;
		count = ft_strlen(s) - 1;
		while (++i <= count || letters)
		{
			if (is_space(s[i]) == 0 && i <= count)
				ft_lstadd_last_d(&letters, ft_strdup((s + i)), 1);
			else if (letters != NULL)
				ft_lstadd_last_d(&words, ft_lst_to_string(&letters), 1);
		}
		return (ft_lst_to_2dstring(&words));
	}
	return (NULL);
}
