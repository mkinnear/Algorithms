/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_first_d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:53:49 by cramorok          #+#    #+#             */
/*   Updated: 2017/11/15 10:53:51 by cramorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_first_d(t_list **alst, void *content, size_t size)
{
	t_list		*new_link;

	new_link = (t_list*)malloc(sizeof(t_list));
	if (new_link)
	{
		new_link->content = content;
		new_link->content_size = size;
		new_link->next = NULL;
		if (*alst)
			new_link->next = *alst;
		*alst = new_link;
	}
}
