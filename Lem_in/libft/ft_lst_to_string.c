/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:53:13 by cramorok          #+#    #+#             */
/*   Updated: 2017/11/15 10:53:15 by cramorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_string	ft_lst_to_string(t_list **letters)
{
	int			i;
	t_string	new_str;
	t_list		*next;
	t_list		*current;

	i = 0;
	next = NULL;
	new_str = NULL;
	current = *letters;
	if (*letters)
	{
		new_str = ft_strnew(ft_lst_count(*letters));
		while (current)
		{
			new_str[i] = *((char *)(current)->content);
			next = (current)->next;
			current = next;
			i++;
		}
		new_str[i] = '\0';
		ft_lstdel(letters, ft_del);
		return (new_str);
	}
	return (NULL);
}
