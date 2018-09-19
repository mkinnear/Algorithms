/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:29:42 by cramorok          #+#    #+#             */
/*   Updated: 2017/11/15 11:29:45 by cramorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_string	*ft_strsplit(t_string s, char c)
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
			if (s[i] != c && i <= count)
				ft_lstadd_last_d(&letters, ft_strdup((s + i)), 1);
			else if (letters != NULL)
				ft_lstadd_last_d(&words, ft_lst_to_string(&letters), 1);
		}
		return (ft_lst_to_2dstring(&words));
	}
	return (NULL);
}
