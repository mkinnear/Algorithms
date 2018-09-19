/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_last_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramorok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:54:22 by cramorok          #+#    #+#             */
/*   Updated: 2017/11/15 10:54:24 by cramorok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_last_d(t_list **alst, void *content, size_t size)
{
	t_list	*current;
	t_list	*new_link;

	new_link = (t_list*)malloc(sizeof(t_list));
	if (new_link)
	{
		new_link->content = content;
		new_link->content_size = size;
		new_link->next = NULL;
	}
	current = *alst;
	if (*alst)
	{
		while (current->next)
			current = current->next;
		current->next = new_link;
	}
	else
		*alst = new_link;
}
